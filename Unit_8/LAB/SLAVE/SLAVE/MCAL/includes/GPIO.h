/*
 * GPIO.h
 *
 * Created: 10/31/2023 10:27:54 AM
 *  Author: abdoo
 */ 








#ifndef ATMEGA32_GPIO_H_
#define ATMEGA32_GPIO_H_

#include "atmega32_driver.h"



typedef struct{
	
	uint8_t		Pin_Number;				//choose mode from @ref GPIO_PIN_define	
	uint8_t		mode;					//choose mode from @ref GPIO_MODE_define	
	
	}GPIO_PinConfig_t;




//@ref GPIO_PIN_define	
#define GPIO_PIN_0		0b00000001
#define GPIO_PIN_1		0b00000010
#define GPIO_PIN_2		0b00000100
#define GPIO_PIN_3		0b00001000
#define GPIO_PIN_4		0b00010000
#define GPIO_PIN_5		0b00100000
#define GPIO_PIN_6		0b01000000
#define GPIO_PIN_7		0b10000000


//@ref GPIO_MODE_define
#define GPIO_MODE_INPUT_FLO						0
#define GPIO_MODE_INPUT_PU							1
#define GPIO_MODE_OUTPUT							2



//@ref #GPIO_PIN_state
#define GPRIO_PIN_SET		1
#define GPRIO_PIN_RESET		0






void MCAL_GPIO_Init(uint8_t *Port, GPIO_PinConfig_t *Pin_Config);
void MCAL_GPIO_DeInit( uint8_t *Port);
uint8_t MCAL_READPin( uint8_t *Port, uint8_t PinNum);
uint8_t MCAL_READPort( uint8_t *Port, uint8_t PinNum);
void MCAL_WritePort( uint8_t *Port, uint8_t value);
void MCAL_WritePin( uint8_t *Port, uint8_t PinNum ,uint8_t value);
void MCAL_TogglePin( uint8_t *Port, uint8_t PinNum);




#endif