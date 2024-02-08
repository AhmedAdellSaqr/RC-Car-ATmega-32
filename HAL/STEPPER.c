#include "STEPPER.h"


/******************************* BI POLAR **************************************/
void Stepper_BiPolar_CW(void)
{
	DIO_Writepin(BI_COIL1A,LOW);
	DIO_Writepin(BI_COIL1B,LOW);
	DIO_Writepin(BI_COIL2A,HIGH);
	DIO_Writepin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_Writepin(BI_COIL1A,LOW);
	DIO_Writepin(BI_COIL1B,HIGH);
	DIO_Writepin(BI_COIL2A,LOW);
	DIO_Writepin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_Writepin(BI_COIL1A,LOW);
	DIO_Writepin(BI_COIL1B,LOW);
	DIO_Writepin(BI_COIL2A,LOW);
	DIO_Writepin(BI_COIL2B,HIGH);
	_delay_ms(BI_DELAY);
	DIO_Writepin(BI_COIL1A,HIGH);
	DIO_Writepin(BI_COIL1B,LOW);
	DIO_Writepin(BI_COIL2A,LOW);
	DIO_Writepin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
}

void Stepper_BiPolar_CCW(void)
{
	DIO_Writepin(BI_COIL1A,LOW);
	DIO_Writepin(BI_COIL1B,LOW);
	DIO_Writepin(BI_COIL2A,LOW);
	DIO_Writepin(BI_COIL2B,HIGH);
	_delay_ms(BI_DELAY);
	DIO_Writepin(BI_COIL1A,LOW);
	DIO_Writepin(BI_COIL1B,HIGH);
	DIO_Writepin(BI_COIL2A,LOW);
	DIO_Writepin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_Writepin(BI_COIL1A,LOW);
	DIO_Writepin(BI_COIL1B,LOW);
	DIO_Writepin(BI_COIL2A,HIGH);
	DIO_Writepin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_Writepin(BI_COIL1A,HIGH);
	DIO_Writepin(BI_COIL1B,LOW);
	DIO_Writepin(BI_COIL2A,LOW);
	DIO_Writepin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
}

void Stepper_BiPolar_Steps_CW(u16 step)
{
	u16 i ,flag1 = 0 , flag2 = 0 ,flag3 = 0;
	for(i = 0 ; i < step ; i++)
	{
		if(flag1 == 0)
		{
			DIO_Writepin(BI_COIL1A,LOW);
			DIO_Writepin(BI_COIL1B,LOW);
			DIO_Writepin(BI_COIL2A,HIGH);
			DIO_Writepin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag1 = 1 ;
		}
		else if (flag2 == 0)
		{
			DIO_Writepin(BI_COIL1A,LOW);
			DIO_Writepin(BI_COIL1B,HIGH);
			DIO_Writepin(BI_COIL2A,LOW);
			DIO_Writepin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag2 =1 ;
		}
		else if(flag3 == 0)
		{
			DIO_Writepin(BI_COIL1A,LOW);
			DIO_Writepin(BI_COIL1B,LOW);
			DIO_Writepin(BI_COIL2A,LOW);
			DIO_Writepin(BI_COIL2B,HIGH);
			_delay_ms(BI_DELAY);
			flag3 = 1 ;
		}
		else
		{
			DIO_Writepin(BI_COIL1A,HIGH);
			DIO_Writepin(BI_COIL1B,LOW);
			DIO_Writepin(BI_COIL2A,LOW);
			DIO_Writepin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
		}
	}
}
/*
void Stepper_BiPolar_Steps_CCW(u16 step)
{
	u16 i ,flag1 = 0 , flag2 = 0 ,flag3 = 0;
	for(i = 0 ; i < step ; i++)
	{
		if(flag1 == 0)
		{
			DIO_Writepin(BI_COIL1A,LOW);
			DIO_Writepin(BI_COIL1B,LOW);
			DIO_Writepin(BI_COIL2A,LOW);
			DIO_Writepin(BI_COIL2B,HIGH);
			_delay_ms(BI_DELAY);
			flag1 = 1 ;
		}
		else if (flag2 == 0)
		{
			DIO_Writepin(BI_COIL1A,LOW);
			DIO_Writepin(BI_COIL1B,HIGH);
			DIO_Writepin(BI_COIL2A,LOW);
			DIO_Writepin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag2 =1 ;
		}
		else if(flag3 == 0)
		{
			DIO_WritePin(BI_COIL1A,LOW);
			DIO_WritePin(BI_COIL1B,LOW);
			DIO_WritePin(BI_COIL2A,HIGH);
			DIO_WritePin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag3 = 1 ;
		}
		else
		{
			DIO_WritePin(BI_COIL1A,HIGH);
			DIO_WritePin(BI_COIL1B,LOW);
			DIO_WritePin(BI_COIL2A,LOW);
			DIO_WritePin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
		}
	}
}

void Stepper_BiPolar_Angle_CW(u16 angle)
{
	u16 i ,flag1 = 0 , flag2 = 0 ,flag3 = 0;
	u16 step = angle / STEP_SIZE ;
	for(i = 0 ; i < step ; i++)
	{
		if(flag1 == 0)
		{
			DIO_WritePin(BI_COIL1A,LOW);
			DIO_WritePin(BI_COIL1B,LOW);
			DIO_WritePin(BI_COIL2A,HIGH);
			DIO_WritePin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag1 = 1 ;
		}
		else if (flag2 == 0)
		{
			DIO_WritePin(BI_COIL1A,LOW);
			DIO_WritePin(BI_COIL1B,HIGH);
			DIO_WritePin(BI_COIL2A,LOW);
			DIO_WritePin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag2 =1 ;
		}
		else if(flag3 == 0)
		{
			DIO_WritePin(BI_COIL1A,LOW);
			DIO_WritePin(BI_COIL1B,LOW);
			DIO_WritePin(BI_COIL2A,LOW);
			DIO_WritePin(BI_COIL2B,HIGH);
			_delay_ms(BI_DELAY);
			flag3 = 1 ;
		}
		else
		{
			DIO_WritePin(BI_COIL1A,HIGH);
			DIO_WritePin(BI_COIL1B,LOW);
			DIO_WritePin(BI_COIL2A,LOW);
			DIO_WritePin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
		}
	}
}

void Stepper_BiPolar_Angle_CCW(u16 angle)
{
	u16 i ,flag1 = 0 , flag2 = 0 ,flag3 = 0;
	u16 step = angle / STEP_SIZE ;
	for(i = 0 ; i < step ; i++)
	{
		if(flag1 == 0)
		{
			DIO_WritePin(BI_COIL1A,LOW);
			DIO_WritePin(BI_COIL1B,LOW);
			DIO_WritePin(BI_COIL2A,LOW);
			DIO_WritePin(BI_COIL2B,HIGH);
			_delay_ms(BI_DELAY);
			flag1 = 1 ;
		}
		else if (flag2 == 0)
		{
			DIO_WritePin(BI_COIL1A,LOW);
			DIO_WritePin(BI_COIL1B,HIGH);
			DIO_WritePin(BI_COIL2A,LOW);
			DIO_WritePin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag2 =1 ;
		}
		else if(flag3 == 0)
		{
			DIO_WritePin(BI_COIL1A,LOW);
			DIO_WritePin(BI_COIL1B,LOW);
			DIO_WritePin(BI_COIL2A,HIGH);
			DIO_WritePin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag3 = 1 ;
		}
		else
		{
			DIO_WritePin(BI_COIL1A,HIGH);
			DIO_WritePin(BI_COIL1B,LOW);
			DIO_WritePin(BI_COIL2A,LOW);
			DIO_WritePin(BI_COIL2B,LOW);
			_delay_ms(BI_DELAY);
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
		}
	}
}

void Stepper_BiPolar_HS_CW(void)
{
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,HIGH);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,HIGH);
	DIO_WritePin(BI_COIL2A,HIGH);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,HIGH);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,HIGH);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,HIGH);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,HIGH);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,HIGH);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,HIGH);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,HIGH);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,HIGH);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,HIGH);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	
}

void Stepper_BiPolar_HS_CCW(void)
{
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,HIGH);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,HIGH);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,HIGH);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,HIGH);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,HIGH);
	DIO_WritePin(BI_COIL2A,HIGH);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,LOW);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,HIGH);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,HIGH);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,HIGH);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,HIGH);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,LOW);
	_delay_ms(BI_DELAY);
	DIO_WritePin(BI_COIL1A,HIGH);
	DIO_WritePin(BI_COIL1B,LOW);
	DIO_WritePin(BI_COIL2A,LOW);
	DIO_WritePin(BI_COIL2B,HIGH);
	_delay_ms(BI_DELAY);
	
}*/

/******************************* UNI POLAR **************************************/

void Stepper_UniPolar_CW(void)
{
	DIO_Writepin(UNI_COIL1A,LOW);
	DIO_Writepin(UNI_COIL1B,HIGH);
	DIO_Writepin(UNI_COIL2A,LOW);
	DIO_Writepin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_Writepin(UNI_COIL1A,LOW);
	DIO_Writepin(UNI_COIL1B,LOW);
	DIO_Writepin(UNI_COIL2A,HIGH);
	DIO_Writepin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_Writepin(UNI_COIL1A,LOW);
	DIO_Writepin(UNI_COIL1B,LOW);
	DIO_Writepin(UNI_COIL2A,LOW);
	DIO_Writepin(UNI_COIL2B,HIGH);
	_delay_ms(UNI_DELAY);
	DIO_Writepin(UNI_COIL1A,HIGH);
	DIO_Writepin(UNI_COIL1B,LOW);
	DIO_Writepin(UNI_COIL2A,LOW);
	DIO_Writepin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	
}

void Stepper_UniPolar_CCW(void)
{
	DIO_Writepin(UNI_COIL1A,HIGH);
	DIO_Writepin(UNI_COIL1B,LOW);
	DIO_Writepin(UNI_COIL2A,LOW);
	DIO_Writepin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_Writepin(UNI_COIL1A,LOW);
	DIO_Writepin(UNI_COIL1B,LOW);
	DIO_Writepin(UNI_COIL2A,LOW);
	DIO_Writepin(UNI_COIL2B,HIGH);
	_delay_ms(UNI_DELAY);
	DIO_Writepin(UNI_COIL1A,LOW);
	DIO_Writepin(UNI_COIL1B,LOW);
	DIO_Writepin(UNI_COIL2A,HIGH);
	DIO_Writepin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_Writepin(UNI_COIL1A,LOW);
	DIO_Writepin(UNI_COIL1B,HIGH);
	DIO_Writepin(UNI_COIL2A,LOW);
	DIO_Writepin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	
}
/*
void Stepper_UniPolar_HS_CW(void)
{
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,HIGH);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,HIGH);
	DIO_WritePin(UNI_COIL2A,HIGH);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,HIGH);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,HIGH);
	DIO_WritePin(UNI_COIL2B,HIGH);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,HIGH);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,HIGH);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,HIGH);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,HIGH);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,HIGH);
	DIO_WritePin(UNI_COIL1B,HIGH);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
}

void Stepper_UniPolar_HS_CCW(void)
{
	DIO_WritePin(UNI_COIL1A,HIGH);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,HIGH);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,HIGH);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,HIGH);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,HIGH);
	DIO_WritePin(UNI_COIL2B,HIGH);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,LOW);
	DIO_WritePin(UNI_COIL2A,HIGH);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,HIGH);
	DIO_WritePin(UNI_COIL2A,HIGH);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,LOW);
	DIO_WritePin(UNI_COIL1B,HIGH);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
	DIO_WritePin(UNI_COIL1A,HIGH);
	DIO_WritePin(UNI_COIL1B,HIGH);
	DIO_WritePin(UNI_COIL2A,LOW);
	DIO_WritePin(UNI_COIL2B,LOW);
	_delay_ms(UNI_DELAY);
}

void Stepper_UniPolar_Steps_CW(u16 step)
{
	u16 i ,flag1 = 0 , flag2 = 0 ,flag3 = 0;
	for(i = 0 ; i < step ; i++)
	{
		if(flag1 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,HIGH);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag1 = 1 ;
		}
		else if (flag2 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,HIGH);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag2 =1 ;
		}
		else if(flag3 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,HIGH);
			_delay_ms(UNI_DELAY);
			flag3 = 1 ;
		}
		else
		{
			DIO_WritePin(UNI_COIL1A,HIGH);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
		}
	}
}

void Stepper_UniPolar_Steps_CCW(u16 step)
{
	u16 i ,flag1 = 0 , flag2 = 0 ,flag3 = 0;
	for(i = 0 ; i < step ; i++)
	{
		if(flag1 == 0)
		{
			DIO_WritePin(UNI_COIL1A,HIGH);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag1 = 1 ;
		}
		else if (flag2 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,HIGH);
			_delay_ms(UNI_DELAY);
			flag2 =1 ;
		}
		else if(flag3 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,HIGH);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag3 = 1 ;
		}
		else
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,HIGH);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
		}
	}
}

void Stepper_UniPolar_Angle_CW(u16 angle)
{
	u16 i ,flag1 = 0 , flag2 = 0 ,flag3 = 0;
	u16 step = angle / STEP_SIZE ;
	for(i = 0 ; i < step ; i++)
	{
		if(flag1 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,HIGH);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag1 = 1 ;
		}
		else if (flag2 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,HIGH);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag2 =1 ;
		}
		else if(flag3 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,HIGH);
			_delay_ms(UNI_DELAY);
			flag3 = 1 ;
		}
		else
		{
			DIO_WritePin(UNI_COIL1A,HIGH);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
		}
	}
}

void Stepper_UniPolar_Angle_CCW(u16 angle)
{
	u16 i ,flag1 = 0 , flag2 = 0 ,flag3 = 0;
	u16 step = angle / STEP_SIZE ;
	for(i = 0 ; i < step ; i++)
	{
		if(flag1 == 0)
		{
			DIO_WritePin(UNI_COIL1A,HIGH);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag1 = 1 ;
		}
		else if (flag2 == 0)
		{
			DIO_WritePin(UNI_COIL1A,LOW);
			DIO_WritePin(UNI_COIL1B,LOW);
			DIO_WritePin(UNI_COIL2A,LOW);
			DIO_WritePin(UNI_COIL2B,HIGH);
			_delay_ms(UNI_DELAY);
			flag2 =1 ;
		}
		else if(flag3 == 0)
		{
			DIO_Writepin(UNI_COIL1A,LOW);
			DIO_Writepin(UNI_COIL1B,LOW);
			DIO_Writepin(UNI_COIL2A,HIGH);
			DIO_Writepin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag3 = 1 ;
		}
		else
		{
			DIO_Writepin(UNI_COIL1A,LOW);
			DIO_Writepin(UNI_COIL1B,HIGH);
			DIO_Writepin(UNI_COIL2A,LOW);
			DIO_Writepin(UNI_COIL2B,LOW);
			_delay_ms(UNI_DELAY);
			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
		}
	}
}*/