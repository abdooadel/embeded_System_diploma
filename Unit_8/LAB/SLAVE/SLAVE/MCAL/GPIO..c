/*
 * GPIO.c
 *
 * Created: 10/31/2023 10:27:36 AM
 *  Author: abdoo
 */ 
#include "GPIO.h"



void MCAL_GPIO_Init(uint8_t *PORT, GPIO_PinConfig_t *Pin_Config){
	
	switch(Pin_Config ->mode)
	{
		case (GPIO_MODE_INPUT_FLO) :
			*(volatile uint8_t*)(PORT-1) &= ~ (Pin_Config->Pin_Number);		//DDR
			*(volatile uint8_t*)(PORT) &= ~ (Pin_Config->Pin_Number);		//
			

		break;
		
		case (GPIO_MODE_INPUT_PU) :
			*(volatile uint8_t*)(PORT-1) &= ~ (Pin_Config->Pin_Number);
			*(volatile uint8_t*)(PORT) &= ~ (Pin_Config->Pin_Number);

		break;
		
		case (GPIO_MODE_OUTPUT) :
			*(volatile uint8_t*)(PORT-1) |= Pin_Config->Pin_Number;

		break;


		break;
	}

	
	
	
	
}
void MCAL_GPIO_DeInit( uint8_t *PORT){
	
	*(volatile uint8_t*)(PORT) =0x00;
	*(volatile uint8_t*)(PORT-1) =0x00;
	*(volatile uint8_t*)(PORT-2) =0x00;
}


uint8_t MCAL_READPin( uint8_t *PORT, uint8_t PinNum){
	uint8_t bitStatus;
	
	if( (*(volatile uint8_t*)(PORT-2) & PinNum ) ==0)
	{
		bitStatus = GPRIO_PIN_RESET;
	}
	else
	{
		bitStatus = GPRIO_PIN_SET;

	}
	
	return bitStatus;
}
	



uint8_t MCAL_READPort( uint8_t *PORT, uint8_t PinNum){
	uint8_t	value;
	value = (*(volatile uint8_t*)(PORT-2) & PinNum );
	return value;
	
}

void MCAL_WritePin( uint8_t *PORT, uint8_t PinNum , uint8_t value)
{
	if ( value == GPRIO_PIN_SET)
	{
		(*(volatile uint8_t*)(PORT)) |= PinNum;
		
	}
	else if ( value == GPRIO_PIN_RESET)
	{
		(*(volatile uint8_t*)(PORT)) &= ~ PinNum;
		
	}
}

void MCAL_WritePort( uint8_t *PORT,uint8_t value)
{
	(*(volatile uint8_t*)(PORT)) = value;
}

void MCAL_TogglePin( uint8_t *Port, uint8_t PinNum)
{
	
	(*(volatile uint8_t *)(Port)) ^=  PinNum;
}