#include "MemMap.h"
#include "Utils.h"
#include "StdTypes.h"
#include "LCD.h"
#include "DIO_interface.h"
#include "move.h"
#include "MOTOR_interface.h"
#include "KeyPad.h"
#include "ADC.h"
#include "Sensors.h"
#include "UART.h"
#include "UART_Services.h"
#include "UART_Private.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "EXI_Interrupt.h"
#include "SERVO.h"
#include "STEPPER.h"
#define F_CPU  8000000
#include <util/delay.h>

#define Repet 5
volatile long i=0;

#define LED_RED    PINA1
#define LED_GREEN  PINA2
#define LED_BLUEE  PINA3

#define MOTOR  PINB7   //MOTOR AND RELAY

               //MOTOR AND ULN2003A
#define M1  PINC0     
#define M2  PINC1
#define M3  PINC2
               //MOTOR AND L293D h bridge
#define IN1  PIND0
#define IN2  PIND1
#define IN3  PIND2
#define IN4	 PIND3	
               /******/
#define IN5  PINA0
#define IN6	 PINA1	

#include "RC_Project.h"

///////////////////////RC////////////////////////////////

u8  rec;
void UART_Project(void)
{
	rec=UART_ReceiveNoBlock();
}
/**********************************************************/

void SERVO_setPosition(u8 angle)
{
	OCR1A=((angle*(u32)1000)/180)+999;
}



int main(void)
{  
	DIO_Init();
	LCD_Init();
	LCD_Init();
	UART_Init();
	
	
	ADC_Init(VREF_AVCC,ADC_SCALER_64);	
    sei();
	UART_Receive_SetCallBack(UART_Project);
    UART_ReceiveInterruptEnable();
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC_Mode(OC0_NON_INVERTING);
	TIMER1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	TIMER1_OCRA1_Mode(OCRA_NON_INVERTING);
	
	LCD_WriteString("Rc Car");

	while(1)
	{
/********************************************************* Forward and Receive *************************************************************************/		
		////////////////RC////////////////////
		
		if ( UART_Receive()=='F')
		{
			//LCD_WriteString("car_Forward");
			//LCD_SetCursor(1,0);
			car_Forward();
			SERVO_setPosition(150);
			while((UART_Receive()=='F'));
			
		}
		else if (UART_Receive()=='B')
		{
			car_Backward();
			SERVO_setPosition(150);
			while((UART_Receive()=='B'));
		//	LCD_WriteString("car_Backward");
		//	LCD_SetCursor(1,0);
		}
		
/****************************** Forward Right(I) /\ Forward Left(G) /\ ReceiveRight(J) /\ ReceiveLeft(H)********************************************/		
		else if (UART_Receive()=='I')
		{
			car_Forward();
			SERVO_setPosition(210);
			while((UART_Receive()=='I'));
		//	LCD_WriteString("Forward Right(I)");
		//	LCD_SetCursor(1,0);
		}
		
		else if (UART_Receive()=='G')
		{
			car_Forward();
			SERVO_setPosition(110);
			while((UART_Receive()=='G'));
			//LCD_WriteString("Forward Left(G)");
			//LCD_SetCursor(1,0);
		}
		
		else if (UART_Receive()=='J')
		{
			car_Backward();
			SERVO_setPosition(210);
			while((UART_Receive()=='J'));
			//LCD_WriteString("Receive Right(J)");
			//LCD_SetCursor(1,0);
		}
		
		else if (UART_Receive()=='H')
		{
			car_Backward();
			SERVO_setPosition(110);
			while((UART_Receive()=='H'));
			//LCD_WriteString("Receive Left(H)");
			//LCD_SetCursor(1,0);
		}
		
/******************************************************** Right and Left and stop *********************************************************************/
////////////////////
		else if (UART_Receive()=='R')
		{
			SERVO_setPosition(210);
			//LCD_WriteString("Right(R)");
			//LCD_SetCursor(1,0);
			
		}
		else if (UART_Receive()=='L')
		{
			SERVO_setPosition(110);
			//LCD_WriteString("Left(L)");
			//LCD_SetCursor(1,0);
		}
		else if (UART_Receive()=='S')
		{
			car_Stop();
			SERVO_setPosition(150);
			//LCD_WriteString("Stop(S)");
			//LCD_SetCursor(1,0);
		}
/********************************************************************* LED /\ BUZZER *********************************************************************************/		
		else if (UART_Receive()=='W')
		{
			DIO_Writepin(PINB0,HIGH);
			DIO_Writepin(PINB1,HIGH);
			DIO_Writepin(PINB2,HIGH);
			DIO_Writepin(PINB3,HIGH);
			LCD_WriteString("Front Lights(on)");
			LCD_SetCursor(1,0);
		}
		else if (UART_Receive()=='w')
		{
			DIO_Writepin(PINB0,LOW);
			DIO_Writepin(PINB1,LOW);
			DIO_Writepin(PINB2,LOW);
			DIO_Writepin(PINB3,LOW);
			LCD_WriteString("Front Lights(off)");
			LCD_SetCursor(1,0);
		}
		else if (UART_Receive()=='U')
		{
			DIO_Writepin(PINB4,HIGH);
			DIO_Writepin(PINB5,HIGH);
			DIO_Writepin(PINB6,HIGH);
			DIO_Writepin(PINB7,HIGH);
			LCD_WriteString("Back Lights(on)");
			LCD_SetCursor(1,0);
		}
		else if (UART_Receive()=='u')
		{
			DIO_Writepin(PINB4,LOW);
			DIO_Writepin(PINB5,LOW);
			DIO_Writepin(PINB6,LOW);
			DIO_Writepin(PINB7,LOW);
			LCD_WriteString("Back Lights(off)");
			LCD_SetCursor(1,0);
		}
		else if (UART_Receive()=='V')
		{
			DIO_Writepin(PINC5,HIGH);
			LCD_WriteString("BUZZER(on)");
			LCD_SetCursor(1,0);
		}
		else if (UART_Receive()=='v')
		{
			DIO_Writepin(PINC5,LOW);
			LCD_WriteString("BUZZER(off)");
			LCD_SetCursor(1,0);
		}
		
	}
}
	
	
