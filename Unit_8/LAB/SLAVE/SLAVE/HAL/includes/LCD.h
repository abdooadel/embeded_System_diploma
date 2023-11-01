/*
 * LCD.h
 *
 * Created: 10/29/2023 9:11:41 AM
 *  Author: abdoo
 */ 


#ifndef LCD_H_
#define LCD_H_

#define F_CPU 1000000UL
#include <util/delay.h>
#include "GPIO.h"
#include "atmega32_driver.h"

#define LCD_DATA_PORT		PORTA
#define DATA_DIRC_LCD		DDRA
#define LCD_CTRL_PORT		PORTB
#define DATA_DIRC_CTRL		DDRB

#define RS_switch			GPIO_PIN_1
#define RW_switch			GPIO_PIN_2
#define ENABLE_switch		GPIO_PIN_3

//#define eight_bit_mode
#define four_bit_mode

#define LCD_FUNCTION_8bits_1lines	(0x30)
#define LCD_FUNCTION_8bits_2lines	(0x38)
#define LCD_FUNCTION_4bits_1lines	(0x20)
#define LCD_FUNCTION_4bits_2lines	(0x28)
#define LCD_ENTRY_MODE				(0x06)
#define LCD_DISPLAY_OFF				(0x08)
#define	LCD_DISPLAY_CRUSOR_ON		(0x0E)
#define	LCD_DISPLAY_CRUSOR_OFF		(0x0C)
#define	LCD_DISPLAY_CRUSOR_BLINK	(0x0F)
#define LCD_SHIFT_RIGHT				(0x1C)
#define LCD_SHIFT_LEFT				(0x18)
#define LCD_MOVE_CRUSOR_LEFT		(0x10)
#define LCD_MOVE_CRUSOR_RIGHT		(0x14)
#define	LCD_CLEAR					(0x01)
#define LCD_CRUSOR_FIRST_ROW		(0x80)
#define LCD_CRUSOR_SECOND_ROW		(0xC0)


void LCD_init(void);
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_STRING(char *data);
void LCD_WRITE_CHAR(unsigned char data);
void LCD_busy(void);
void LCD_clear_screen(void);




#endif /* LCD_H_ */