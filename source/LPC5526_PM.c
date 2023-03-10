/**
 * @file    LPC5526_PM.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC5526.h"
#include "fsl_debug_console.h"

#include "fsl_device_registers.h"
#include "fsl_spi_cmsis.h"
#include "fsl_power.h"
#include "fsl_gpio.h"

#include "ad9102.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DRIVER_MASTER_SPI Driver_SPI0

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

int main(void) {

    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);

    /* attach 12 MHz clock to FLEXCOMM9 (SPI9 master) */
    CLOCK_AttachClk(kFRO12M_to_FLEXCOMM0);

    /* reset FLEXCOMM for SPI */
    RESET_PeripheralReset(kFC0_RST_SHIFT_RSTn);

    /* init */
    BOARD_BootClockPLL150M();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();
    SystemCoreClockUpdate();
    GPIO_PortInit(GPIO, 0);

    /* pin init */
    /*Define a digital output pin configuration,*/
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

    /*SPI master init*/
    DRIVER_MASTER_SPI.Initialize(SPI_MasterSignalEvent_t);
    DRIVER_MASTER_SPI.PowerControl(ARM_POWER_FULL);
    DRIVER_MASTER_SPI.Control(ARM_SPI_MODE_MASTER, TRANSFER_BAUDRATE);

    /* set DDS output frequency */
	double f;
	f = 5;		//MHz

	isTransferCompleted = false;

	// Calculate tuning word (tw) from frequency input
	int tw = (int) (f*1.15/180*16777216);
	uint16_t reg_3e = ((tw >> 8) & 0xFFFF);
	uint16_t reg_3f = ((tw & 0xFF) << 8);
	GPIO_PortSet(GPIO, Trigger_PORT, 1<<Trigger_PIN); /* turn on */;
	// Reset registers
	spi_write(0x0000, 0x2004);
	wait_us(10);

	// Write all registers to initiate a sinusoidal waveform
	update_regs();

	// Set DDS tuning word (TW) freq=DDS_TW ?? f_CLK/2^(24)
	// 0x003e:MSB, 0x003f:LSB
	// 0xFFFF max, 0xFF00 max, (24 bit in total) 0x003F[7:0] are reserved
	spi_write(0x003e, reg_3e);
	spi_write(0x003f, reg_3f);

	//Update all SPI settings with a new configuration (self-clearing)
	spi_write(0x001e, 0x0001);
	//RUN: Allows the pattern generation, and stop pattern after trigger.
	spi_write(0x001d, 0x0001);
	wait_us(10);
	GPIO_PortClear(GPIO, Trigger_PORT, 1<<Trigger_PIN); /* turn off (start signal)*/

	while (1)
	{
		//set pin to 1
		GPIO_PortSet(GPIO, LPC_LED_R_PORT, 1<<LPC_LED_R_PIN); /* turn on */
		GPIO_PortClear(GPIO, LPC_LED_G_PORT, 1<<LPC_LED_G_PIN); /* turn on */
		GPIO_PortClear(GPIO, LPC_LED_B_PORT, 1<<LPC_LED_B_PIN); /* turn on */
		GPIO_PortClear(GPIO, LPC_ST_2_PORT, 1<<LPC_ST_2_PIN); /* turn off */
		GPIO_PortSet(GPIO, LPC_ST_1_PORT, 1<<LPC_ST_1_PIN); /* turn on */

		// Wait until transfer completed
		wait_us(1000);

		// Set trigger pin to 1
		GPIO_PortClear(GPIO, LPC_LED_R_PORT, 1<<LPC_LED_R_PIN); /* turn off */
		GPIO_PortSet(GPIO, LPC_LED_G_PORT, 1<<LPC_LED_G_PIN); /* turn off */
		GPIO_PortSet(GPIO, LPC_LED_B_PORT, 1<<LPC_LED_B_PIN); /* turn off */
		GPIO_PortSet(GPIO, LPC_ST_2_PORT, 1<<LPC_ST_2_PIN); /* turn on */
		GPIO_PortClear(GPIO, LPC_ST_1_PORT, 1<<LPC_ST_1_PIN); /* turn off */



		// Wait until transfer completed
		wait_us(1000);

//		while (!isTransferCompleted)
//		{
//		}
 	 }

}

