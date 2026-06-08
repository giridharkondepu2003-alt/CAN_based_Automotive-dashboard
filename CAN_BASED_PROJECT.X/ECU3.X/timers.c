/*
 * File:   timers.c
 * Author: girid
 *
 * Created on 28 May, 2026, 11:09 PM
 */


#include <xc.h>
#include "timers.h"

void init_timer0(void) {
    /*
     * Setting instruction cycle clock (Fosc / 4) as the source of
     * timer0
     */

    /*Setting 8 bit timer register*/
    T08BIT = 1;

    /* Selecting internal clock source */
    T0CS = 0;

    /* Enabling timer0*/
    TMR0ON = 1;

    /* disabling prescaler*/
    PSA = 1;

    TMR0 = 6;

    /* Clearing timer0 overflow interrupt flag bit */
    TMR0IF = 0;

    /* Enabling timer0 overflow interrupt */
    TMR0IE = 1;
    
}

void init_leds(void)
{
    TRISB0=0;
    TRISB1=0;
    TRISB6=0;
    TRISB7=0;
    RB0=0;
    RB1=0;
    RB6=0;
    RB7=0;
}
