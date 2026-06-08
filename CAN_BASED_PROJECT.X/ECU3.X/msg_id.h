/* 
 * File:   msg_id.h
 * Author: girid
 *
 * Created on 28 May, 2026, 9:37 PM
 */

#ifndef MSG_ID_H
#define	MSG_ID_H
#include <stdint.h>

#define LED_OFF 0
#define LED_ON 1

#define RIGHT_IND_ON() (PORTB = PORTB | 0xC0)
#define RIGHT_IND_OFF() (PORTB = PORTB & ~0xC0)
#define LEFT_IND_ON() (PORTB = PORTB | 0x03)
#define LEFT_IND_OFF() (PORTB = PORTB & ~0x03)


#define SPEED_MSG_ID 0x10
#define GEAR_MSG_ID 0x20
#define RPM_MSG_ID 0x30
#define ENG_TEMP_MSG_ID 0x40
#define INDICATOR_MSG_ID 0x50


#endif	/* MSG_ID_H */

