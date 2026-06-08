/*
 * File:   ssd.c
 * Author: girid
 *
 * Created on 25 May, 2026, 8:49 AM
 */


#include <xc.h>
#include"ssd.h"

void init_ssd()
{
    TRISD = 0x00;
    TRISA = TRISA & 0xF0;
    PORTD = 0x00;
    PORTA = PORTA & 0xF0;
}

void ssd_display(unsigned char *ssd)
{
    for(int i = 0; i < 4; i++)
    {
        PORTD = ssd[i];
        PORTA = (PORTA & 0xF0) | (1 << i);
        for(int wait = 1000; wait--;);
    }
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
