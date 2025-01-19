/*
 * Settings.h
 *
 * Created: 2025-01-19 14:59:29
 *  Author: Saulius
 */ 


#ifndef SETTINGS_H_
#define SETTINGS_H_

#define F_CPU 20000000
#define USART0_BAUD_RATE(BAUD_RATE) ((float)(F_CPU * 64 / (8 *(float)BAUD_RATE)) + 0.5)

#include <avr/io.h>
#include <stdio.h>       /**< Include standard I/O library for functions like printf */
#include <string.h>      /**< Include string library for handling string functions like strlen */
#include <util/delay.h>
#include <avr/cpufunc.h>

/** @brief Initializes GPIO pins. */
void GPIO_init();
/** @brief Initializes the internal high-frequency clock. */
void CLOCK_INHF_clock_init();

void ADC0_init();

uint16_t ADC0_read();

void USART0_init();
void USART_printf(const char *format, ...);

#endif /* SETTINGS_H_ */