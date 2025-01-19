/*
 * Attiny1614-USART-LED-Transmitter.c
 *
 * Created: 2025-01-19 14:56:52
 * Author : Saulius
 */ 

#include "Settings.h"

int main(void)
{
	GPIO_init();
	CLOCK_INHF_clock_init();
	USART0_init();
	ADC0_init();
    while (1) 
    {
		USART_printf("[%04u]\n", ADC0_read());// \n is for MSO5072 decoder as package separator
    }
}

