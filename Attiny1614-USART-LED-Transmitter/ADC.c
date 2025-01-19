/**
 * @file ADC.c
 * @brief ADC configuration and operation for the ATTiny1614.
 * 
 * This file contains the implementation of functions to initialize the ADC 
 * and read values from it. The ADC is configured for 10-bit resolution, 
 * averaging 64 measurements in free-running mode.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#include "Settings.h"

/**
 * @brief Initializes the ADC peripheral.
 * 
 * Configures the ADC on the ATTiny1614 to:
 * - Use 64-sample accumulation for better accuracy.
 * - Operate at 10-bit resolution.
 * - Use the VDD as the reference voltage.
 * - Run in free-running mode for continuous sampling.
 * - Set PA7 (AIN7) as the ADC input channel.
 * - Start the ADC conversion.
 */
void ADC0_init() {
    ADC0.CTRLB = ADC_SAMPNUM_ACC64_gc; ///< Configure ADC to accumulate 64 measurements.
    ADC0.CTRLC = ADC_PRESC_DIV16_gc | ADC_REFSEL_VDDREF_gc; ///< Set ADC clock prescaler and reference voltage to VDD.
    ADC0.CTRLA = ADC_ENABLE_bm | ADC_RESSEL_10BIT_gc | ADC_FREERUN_bm; ///< Enable ADC, set 10-bit resolution, and start free-running mode.
    ADC0.MUXPOS = ADC_MUXPOS_AIN7_gc; ///< Set PA7 (AIN7) as the ADC input.
    ADC0.COMMAND = ADC_STCONV_bm; ///< Start ADC conversion.
}

/**
 * @brief Reads the averaged ADC value.
 * 
 * Retrieves the result of the ADC conversion, which is the average of 64 measurements. 
 * The returned value is adjusted to reflect a 10-bit resolution.
 * 
 * @return uint16_t The averaged ADC result (10-bit value).
 */
uint16_t ADC0_read() {
    return ADC0.RES >> 6; ///< Return the average ADC value by dividing the 16-bit result by 64.
}
