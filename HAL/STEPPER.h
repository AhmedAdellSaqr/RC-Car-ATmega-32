/*
 * STEPPER.h
 *
 * Created: 1/18/2024 10:06:52 PM
 *  Author: HP
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_

#define  F_CPU      8000000
#include "util/delay.h"
#include "DIO_Interface.h"

/********************** PIN CONFIG ***************************/
/**********BiPolar***********/
#define  BI_COIL1A           PIND0
#define  BI_COIL1B           PIND1
#define  BI_COIL2A           PIND2
#define  BI_COIL2B           PIND3
#define  BI_DELAY            500
/**********UniPolar**********/
#define  UNI_COIL1A          PIND4
#define  UNI_COIL1B          PIND5
#define  UNI_COIL2A          PIND6
#define  UNI_COIL2B          PIND7
#define  UNI_DELAY           50

#define  STEP_SIZE           10
/*************************************************************/

void Stepper_BiPolar_CW(void);

void Stepper_BiPolar_CCW(void);

void Stepper_BiPolar_HS_CW(void);

void Stepper_BiPolar_HS_CCW(void);

void Stepper_UniPolar_CW(void);

void Stepper_UniPolar_CCW(void);

void Stepper_UniPolar_HS_CW(void);

void Stepper_UniPolar_HS_CCW(void);

void Stepper_UniPolar_Steps_CW(u16 step);

void Stepper_UniPolar_Angle_CW(u16 angle);




#endif /* STEPPER_H_ */