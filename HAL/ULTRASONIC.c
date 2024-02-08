#include "ULTRASONIC.h"

static volatile u16 t1,t2,flag = 0 ;

static void Func_ICU(void)
{
	if(flag == 0)
	{
		t1= Timer1_ICR1_Read();
		TIMER1_InputCaptureEdge(FALLING);
		flag = 1 ;
	}
	else if(flag == 1)
	{
		t2= Timer1_ICR1_Read();
		TIMER1_ICU_InterruptDisable();
		flag = 2 ;
	}
}

void ULTRASONIC_Init(void)
{
	TIMER1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8);
	TIMER1_SetCallBack(ICU1_INT,Func_ICU);
}
	
void ULTRASONIC_GetDistance(u8* Pdistance,ULTRASONIC_type ultrasonic_pin)
{
	u16 time  = 0 ;
	*Pdistance = 0 ;
	DIO_WritePin(ultrasonic_pin,HIGH);
	_delay_us(10);
	DIO_WritePin(ultrasonic_pin,LOW);
	TIMER1_InputCaptureEdge(RISING);
	Timer1_Set(0);
	TIMER1_ICU_InterruptEnable();
	
	while(flag < 2);
	time = t2 - t1 ;
	*Pdistance = time / 58 ;
	flag = 0 ;	
}

void ULTRASONIC_Start(ULTRASONIC_type ultrasonic_pin)
{
	if(flag == 0)
	{
		
		DIO_WritePin(ultrasonic_pin,HIGH);
		_delay_us(10);
		DIO_WritePin(ultrasonic_pin,LOW);		
		TIMER1_InputCaptureEdge(RISING);
		Timer1_Set(0);
		TIMER1_ICU_InterruptEnable();
	}
}

u8 ULTRASONIC_GetDistanceNoBlock(u8*Pdistance)
{
	u16 time;
	if (flag == 2)
	{
		time = t2 - t1;
		*Pdistance = time/58;
		flag=0;
		return 1;
	}
	return 0;
}



/*
void UltraSonic_Init(void)
{
	sei();
	DIO_Init();
	TIMER1_Init(TIMER1_FASTPWM_OCRA_TOP_MODE,TIMER1_SCALER_8);
	TIMER1_SetCallBack(ICU1_INT,UltraSonic);
}

void UltraSonic_Trigger(ULTRASONIC_type pin)
{
	if(flag == 0)
	{
		TIMER1_InputCaptureEdge(RISING);
		TIMER1_ICU_InterruptEnable();
		Timer1_Set(0);
		DIO_WritePin(pin,HIGH);
		_delay_us(10);
		DIO_WritePin(pin,LOW);
	}	
}

u8 UltraSonic_GetDistancePeriodicCheck(u16* distance)
{
	u16 time  = 0 ;
	*distance = 0 ;
    if(flag == 2)
    {
	   time = t2 - t1 ;
	   *distance = time / 58 ;
	   flag  = 0 ;

	   return 1 ;
	}
	return 0 ;
}

void UltraSonic_GetDistance(u16* distance,ULTRASONIC_type pin)
{
	u16 time  = 0 ;
	*distance = 0 ;
	TIMER1_InputCaptureEdge(RISING);
	Timer1_Set(0);
	DIO_WritePin(pin,HIGH);
	_delay_us(10);
	DIO_WritePin(pin,LOW);
	while(flag < 2);
	time = t2 - t1 ;
	*distance = time / 58 ;	
	flag = 0 ;
	TIMER1_ICU_InterruptEnable();
}

void UltraSonic(void)
{
	if(flag == 0)
	{
		t1= Timer1_ICR1_Read();
		TIMER1_InputCaptureEdge(FALLING);
		flag = 1 ;
	}
	else if(flag == 1)
	{
		t2= Timer1_ICR1_Read();
		TIMER1_ICU_InterruptDisable();
		flag = 2 ;
	}
}
*/