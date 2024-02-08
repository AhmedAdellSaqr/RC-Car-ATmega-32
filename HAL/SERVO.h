/*
 * SERVO.h
 *
 * Created: 1/18/2024 10:47:10 PM
 *  Author: HP
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#define  F_CPU      8000000
#include "util/delay.h"
#include "DIO_Interface.h"
#include "Timers.h"


#define On_Proteus          1
#define On_Kit              2
/*********** Select Between Proutes / kit *********/
#define program          On_Proteus
/**************************************************/


#define SERVO_FREQ          19999

#define OCRA                1
#define OCRB                2
#define OCRA_OCRB           3
/**************************** Timer Selection *************************/
/* TIMER0  / TIMER2 */
#define  TIMER                          TIMER0
/* TIMER1A_ICR_TOP_OC  / TIMER1B_OCRA_TOP_OC */
#define  TIMER1_OCR_MODE                TIMER1A_ICR_TOP_OC

//if You Select TIMER1A_ICR_TOP Mode
/********Select Channels OF Timer1*********/
/* OCRA / OCRB / OCRA_OCRB */
#define CHANNEL_SELECT                  OCRA

//if You Select Channel OCRA_OCRB
/* OCRB_NON_INVERTING / OCRB_INVERTING */
#define TIMER1_OCRB_MODE                OCRB_NON_INVERTING
/**************************** Scaler Config ***************************/
/* Timer 0 / 2 */
/* TIMER0_STOP / TIMER0_SCALER_1 / TIMER0_SCALER_8 / TIMER0_SCALER_64 / TIMER0_SCALER_256 / TIMER0_SCALER_1024 */
/* TIMER2_STOP / TIMER2_SCALER_1 / TIMER2_SCALER_8 / TIMER2_SCALER_64 / TIMER2_SCALER_256 / TIMER2_SCALER_1024 */
#define TIMER0SCALER                    TIMER0_SCALER_8
#define TIMER2SCALER                    TIMER2_SCALER_8
/* Timer 1 */
/* TIMER1_STOP / TIMER1_SCALER_1 / TIMER1_SCALER_8 / TIMER1_SCALER_64 / TIMER1_SCALER_256 / TIMER1_SCALER_1024 */
#define TIMER1A_ICR_TOP_SCALER          TIMER1_SCALER_8
#define TIMER1B_OCRA_TOP_SCALER         TIMER1_SCALER_8
/**********************************************************************/
/***************************** OCR Config *****************************/
/* Timer 0 / 2 */
#define TIMER0OC                        OC0_DISCONNECTED
#define TIMER2OC                        OC2_DISCONNECTED
/* Timer 1 */
/* OCRA_NON_INVERTING / OCRA_INVERTING */
/* OCRB_NON_INVERTING / OCRB_INVERTING */
#define TIMER1A_ICR_TOP_OC              OCRA_NON_INVERTING
#define TIMER1B_OCRA_TOP_OC             OCRB_NON_INVERTING
/**********************************************************************/
typedef enum{
	TIMER0,
	TIMER2
}TimerMode_type;

typedef enum{
	TIMER1A_ICR_TOP,
	TIMER1B_OCRA_TOP
}Timer1OCMode_type;

#if program == On_Proteus
typedef enum{
	Position_180=72,
	Position_135,
	Position_90,
	Position_45,
	Position_0
}TimerPosition_type;

#elif program == On_Kit
typedef enum{
	Position_155=70,
	Position_135,
	Position_115,
	Position_90,
	Position_65,
	Position_45,
	Position_15,
	Position_0,
}TimerPosition_type;
#endif

typedef enum{
	Position1_0  = 0,
	Position1_5  = 5,
	Position1_10 = 10,
	Position1_15 = 15,
	Position1_20 = 20,
	Position1_25 = 25,
	Position1_30 = 30,
	Position1_35 = 35,
	Position1_40 = 40,
	Position1_45 = 45,
	Position1_50 = 50,
	Position1_55 = 55,
	Position1_60 = 60,
	Position1_65 = 65,
	Position1_70 = 70,
	Position1_75 = 75,
	Position1_80 = 80,
	Position1_85 = 85,
	Position1_90 = 90,
	Position1_95 = 95,
	Position1_100 = 100,
	Position1_105 = 105,
	Position1_110 = 100,
	Position1_115 = 115,
	Position1_120 = 120,
	Position1_125 = 125,
	Position1_130 = 130,
	Position1_135 = 135,
	Position1_140 = 140,
	Position1_145 = 145,
	Position1_150 = 150,
	Position1_155 = 155,
	Position1_160 = 160,
	Position1_165 = 165,
	Position1_170 = 170,
	Position1_175 = 175,
	Position1_180 = 180
}Timer1Position_type;

void SERVO_Init_Timer(TimerMode_type timer);

void SERVO_Init_Timer1(Timer1OCMode_type OC_Mode);

void SERVO_SetPositionTimer(TimerPosition_type position);

void SERVO_SetPositionTimer1_OCRA(Timer1Position_type position);

void SERVO_SetAngleTimer1_OCRA(u8 angle);

void SERVO_SetPositionTimer1_OCRB(Timer1Position_type position);

void SERVO_SetAngleTimer1_OCRB(u8 angle);










#endif /* SERVO_H_ */