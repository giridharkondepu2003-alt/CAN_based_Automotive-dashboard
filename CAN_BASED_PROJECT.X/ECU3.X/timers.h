/* 
 * File:   timers.h
 * Author: girid
 *
 * Created on 28 May, 2026, 11:09 PM
 */

#ifndef TIMER0_H
#define TIMER0_H

typedef enum {
    e_ind_off,
    e_ind_left,
    e_ind_right
} IndicatorStatus;

void init_timer0(void);
void init_leds();

#endif

