/*
 * File:   main.c
 * Author: girid
 *
 * Created on 22 May, 2026, 5:56 PM
 */


#include <xc.h>
#include"adc.h"
#include"clcd.h"
#include"matrix.h"
#include"can.h"
#include"msg_id.h"

void main(void) {
    
    init_adc();
    init_clcd();
    init_matrix_keypad();
    init_can();
    
    int gear=0;
    char event[9][3]={"ON","GN","G1","G2","G3","G4","G5","GR","C_"};
    char speed[3];
    
    uint16_t speed_data[3];
    uint16_t gear_data[3];
    uint16_t speed_len=0;
    uint16_t gear_len=0;
    uint16_t speed_id;
    uint16_t gear_id;
    
    
    while(1)
    {
        unsigned int adc_speed = read_adc(CHANNEL4);
        adc_speed = adc_speed/10.33;
        speed[1]=(adc_speed/10)+'0';
        speed[0]=(adc_speed%10)+'0';
        speed[2]='\0';
        
        can_transmit(SPEED_MSG_ID,speed,2);

        __delay_ms(100);
        
//        can_receive(&speed_id,speed_data,&speed_len);
//        speed_data[speed_len]='\0';
        
        uint16_t key = read_switches(STATE_CHANGE);
        if(key==1)
        {
            if(gear<7)
                gear++;
            else if(gear==8)
                gear=1;
        }
        else if(key == 2)
        {
            if(gear>1 && gear!=8)
                gear--;
            else if(gear==8)
                gear=1;
        }
        else if(key == 3)
        {
            gear=8;
        }
        
        can_transmit(GEAR_MSG_ID,event[gear],2);
        __delay_ms(100);
        
//        can_receive(&gear_id,gear_data,&gear_len);
//        gear_data[gear_len]='\0';
        
        
        
//        clcd_print("SPEED",LINE1(1));
//        clcd_print("GEAR",LINE1(10));
//        
//        clcd_print(speed,LINE2(2));
//        clcd_print(event[gear],LINE2(11));
//        
//        clcd_print("SPEED",LINE1(1));
//        clcd_print("GEAR",LINE1(10));
//        
//        clcd_print(speed_data,LINE2(2));
//        clcd_print(gear_data,LINE2(11));
    }
}
