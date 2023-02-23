/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*  Standard C Included Files */
#include <stdio.h>
#include <string.h>
#include "pin_mux.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_i2c.h"
#include "clock_config.h"
#include "peripherals.h"
#include "fsl_power.h"
#include "fsl_common.h"
#include "fsl_lpadc.h"
#include "LPC5526.h"
#include "fsl_device_registers.h"
#include "fsl_spi_cmsis.h"
#include "fsl_gpio.h"
#include "ad9102.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_I2C_SLAVE_BASE    (I2C1_BASE)
#define EXAMPLE_I2C_SLAVE ((I2C_Type *)EXAMPLE_I2C_SLAVE_BASE)
#define I2C_DATA_LENGTH            (32) /* MAX is 256 */
#define ADDR_LENGTH (13)
#define DRIVER_MASTER_SPI Driver_SPI0
#define DEMO_LPADC_BASE (ADC0)

/* Board pins */
#define LPC_LED_R_PORT BOARD_INITPINS_LPC_LED_R_PORT
#define LPC_LED_R_PIN  BOARD_INITPINS_LPC_LED_R_PIN

#define LPC_LED_G_PORT BOARD_INITPINS_LPC_LED_G_PORT
#define LPC_LED_G_PIN  BOARD_INITPINS_LPC_LED_G_PIN

#define LPC_LED_B_PORT BOARD_INITPINS_LPC_LED_B_PORT
#define LPC_LED_B_PIN  BOARD_INITPINS_LPC_LED_B_PIN

#define LPC_ST_2_PORT BOARD_INITPINS_LPC_ST_2_PORT
#define LPC_ST_2_PIN  BOARD_INITPINS_LPC_ST_2_PIN

#define LPC_ST_1_PORT BOARD_INITPINS_LPC_ST_1_PORT
#define LPC_ST_1_PIN  BOARD_INITPINS_LPC_ST_1_PIN

#define Trigger_PORT  BOARD_INITPINS_Trigger_PORT
#define Trigger_PIN   BOARD_INITPINS_Trigger_PIN

enum Addr{NOP, Addr, Frequency, Trigger, LEDR, LEDG, RGBr, RGBg, RGBb, ADCT1H, ADCT1L, ADCT2H, ADCT2L};
enum Buffer{Address, ReceivedData, AddressReceived};
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* SPI user SignalEvent */
void SPI_MasterSignalEvent_t(uint32_t event);

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile bool isTransferCompleted = false;
volatile bool isMasterOnTransmit  = false;
volatile bool isMasterOnReceive   = false;
volatile uint32_t g_systickCounter;
uint8_t g_slave_buff[I2C_DATA_LENGTH];
i2c_slave_handle_t g_s_handle;
volatile bool g_SlaveCompletionFlag = false;
uint8_t Addr_Holder[ADDR_LENGTH];

/*******************************************************************************
 * Code
 ******************************************************************************/
void SysTick_Handler(void)
{
    if (g_systickCounter != 0U)
    {
        g_systickCounter--;
    }
}

void SysTick_DelayTicks(uint32_t n)
{
    g_systickCounter = n;
    while (g_systickCounter != 0U)
    {
    }
}

void wait_us(uint32_t us)
{
	/* Set systick reload value to generate 1ms interrupt */
	if (SysTick_Config(SystemCoreClock / 1000U))
	{
		while (1)
		{
		}
	}
	SysTick_DelayTicks(us);
}

void SPI_MasterSignalEvent_t(uint32_t event)
{
    if (true == isMasterOnReceive)
    {
        isMasterOnReceive = false;
    }
    if (true == isMasterOnTransmit)
    {
        isMasterOnTransmit = false;
    }
    isTransferCompleted = true;
}

/* FLEXCOMM0 signal event callback function */
void SPI0_SignalEvent(uint32_t event) {
  /* Data Transfer completed */
  if (event & ARM_SPI_EVENT_TRANSFER_COMPLETE) {
    /* Place your code here */
  }
  /* Data lost: Receive overflow / Transmit underflow */
  if (event & ARM_SPI_EVENT_DATA_LOST) {
    /* Place your code here */
  }
}


static void i2c_slave_callback(I2C_Type *base, volatile i2c_slave_transfer_t *xfer, void *userData)
{
	int addr_reg = Addr_Holder[Addr];
    switch (xfer->event)
    {
        /*  Address match event */
        case kI2C_SlaveAddressMatchEvent:
            xfer->rxData = NULL;
            xfer->rxSize = 0;
            break;
        /*  Transmit request */
        case kI2C_SlaveTransmitEvent:
            /*  Update information for transmit process */
            xfer->txData = &Addr_Holder[addr_reg];
            if (addr_reg>=ADCT1H){
            	xfer->txSize = 2;
            }
            else{
            	xfer->txSize = 1;
            }

            break;

        /* Setup the slave receive buffer */
        case kI2C_SlaveReceiveEvent:
            /*  Update information for received process */
			xfer->rxData = &g_slave_buff[0];
			xfer->rxSize = I2C_DATA_LENGTH;
            break;

        /* The master has sent a stop transition on the bus */
        case kI2C_SlaveDeselectedEvent:
            g_SlaveCompletionFlag = true;
            break;

        default:
            g_SlaveCompletionFlag = false;
            break;

    }
}
void Enable_DDS(void){

    /* set default DDS output frequency */
    double f;
    f = 5;		//MHz

    /* Calculate tuning word (tw) from frequency input */
    int tw = (int) (f*1.15/180*16777216);
    uint16_t reg_3e = ((tw >> 8) & 0xFFFF);
    uint16_t reg_3f = ((tw & 0xFF) << 8);

    /* turn on TRIGGER pin (stop signal) */
    GPIO_PortSet(GPIO, Trigger_PORT, 1<<Trigger_PIN);

    /* Reset registers */
    spi_write(0x0000, 0x2004);

    /* Write all registers to initiate a sinusoidal waveform */
    update_regs();

    /* Set DDS tuning word (TW) freq=DDS_TW × f_CLK/2^(24)
       0x003e:MSB, 0x003f:LSB
       0xFFFF max, 0xFF00 max, (24 bit in total) 0x003F[7:0] are reserved
    */
    spi_write(0x003e, reg_3e);
    spi_write(0x003f, reg_3f);

    /* Update all SPI settings with a new configuration (self-clearing) */
    spi_write(0x001e, 0x0001);

    /* RUN: Allows the pattern generation, and stop pattern after trigger. */
    spi_write(0x001d, 0x0001);

    /* turn off TRIGGER pin (start signal) */
    GPIO_PortClear(GPIO, Trigger_PORT, 1<<Trigger_PIN);
}

/*!
 * @brief Main function
 */
int main(void)
{
    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    /* reset FLEXCOMM0 for SPI */
    RESET_PeripheralReset(kFC0_RST_SHIFT_RSTn);
    /* reset FLEXCOMM1 for I2C */
    RESET_PeripheralReset(kFC1_RST_SHIFT_RSTn);
    /* attach 12 MHz clock to FLEXCOMM0 (SPI0 master) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);
    /* initialize pins, clocks, peripherals, debug console and GPIO */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitPeripherals();
    BOARD_InitDebugConsole();
    GPIO_PortInit(GPIO, 0);

    /* pin init */
    /* Define a digital output pin configuration */
    static const gpio_pin_config_t configOutput =
    {
     kGPIO_DigitalOutput,  	/* use as output pin */
     0,  					/* initial value */
    };
    GPIO_PinInit(GPIO, LPC_LED_R_PORT, LPC_LED_R_PIN, &configOutput);
    GPIO_PinInit(GPIO, LPC_LED_G_PORT, LPC_LED_G_PIN, &configOutput);
    GPIO_PinInit(GPIO, LPC_LED_B_PORT, LPC_LED_B_PIN, &configOutput);
    GPIO_PinInit(GPIO, LPC_ST_2_PORT, LPC_ST_2_PIN, &configOutput);
    GPIO_PinInit(GPIO, LPC_ST_1_PORT, LPC_ST_1_PIN, &configOutput);
    GPIO_PinInit(GPIO, Trigger_PORT, Trigger_PIN, &configOutput);

    /* Set up i2c slave */
    i2c_slave_config_t slaveConfig;
    status_t reVal = kStatus_Fail;
    I2C_SlaveGetDefaultConfig(&slaveConfig);
    /* Create the I2C handle for the non-blocking transfer */
    I2C_SlaveTransferCreateHandle(EXAMPLE_I2C_SLAVE, &g_s_handle, i2c_slave_callback, NULL);
    /* Start accepting I2C transfers on the I2C slave peripheral */
    reVal = I2C_SlaveTransferNonBlocking(EXAMPLE_I2C_SLAVE, &g_s_handle,
                                         kI2C_SlaveAddressMatchEvent | kI2C_SlaveCompletionEvent
										 | kI2C_SlaveDeselectedEvent);
    if (reVal != kStatus_Success)
    {
        return -1;
    }

    /* SPI master init */
    DRIVER_MASTER_SPI.Initialize(SPI_MasterSignalEvent_t);
    DRIVER_MASTER_SPI.PowerControl(ARM_POWER_FULL);
    DRIVER_MASTER_SPI.Control(ARM_SPI_MODE_MASTER, TRANSFER_BAUDRATE);

    /* Set up ADC */
	POWER_DisablePD(kPDRUNCFG_PD_LDOGPADC); //Power up ADC
    lpadc_config_t lpadcConfigStruct;
    lpadc_conv_result_t lpadcResultStruct;
    /* Initialize the LPADC module */
    LPADC_GetDefaultConfig(&lpadcConfigStruct);

    /* Turn on DDS */
    Enable_DDS();

    int ADCT1;
    int curr_addr;
    uint8_t Addr_Holder_Previous[ADDR_LENGTH];
    while(1){

        /* Start a new ADC conversion */
        LPADC_DoSoftwareTrigger(DEMO_LPADC_BASE, 1U);
        /* Get the ADC result */
        LPADC_GetConvResult(DEMO_LPADC_BASE, &lpadcResultStruct, 0U);
        ADCT1 = lpadcResultStruct.convValue;
        /* Store result in Address handler
           Converting this value to temperature can be done using the following formula:
           T = 3.3/65535.0/0.0032 * ADCT - 1.06/0.0032 + 25
        */
        Addr_Holder[ADCT1H] = ADCT1 >> 8 & 0xFF;
        Addr_Holder[ADCT1L] = ADCT1 & 0xFF;

        Addr_Holder[ADCT2H] = ADCT1 >> 8 & 0xFF;
        Addr_Holder[ADCT2L] = ADCT1 & 0xFF;
        //PRINTF("CompFlag = %d\n", g_SlaveCompletionFlag);
        /* I2C Logic */
        if (g_SlaveCompletionFlag && (g_slave_buff[0] || g_slave_buff[1]))
        {
        	Addr_Holder[Addr] = g_slave_buff[Address];
        	curr_addr = Addr_Holder[Addr];
        	if (g_slave_buff[ReceivedData] & 0x1 && curr_addr!=NOP && curr_addr!=Addr)
        	{
        		Addr_Holder[curr_addr] = g_slave_buff[ReceivedData]>>1&0xFF;
        	}
			memset(g_slave_buff, 0, I2C_DATA_LENGTH);
			g_SlaveCompletionFlag = false;
        }




//        if (g_slave_buff[4] != IOrgbR && g_slave_buff[4]==1){
//        	GPIO_PortSet(GPIO, LPC_ST_1_PORT, 1<<LPC_ST_1_PIN);
//        	IOrgbR = 1;
//        }else if (g_slave_buff[4] != IOrgbR && g_slave_buff[4]==0){
//        	GPIO_PortClear(GPIO, LPC_ST_1_PORT, 1<<LPC_ST_1_PIN);
//        	IOrgbR = 0;
//        }
//        if (g_slave_buff[5] != IOrgbG && g_slave_buff[5]==1){
//        	GPIO_PortSet(GPIO, LPC_ST_2_PORT, 1<<LPC_ST_2_PIN);
//        	IOrgbR = 1;
//        }else if (g_slave_buff[5] != IOrgbR && g_slave_buff[5]==0){
//        	GPIO_PortClear(GPIO, LPC_ST_2_PORT, 1<<LPC_ST_2_PIN);
//        	IOrgbR = 0;
//        }
        }

    }
}
