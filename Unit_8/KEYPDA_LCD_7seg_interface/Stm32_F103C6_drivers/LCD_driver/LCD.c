/*
 * lcd.c
 *
 * Created: 4/22/2021 3:01:11 PM
 *  Author: Marco
 */

#include "lcd.h"

GPIO_PinConfig_t PinCfg ;


void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

void LCD_GPIO_init() {
	PinCfg.GPIO_PinNumber = RS_switch;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = RW_switch;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = ENABLE_switch;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	//============================
	// SET THE NEXT 8 PINS AS INPUT
	PinCfg.GPIO_PinNumber = D0;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D1;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D2;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D3;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D4;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D5;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D6;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D7;
	PinCfg.GPIO_Mode = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	//	DataDir_LCD_CTRL |= (1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, ENABLE_switch, GPIO_PIN_reset);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS_switch, GPIO_PIN_reset);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW_switch, GPIO_PIN_reset);

}

void LCD_clear_screen() {
	LCD_WRITE_COMMAND(LCD_CLEAR);
}

void LCD_lcd_kick() {
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, ENABLE_switch, GPIO_PIN_set);
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, ENABLE_switch, GPIO_PIN_reset);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_CRUSOR_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_CRUSOR_SECOND_ROW + position);
		}
	}
}

void LCD_INIT() {

	delay_ms(20);
	// SET THE FIRST 3 PINS AS OUPUT
	LCD_GPIO_init();
//	LCD_CTRL &= ~(1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
//	DataDir_LCD_PORT = 0xFF;
	delay_ms(15);

	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8bits_2lines);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_CRUSOR_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISPLAY_CRUSOR_BLINK);
}

void LCD_check_lcd_isbusy() {
//	DataDir_LCD_PORT &= ~(0xFF << DATA_shift);
	PinCfg.GPIO_PinNumber = D0;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D1;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D2;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D3;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D4;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D5;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D6;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D7;
	PinCfg.GPIO_Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL_PORT, &PinCfg);

	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW_switch, GPIO_PIN_set);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS_switch, GPIO_PIN_reset);
//	LCD_CTRL |= (1 << RW_SWITCH);
//	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick();
//	DataDir_LCD_PORT |= (0xFF << DATA_shift);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW_switch, GPIO_PIN_reset);
//	LCD_CTRL &= ~(1 << RW_SWITCH);

}

void LCD_WRITE_COMMAND(unsigned char command) {
//	LCD_check_lcd_isbusy();
	MCAL_GPIO_WritePort(LCD_CTRL_PORT, command);
//	LCD_CTRL->BRR = (LCD_CTRL->BRR & 0x00FF) | (command);
//	LCD_CTRL->CRL ^= (LCD_CTRL->CRL ^ command) & 0x00ff;
//	LCD_CTRL->CRL = command;
//	LCD_CTRL ^= (LCD_CTRL-> ^ command) & 0x00ff;
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW_switch, GPIO_PIN_reset);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS_switch, GPIO_PIN_reset);
//	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	delay_ms(1);
	LCD_lcd_kick();

}

void LCD_WRITE_CHAR(unsigned char character) {
//	LCD_check_lcd_isbusy();
//	LCD_CTRL->CRL = character;
//	LCD_CTRL->CRL ^= (LCD_CTRL->CRL ^ character) & 0x00ff;
	MCAL_GPIO_WritePort(LCD_CTRL_PORT, character);
//	LCD_CTRL ^= (LCD_CTRL ^ character) & 0x00ff;
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RW_switch, GPIO_PIN_reset);
	MCAL_GPIO_WritePin(LCD_CTRL_PORT, RS_switch, GPIO_PIN_set);
//	LCD_CTRL &= ~(1 << RW_SWITCH);
//	LCD_CTRL |= (1 << RS_SWITCH);
	delay_ms(1);
	LCD_lcd_kick();
}

void LCD_WRITE_STRING(char *string) {
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) {
			LCD_GOTO_XY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}
