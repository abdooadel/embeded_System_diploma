/*
 * KEYBAD.h
 *
 * Created: 10/29/2023 1:52:36 PM
 *  Author: abdoo
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_

#include "Utlis.h"
#include "memory_map.h"

#define KEYPAD_PORT			PORTD
#define KEYPAD_DATA_DIR		DDRD
#define KEYPAD_PIN			PIND

#define R0	0
#define R1	1
#define R2	2
#define R3	3
#define C0	4
#define C1	5
#define C2	6
#define C3	7


void KEYPAD_INIT(void);
char KEYPAD_GETCHAR(void);



#endif /* KEYBAD_H_ */
