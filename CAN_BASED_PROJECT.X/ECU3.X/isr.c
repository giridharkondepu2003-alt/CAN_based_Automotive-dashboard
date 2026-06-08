/*
 * File:   isr.c
 * Author: girid
 *
 * Created on 28 May, 2026, 11:40 PM
 */


#include <xc.h>
#include "timers.h"
extern volatile uint8_t led_flag;

void __interrupt() isr(void)
{
    static unsigned int delay=0;
    if(TMR0IF)
    {
        TMR0 = TMR0 + 8;
        if(delay++ == 20000)
        {
            led_flag= !led_flag;
            delay=0;
        }
        TMR0IF = 0;
    }
}