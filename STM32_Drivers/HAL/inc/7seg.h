/*
 * IncFile1.h
 *
 * Created: 10/28/2023 10:42:40 PM
 *  Author: abdoo
 */ 


#ifndef SEG_H_
#define SEG_H_


#include "Stm32_F103C6_GPIO_drivers.h"
#include "stm32f103x6.h"

#define 	VCC_CON
//#define 	GROUND_CON
#define SEVEN_SEG_PORT		GPIOB
#define SEVEN_SEG_PIN_0		GPIO_PIN_15
#define SEVEN_SEG_PIN_1		GPIO_PIN_10
#define SEVEN_SEG_PIN_2		GPIO_PIN_11
#define SEVEN_SEG_PIN_3		GPIO_PIN_12
#define SEVEN_SEG_PIN_4		GPIO_PIN_13
#define SEVEN_SEG_PIN_5		GPIO_PIN_14
#define SEVEN_SEG_PIN_6		GPIO_PIN_9

#ifdef GROUND_CON
#define SEVEN_SEG_PIN_ON	GPIO_PIN_set
#define SEVEN_SEG_PIN_OFF	GPIO_PIN_reset
#endif

#ifdef VCC_CON
#define SEVEN_SEG_PIN_ON	GPIO_PIN_reset
#define SEVEN_SEG_PIN_OFF	GPIO_PIN_set
#endif


void seven_seg_init(void);
void seven_seg_write(int num);


#endif /* INCFILE1_H_ */
