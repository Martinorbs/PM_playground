/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_22_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_22_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_23_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 5. */
#define PIO0_23_FUNC_ALT5 0x05u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_25_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_25_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_28_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO0_28_FUNC_ALT1 0x01u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_29_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO0_29_FUNC_ALT1 0x01u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_2_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_2_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_30_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 1. */
#define PIO0_30_FUNC_ALT1 0x01u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_31_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_31_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_7_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_7_FUNC_ALT0 0x00u
/*!
 * @brief Select Digital mode.: Enable Digital mode. Digital input is enabled. */
#define PIO0_8_DIGIMODE_DIGITAL 0x01u
/*!
 * @brief Selects pin function.: Alternative connection 0. */
#define PIO0_8_FUNC_ALT0 0x00u

/*! @name PIO0_22 (number 50), LPC_LED_R
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LPC_LED_R_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LPC_LED_R_GPIO_PIN_MASK (1U << 22U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_LPC_LED_R_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LPC_LED_R_PIN 22U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LPC_LED_R_PIN_MASK (1U << 22U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*! @name PIO0_25 (number 51), LPC_LED_G
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LPC_LED_G_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LPC_LED_G_GPIO_PIN_MASK (1U << 25U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_LPC_LED_G_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LPC_LED_G_PIN 25U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LPC_LED_G_PIN_MASK (1U << 25U)      /*!<@brief PORT pin mask */
                                                           /* @} */

/*! @name PIO0_2 (number 52), LPC_LED_B
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LPC_LED_B_GPIO GPIO                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LPC_LED_B_GPIO_PIN_MASK (1U << 2U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_LPC_LED_B_PORT 0U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LPC_LED_B_PIN 2U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LPC_LED_B_PIN_MASK (1U << 2U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO0_31 (number 15), LPC_ST_2
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LPC_ST_2_GPIO GPIO                 /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LPC_ST_2_GPIO_PIN_MASK (1U << 31U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_LPC_ST_2_PORT 0U                   /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LPC_ST_2_PIN 31U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LPC_ST_2_PIN_MASK (1U << 31U)      /*!<@brief PORT pin mask */
                                                          /* @} */

/*! @name PIO0_8 (number 17), LPC_ST_1
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_LPC_ST_1_GPIO GPIO                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_LPC_ST_1_GPIO_PIN_MASK (1U << 8U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_LPC_ST_1_PORT 0U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_LPC_ST_1_PIN 8U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_LPC_ST_1_PIN_MASK (1U << 8U)      /*!<@brief PORT pin mask */
                                                         /* @} */

/*! @name PIO0_7 (number 1), Trigger
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_Trigger_GPIO GPIO                /*!<@brief GPIO peripheral base pointer */
#define BOARD_INITPINS_Trigger_GPIO_PIN_MASK (1U << 7U) /*!<@brief GPIO pin mask */
#define BOARD_INITPINS_Trigger_PORT 0U                  /*!<@brief PORT peripheral base pointer */
#define BOARD_INITPINS_Trigger_PIN 7U                   /*!<@brief PORT pin number */
#define BOARD_INITPINS_Trigger_PIN_MASK (1U << 7U)      /*!<@brief PORT pin mask */
                                                        /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void); /* Function assigned for the Cortex-M33 (Core #0) */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
