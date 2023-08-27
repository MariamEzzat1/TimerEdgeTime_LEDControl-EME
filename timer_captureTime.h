
#ifndef TIMER_CAPTURETIME_H_
#define TIMER_CAPTURETIME_H_
#include "DIO.h"

#define TIMER2              2
#define TAEN_bit            0
#define TAEVENT_bit1        2
#define TAEVENT_bit2        3

void wtimer2Handler(void);
void wtimer2_Init(void);
uint32 seconds_to_ticks(uint8 seconds_num);


#endif /* TIMER_CAPTURETIME_H_ */
