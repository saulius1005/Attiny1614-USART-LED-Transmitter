/*
 * ADC.c
 *
 * Created: 2025-01-19 15:48:12
 *  Author: Saulius
 */ 

 #include "Settings.h"

void ADC0_init(){
	ADC0.CTRLB = ADC_SAMPNUM_ACC64_gc; //64 measurements
	ADC0.CTRLC = ADC_PRESC_DIV16_gc | ADC_REFSEL_VDDREF_gc; //20mhz/16 adc speed
	ADC0.CTRLA = ADC_ENABLE_bm | ADC_RESSEL_10BIT_gc | ADC_FREERUN_bm; //adc enable with 10bit resolution and starting free runing
	ADC0.MUXPOS  = ADC_MUXPOS_AIN7_gc; //PA7 as ADC input
	ADC0.COMMAND = ADC_STCONV_bm; //start conversion
}

uint16_t ADC0_read(){
	//while(!(ADC0.INTFLAGS & ADC_RESRDY_bm)); //wait unti we get result
	//ADC0.INTFLAGS = ADC_RESRDY_bm; //clear result ready flag
	return ADC0.RES>>6; //return average ADC value of 64 measurements
}