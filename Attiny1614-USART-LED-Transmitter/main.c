/**
 * @file Attiny1614-USART-LED-Transmitter.c
 * @brief A simple program to transmit ADC readings over USART using an ATTiny1614.
 * 
 * This program initializes GPIO, clock, USART, and ADC peripherals on an ATTiny1614 microcontroller. 
 * It reads data from the ADC (e.g., for an MT6701 sensor) and transmits the readings via USART.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#include "Settings.h"

/**
 * @brief The main entry point of the program.
 * 
 * The function initializes the GPIO, clock, USART, and ADC peripherals. 
 * It continuously reads data from the ADC and sends the result via USART. 
 * Each transmitted ADC reading is enclosed in square brackets and terminated with a newline character.
 * The newline character serves as a package separator for MSO5072 decoding.
 * 
 * @return This function does not return any value as it contains an infinite loop.
 */
int main(void)
{
    GPIO_init(); ///< Initialize GPIO pins.
    CLOCK_INHF_clock_init(); ///< Initialize the internal 20 MHz clock.
    USART0_init(); ///< Initialize USART0 for transmission only.
    ADC0_init(); ///< Initialize ADC0 for reading the MT6701 sensor.

    while (1) 
    {
        /**
         * @brief Transmit ADC reading over USART.
         * 
         * The ADC reading is formatted as a 4-digit zero-padded unsigned integer 
         * enclosed in square brackets, followed by a newline character ('\n'). 
         * The newline is used by the MSO5072 oscilloscope for packet separation.
         */
        USART_printf("[%04u]\n", ADC0_read());
    }
}
