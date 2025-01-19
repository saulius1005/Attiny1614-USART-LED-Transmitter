/**
 * @file Settings.h
 * @brief Header file for configuring and initializing peripherals on the ATTiny1614.
 * 
 * This file contains macro definitions, library includes, and function declarations 
 * for GPIO, clock, ADC, and USART functionalities used in the project.
 * 
 * @author Saulius
 * @date 2025-01-19
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

/** @brief CPU frequency in Hz. */
#define F_CPU 20000000

/**
 * @brief Macro to calculate the baud rate setting for USART0.
 * 
 * @param BAUD_RATE The desired baud rate.
 * @return The value to be written to the USART0 baud register.
 */
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (8 * (float)BAUD_RATE)) + 0.5)

#include <avr/io.h>
#include <stdio.h>       /**< Include standard I/O library for functions like printf. */
#include <string.h>      /**< Include string library for handling string functions like strlen. */
#include <util/delay.h>  /**< Include delay utilities for timing functions. */
#include <avr/cpufunc.h> /**< Include AVR-specific functions like ccp_write_io. */

/** @brief Initializes GPIO pins. */
void GPIO_init();

/** @brief Initializes the internal high-frequency clock. */
void CLOCK_INHF_clock_init();

/** @brief Initializes the ADC peripheral. */
void ADC0_init();

/**
 * @brief Reads a value from the ADC.
 * 
 * @return A 16-bit value representing the ADC conversion result.
 */
uint16_t ADC0_read();

/** @brief Initializes USART0 as a transmitter. */
void USART0_init();

/**
 * @brief Sends formatted output over USART0.
 * 
 * @param format A printf-style format string.
 * @param ... Arguments corresponding to the format string.
 */
void USART_printf(const char *format, ...);

#endif /* SETTINGS_H_ */
