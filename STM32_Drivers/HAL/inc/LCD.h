/*
 * LCD.h
 *
 * Created: 10/29/2023 9:11:41 AM
 *  Author: abdoo
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "Stm32_F103C6_GPIO_drivers.h"
#include "stm32f103x6.h"

#define LCD_DATA_PORT		GPIOA
#define LCD_CTRL_PORT		GPIOA

#define RS_switch		GPIO_PIN_8
#define RW_switch		GPIO_PIN_9
#define ENABLE_switch	GPIO_PIN_10

#define D0 				GPIO_PIN_0
#define D1 				GPIO_PIN_1
#define D2 				GPIO_PIN_2
#define D3 				GPIO_PIN_3
#define D4 				GPIO_PIN_4
#define D5 				GPIO_PIN_5
#define D6 				GPIO_PIN_6
#define D7 				GPIO_PIN_7


#define eight_bit_mode
//#define four_bit_mode

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


void LCD_INIT();
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char character);
void LCD_WRITE_STRING(char* string);
void LCD_check_lcd_isbusy(void);
void LCD_lcd_kick(void);
void LCD_clear_screen();
void LCD_GOTO_XY(unsigned char line, unsigned char position);





#endif /* LCD_H_ */
