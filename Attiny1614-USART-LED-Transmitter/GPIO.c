/*
 * GPIO.c
 *
 * Created: 2025-01-19 14:57:12
 *  Author: Saulius
 */ 
 #include "Settings.h"

void GPIO_init(){
	// Configure Port B (PB) for USART0 TX 
	PORTB.DIRSET = PIN2_bm  ; // Set PB2 as output
	PORTA.PIN7CTRL = PORT_ISC_INPUT_DISABLE_gc;  // turn off digital input buffer for PA7 ADC MT6701 input
}