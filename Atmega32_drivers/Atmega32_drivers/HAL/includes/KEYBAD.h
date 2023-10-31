/*
 * KEYBAD.h
 *
 * Created: 10/29/2023 1:52:36 PM
 *  Author: abdoo
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_
#include "GPIO.h"

#define KEYPAD_PORT			PORTD


#define R0					GPIO_PIN_0
#define R1					GPIO_PIN_1
#define R2					GPIO_PIN_2
#define R3					GPIO_PIN_3
#define C0					GPIO_PIN_4
#define C1					GPIO_PIN_5
#define C2					GPIO_PIN_6
#define C3					GPIO_PIN_7


void KEYPAD_INIT(void);
char KEYPAD_GETCHAR(void);



#endif /* KEYBAD_H_ */