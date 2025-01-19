/*
 * CLK.c
 *
 * Created: 2025-01-19 14:58:51
 *  Author: Saulius
 */ 
 #include "Settings.h"
 /**
 * @brief Initializes the internal high-frequency oscillator (OSCHF).
 * 
 * @details Configures the internal oscillator with a frequency of 24 MHz. 
 *          Optionally enables clock output on pin PA7. A prescaler can be configured if needed.
 */
void CLOCK_INHF_clock_init() {
    /* Enable internal oscillator with a frequency of 24 MHz */
    ccp_write_io((uint8_t *) &CLKCTRL.MCLKCTRLA, CLKCTRL_CLKSEL_OSC20M_gc/*| CLKCTRL_CLKOUT_bm*/); // for so14 impossible to enable clkout- no actual pin

    /* Set main clock prescaler is turned off */
     ccp_write_io((uint8_t *) &CLKCTRL.MCLKCTRLB, CLKCTRL_PDIV_2X_gc  & ~CLKCTRL_PEN_bm);

    /* Wait for oscillator change to complete */
    while (CLKCTRL.MCLKSTATUS & CLKCTRL_SOSC_bm) {};
}