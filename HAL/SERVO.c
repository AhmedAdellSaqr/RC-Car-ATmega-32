#include "SERVO.h"

static u8 Position ;

static void Servo_CallBack_int(void)
{
	static u16 c ;
	c++ ;
	Timer0_Set(13);
	if(c == Position)
	{
		DIO_Writepin(PINB3,HIGH);
	}
	else if (c == 80)
	{
		DIO_Writepin(PINB3,LOW);
		c = 0 ;
	}
}

void SERVO_Init_Timer(TimerMode_type timer)
{
	switch(timer)
	{
		case TIMER0:
		TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0SCALER);
		TIMER0_OC_Mode(TIMER0OC);
		TIMER0_OV_InterruptEnable();
		TIMER0_SetCallBack(OVF0_INT,Servo_CallBack_int);
		break;
		case TIMER2:
		TIMER2_Init(TIMER2_FASTPWM_MODE,TIMER2SCALER);
		TIMER2_OC_Mode(TIMER2OC);
		TIMER2_OV_InterruptEnable();
		TIMER2_SetCallBack(OVF2_INT,Servo_CallBack_int);
		break;
	}
}

void SERVO_Init_Timer1(Timer1OCMode_type OC_Mode)
{
	switch(OC_Mode)
	{
		case TIMER1A_ICR_TOP:
		TIMER1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1A_ICR_TOP_SCALER);
		Timer1_ICR1_Set(SERVO_FREQ);
		
		#if   CHANNEL_SELECT == OCRA
		TIMER1_OCRA1_Mode(TIMER1A_ICR_TOP_OC);
		
		#elif CHANNEL_SELECT == OCRB
		TIMER1_OCRB1_Mode(TIMER1A_ICR_TOP_OC);
		
		#elif CHANNEL_SELECT == OCRA_OCRB
		TIMER1_OCRA1_Mode(TIMER1A_ICR_TOP_OC);
		TIMER1_OCRB1_Mode(TIMER1_OCRB_MODE);
		#endif
		
		break;
		case TIMER1B_OCRA_TOP:
		TIMER1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1B_OCRA_TOP_SCALER);
		Timer1_OCA_Set(SERVO_FREQ);
		TIMER1_OCRB1_Mode(TIMER1B_OCRA_TOP_OC);
		break;
	}
}

void SERVO_SetPositionTimer(TimerPosition_type position)
{
	Position = position ;
}

void SERVO_SetPositionTimer1_OCRA(Timer1Position_type position)
{
	#if program == On_Proteus
	Timer1_OCA_Set((u32)position*1000 /180 + 999);
	
	#elif program == On_Kit
	Timer1_OCA_Set((u32)position*2000 /180 + 499);
	#endif
}

void SERVO_SetAngleTimer1_OCRA(u8 angle)
{
	#if program == On_Proteus
	Timer1_OCA_Set((u32)angle*1000 /180 + 999);
	
	#elif program == On_Kit
	Timer1_OCA_Set((u32)angle*2000 /180 + 499);
	#endif
}

void SERVO_SetPositionTimer1_OCRB(Timer1Position_type position)
{
	#if program == On_Proteus
	Timer1_OCB_Set((u32)position*1000 /180 + 999);
	
	#elif program == On_Kit
	Timer1_OCB_Set((u32)position*2000 /180 + 499);
	#endif
}

void SERVO_SetAngleTimer1_OCRB(u8 angle)
{
	#if program == On_Proteus
	Timer1_OCB_Set((u32)angle*1000 /180 + 999);
	
	#elif program == On_Kit
	Timer1_OCB_Set((u32)angle*2000 /180 + 499);
	#endif
}