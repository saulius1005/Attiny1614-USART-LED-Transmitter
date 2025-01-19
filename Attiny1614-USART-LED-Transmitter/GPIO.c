/**
 * @file GPIO.c
 * @brief GPIO configuration for ATTiny1614 peripherals.
 * 
 * This file contains the implementation of GPIO initialization, 
 * setting up ports for USART transmission and ADC input.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#include "Settings.h"

/**
 * @brief Initialize GPIO pins.
 * 
 * This function configures the GPIO pins needed for USART0 transmission and ADC input:
 * - PB2 is set as an output for the USART0 TX line.
 * - PA7 has its digital input buffer disabled to prepare it for analog input (e.g., MT6701 sensor).
 */
void GPIO_init() {
    PORTB.DIRSET = PIN2_bm; ///< Configure PB2 as output for USART0 TX.
    PORTA.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc; ///< Disable the digital input buffer for PA7 (ADC input).
}
