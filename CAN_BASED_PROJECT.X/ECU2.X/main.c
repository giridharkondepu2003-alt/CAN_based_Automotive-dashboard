/*
 * File:   main.c
 * Author: girid
 *
 * Created on 25 May, 2026, 8:49 AM
 */


#include <xc.h>
#include"adc.h"
#include"digital_keypad.h"
#include"ssd.h"
#include"can.h"
#include "msg_id.h"
#include"clcd.h"
#include"ecu2_ind.h"

void main(void) {
    
    
    init_adc();
    init_leds();
    init_digital_keypad();
    init_clcd();
    init_can();
    
    unsigned char digit[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
    unsigned char ssd[5];
    unsigned int delay=0;
    uint8_t led[3]={0,0,0};
    int ind=0;
    
    
    uint16_t rpm_id;
    uint16_t ind_id;
    uint8_t ind_data[2];
    uint8_t rpm_data[5];
    uint8_t ind_len=0;
    uint8_t rpm_len=0;
    
    while(1)
    {
        unsigned int rpm_value = read_adc(CHANNEL4);
        int count = rpm_value*5.86;
        ssd[0] = (count/1000)+'0';
        ssd[1] = (count/100)%10+'0';
        ssd[2] = (count/10)%10+'0';
        ssd[3] = (count % 10)+'0';
        ssd[4]='\0';
        
        can_transmit(RPM_MSG_ID,ssd,4);
        
        __delay_ms(100);
        
//        can_receive(&rpm_id,rpm_data,&rpm_len);
//        rpm_data[rpm_len]='\0';
//        
//        clcd_print("RPM",LINE1(2));
//        clcd_print(rpm_data,LINE2(2));
//        
        
        uint8_t key=process_indicator(); 
        if(key == e_ind_left){
        led[0]=1;
        led[1]=0;
        led[2]=0;
                

        }
        else if(key == e_ind_right){
             
        led[0]=0;
        led[1]=0;
        led[2]=1;
                

        }
        else if(key == e_ind_off){
             
        led[0]=0;
        led[1]=1;
        led[2]=0;
        }
        
       can_transmit(INDICATOR_MSG_ID,led,3);
       
       __delay_ms(100);
       
       // can_receive(&ind_id,ind_data,&ind_len);

//        if(delay++ == 10)
//        {
//        
//            if(ind_data[0]==e_ind_right)
//            {
//                RB0 = 0;
//                RB1=0;
//                RB6=!RB6;
//                RB7=!RB7;
//            }
//            else if(ind_data[0]==e_ind_left)
//            {
//                RB0 = !RB0;
//                RB1=!RB1;
//                RB6=0;
//                RB7=0;
//            }
//            else if(ind_data[0]==e_ind_off)
//            {
//                RB0=0;
//                RB1=0;
//                RB6=0;
//                RB7=0;
//            }
//            delay=0;
//        }
        
      }
    
}
