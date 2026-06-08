/*
 * File:   main.c
 * Author: girid
 *
 * Created on 28 May, 2026, 9:40 PM
 */

#include <xc.h>
#include <string.h>

#include "can.h"
#include "clcd.h"
#include "msg_id.h"
#include "timers.h"

volatile uint8_t led_flag = 0;
uint8_t indicator_status = 0;
    
void main(void)
{
    init_clcd();
    init_timer0();
    init_can();
    init_leds();
    
    PEIE = 1;
    GIE = 1;

    uint16_t msg_id;
    uint8_t rece_data[8];
    uint8_t rece_len;
    char buf[4];

    while(1)
    {
        can_receive(&msg_id, rece_data, &rece_len);

        if(rece_len == 0)
            continue;
        /* make received data a string */
        rece_data[rece_len] = '\0';

        if(msg_id == SPEED_MSG_ID)
        {
            clcd_print(rece_data,LINE2(0));
        }

        else if(msg_id == GEAR_MSG_ID)
        {
            clcd_print(rece_data,LINE2(3));
        }

        else if(msg_id == RPM_MSG_ID)
        {
            clcd_print(rece_data,LINE2(7));
        }

        else if(msg_id == INDICATOR_MSG_ID)
        {
           if(rece_data[1])
                indicator_status = 0;     // OFF
           else if(rece_data[0])
                indicator_status = 1;     // LEFT
           else if(rece_data[2])
                indicator_status = 2;     // RIGHT
        }

        clcd_print("SP",  LINE1(0));
        clcd_print("GR",  LINE1(3));
        clcd_print("RPM", LINE1(7));
        clcd_print("IND", LINE1(13));

        switch(indicator_status)
        {
            case 0:     // OFF
                LEFT_IND_OFF();
                RIGHT_IND_OFF();
                clcd_print("  ", LINE2(13));
                break;

            case 1:     // LEFT
                RIGHT_IND_OFF();

                if(led_flag)
                {
                    LEFT_IND_ON();
                    clcd_print("<-", LINE2(13));
                }
                else
                {
                    LEFT_IND_OFF();
                    clcd_print("  ", LINE2(13));
                }
                break;

            case 2:     // RIGHT
                LEFT_IND_OFF();

                if(led_flag)
                {
                    RIGHT_IND_ON();
                    clcd_print("->", LINE2(13));
                }
                else
                {
                    RIGHT_IND_OFF();
                    clcd_print("  ", LINE2(13));
                }
                break;
        }
        
    }
}