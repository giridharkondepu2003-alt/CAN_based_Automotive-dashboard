/* 
 * File:   ssd.h
 * Author: girid
 *
 * Created on 25 May, 2026, 8:46 AM
 */

#ifndef SSD_H
#define	SSD_H

void init_ssd(void);
void ssd_display(unsigned char *ssd);
void init_leds(void);

#define ZERO 0xE7
#define ONE 0x21
#define TWO 0xCB
#define THREE 0x6B
#define FOUR 0x2D
#define FIVE 0x6E
#define SIX 0xEE
#define SEVEN 0x23
#define EIGHT 0xEF
#define NINE 0x6F



#endif	/* SSD_H */

