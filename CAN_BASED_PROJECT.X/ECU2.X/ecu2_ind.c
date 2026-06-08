/*
 * File:   ecu2_ind.c
 * Author: girid
 *
 * Created on 29 May, 2026, 9:50 AM
 */


#include "ecu2_ind.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "digital_keypad.h"
static IndicatorStatus status = e_ind_off;

IndicatorStatus process_indicator()
{
    unsigned char key = read_digital_keypad(STATE_CHANGE);

    if(key == SWITCH1)
        status = e_ind_left;

    else if(key == SWITCH2)
        status = e_ind_off;

    else if(key == SWITCH3)
        status = e_ind_right;

    return status;
}