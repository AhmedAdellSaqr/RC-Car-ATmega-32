/*
 * ULTRASONIC.h
 *
 * Created: 1/18/2024 10:50:53 PM
 *  Author: HP
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_



#define  F_CPU      8000000
#include "util/delay.h"
#include "Timers.h"
#include "DIO_Interface.h"

typedef enum{
	ULTRASONIC_1=PIND0,
	ULTRASONIC_2=PIND1,
	ULTRASONIC_3=PIND2,
	ULTRASONIC_4=PIND3
}ULTRASONIC_type;

void ULTRASONIC_Init(void);

void ULTRASONIC_GetDistance(u8* Pdistance,ULTRASONIC_type ultrasonic_pin);

void ULTRASONIC_Start(ULTRASONIC_type ultrasonic_pin);

u8 ULTRASONIC_GetDistanceNoBlock(u8*Pdistance);




/*
void ULTRASONIC_Init(void);

void ULTRASONIC_GetDistance(u16* distance,ULTRASONIC_type pin);

void ULTRASONIC_Trigger(ULTRASONIC_type pin);

u8 ULTRASONIC_GetDistancePeriodicCheck(u16* distance);
*/



#endif /* ULTRASONIC_H_ */