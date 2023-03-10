/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "fsl_spi_cmsis.h"
#include "fsl_lpadc.h"
#include "fsl_i2c.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* Definition of peripheral ID */
#define FLEXCOMM0_PERIPHERAL Driver_SPI0
/* Definition of the clock source frequency */
#define FLEXCOMM0_CLOCK_SOURCE_FREQ 12000000UL
/* Alias for ADC0 peripheral */
#define ADC0_PERIPHERAL ADC0
/* BOARD_InitPeripherals defines for FLEXCOMM1 */
/* Definition of peripheral ID */
#define FLEXCOMM1_PERIPHERAL ((I2C_Type *)FLEXCOMM1)
/* Definition of the clock source frequency */
#define FLEXCOMM1_CLOCK_SOURCE 12000000UL
/* FLEXCOMM1 interrupt vector ID (number). */
#define FLEXCOMM1_FLEXCOMM_IRQN FLEXCOMM1_IRQn
/* FLEXCOMM1 interrupt handler identifier. */
#define FLEXCOMM1_FLEXCOMM_IRQHANDLER FLEXCOMM1_IRQHandler

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const lpadc_config_t ADC0_config;
extern lpadc_conv_command_config_t ADC0_commandsConfig[1];
extern lpadc_conv_trigger_config_t ADC0_triggersConfig[1];
extern const i2c_slave_config_t FLEXCOMM1_config;

/***********************************************************************************************************************
 * Global functions
 **********************************************************************************************************************/
/* Signal event function for component FLEXCOMM0*/
extern void SPI0_SignalEvent(uint32_t event);
/* Get clock source frequency function for component FLEXCOMM0 */
uint32_t SPI0_GetFreq(void);

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
