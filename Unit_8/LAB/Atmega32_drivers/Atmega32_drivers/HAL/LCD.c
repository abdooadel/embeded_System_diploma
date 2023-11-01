/*
 * LCD.c
 *
 * Created: 10/29/2023 9:11:28 AM
 *  Author: abdoo
 */ 

#include "LCD.h"



void GPIO_INIT(void){

GPIO_PinConfig_t PinConfig;
PinConfig.Pin_Number= GPIO_PIN_4;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_5;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_6;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_7;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTD, &PinConfig);

#ifdef eight_bit_mode
PinConfig.Pin_Number= GPIO_PIN_0;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_1;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_2;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_3;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTD, &PinConfig);

#endif

PinConfig.Pin_Number= GPIO_PIN_1;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTB, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_2;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTB, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_3;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTB, &PinConfig);	
}

void Data_INPUT (void)
{
	

GPIO_PinConfig_t PinConfig;
PinConfig.Pin_Number= GPIO_PIN_4;
PinConfig.mode = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_5;
PinConfig.mode = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_6;
PinConfig.mode = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_7;
PinConfig.mode = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init(PORTD, &PinConfig);

#ifdef eight_bit_mode
PinConfig.Pin_Number= GPIO_PIN_0;
PinConfig.mode = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_1;
PinConfig.mode = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_2;
PinConfig.mode = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init(PORTD, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_3;
PinConfig.mode = GPIO_MODE_INPUT_FLO;
MCAL_GPIO_Init(PORTD, &PinConfig);

#endif
	
	
	
	
	
	
	
	
	
	
	
	
}
void LCD_CRUSOR_GOTO_XY(unsigned char x, unsigned char y){
	if(y<16 && y>=0)
	{
		
		if (x==1)
		{
			LCD_WRITE_COMMAND(LCD_CRUSOR_FIRST_ROW);
		}
		if (x==2)
		{
			LCD_WRITE_COMMAND(LCD_CRUSOR_SECOND_ROW);
		}
	}
	
}
void LCD_config(void){
	MCAL_WritePin(LCD_CTRL_PORT, ENABLE_switch , GPRIO_PIN_SET);
	//ClearBit(LCD_CTRL_PORT,ENABLE_switch);
	_delay_ms(50);
	//SetBit(LCD_CTRL_PORT,ENABLE_switch);
	MCAL_WritePin(LCD_CTRL_PORT, ENABLE_switch , GPRIO_PIN_RESET);

}

void LCD_busy(){
	#ifdef eight_bit_mode
	Data_INPUT();
	//DATA_DIRC_LCD=0x00;
#endif
#ifdef four_bit_mode
	Data_INPUT();
	//DATA_DIRC_LCD &= ~(0xFF <<4 );
#endif

	MCAL_WritePin(LCD_CTRL_PORT, ENABLE_switch , GPRIO_PIN_SET);
GPIO_PinConfig_t PinConfig;
PinConfig.Pin_Number= GPIO_PIN_1;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTB, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_2;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTB, &PinConfig);
PinConfig.Pin_Number= GPIO_PIN_3;
PinConfig.mode = GPIO_MODE_OUTPUT;
MCAL_GPIO_Init(PORTB, &PinConfig);
MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_SET);
MCAL_WritePin(LCD_CTRL_PORT, RS_switch , GPRIO_PIN_RESET);
LCD_config();
MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_RESET);
	
	//SetBit(LCD_CTRL_PORT,RW_switch);
	//ClearBit(LCD_CTRL_PORT,RS_switch);
	//LCD_config();
	//DATA_DIRC_LCD=0xFF;
	//ClearBit(LCD_CTRL_PORT,RW_switch);
		}
		
void LCD_clear_screen(void){
	LCD_WRITE_COMMAND(LCD_CLEAR);
}
void LCD_init(void){
	
	_delay_ms(20);
	
	
		LCD_busy();
		GPIO_INIT();
		_delay_ms(5);
		//SetBit(DATA_DIRC_CTRL,RS_switch);
		//SetBit(DATA_DIRC_CTRL,RW_switch);
		//SetBit(DATA_DIRC_CTRL,ENABLE_switch);
		MCAL_WritePin(LCD_CTRL_PORT, RS_switch , GPRIO_PIN_RESET);
		MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_RESET);
		MCAL_WritePin(LCD_CTRL_PORT, ENABLE_switch , GPRIO_PIN_RESET);

		//ClearBit(LCD_CTRL_PORT,RS_switch);
		//ClearBit(LCD_CTRL_PORT,RW_switch);
		//ClearBit(LCD_CTRL_PORT,ENABLE_switch);
		//DATA_DIRC_LCD=0xFF;
	#ifdef eight_bit_mode

		LCD_clear_screen();
		LCD_WRITE_COMMAND(LCD_FUNCTION_8bits_2lines);
	#endif

	#ifdef four_bit_mode
		LCD_WRITE_COMMAND(0x02);
		LCD_WRITE_COMMAND(LCD_FUNCTION_4bits_2lines);
	#endif
	
	 LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	 LCD_WRITE_COMMAND(LCD_CRUSOR_FIRST_ROW);
	 LCD_WRITE_COMMAND(LCD_DISPLAY_CRUSOR_BLINK);

	
	
}

void LCD_WRITE_COMMAND(unsigned char coomand){
	LCD_busy();
	#ifdef eight_bit_mode
		MCAL_WritePin(LCD_CTRL_PORT, RS_switch , GPRIO_PIN_RESET);
		MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_RESET);
		//ClearBit(LCD_CTRL_PORT,RW_switch);
		//ClearBit(LCD_CTRL_PORT,RS_switch);
		MCAL_WritePort(LCD_DATA_PORT,coomand)
		//LCD_PORT=coomand;
		LCD_config();
#endif

#ifdef four_bit_mode

	MCAL_WritePort(LCD_DATA_PORT,(coomand & 0xF0) );
	MCAL_WritePin(LCD_CTRL_PORT, RS_switch , GPRIO_PIN_RESET);
	MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_RESET);
	//LCD_PORT= (LCD_PORT & 0x0F) | (coomand & 0xF0);
	//ClearBit(LCD_CTRL_PORT,RW_switch);
	//ClearBit(LCD_CTRL_PORT,RS_switch);
	LCD_config();
	
	MCAL_WritePort(LCD_DATA_PORT,(coomand <<4) );
	MCAL_WritePin(LCD_CTRL_PORT, RS_switch , GPRIO_PIN_RESET);
	MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_RESET);
	//LCD_PORT= (LCD_PORT & 0x0F) | (coomand << 4);
	//ClearBit(LCD_CTRL_PORT,RW_switch);
	//ClearBit(LCD_CTRL_PORT,RS_switch);
	
	LCD_config();

#endif
	
	
}

void LCD_WRITE_CHAR(unsigned char data){
		LCD_busy();

		static int counter=0;

	#ifdef eight_bit_mode
	
	MCAL_WritePort(LCD_DATA_PORT,data );
	MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_RESET);
	MCAL_WritePin(LCD_CTRL_PORT, RS_switch , GPRIO_PIN_SET);
	//LCD_PORT=data;	
	//ClearBit(LCD_CTRL_PORT,RW_switch);
	//SetBit(LCD_CTRL_PORT,RS_switch);
	
	LCD_config();
	
	
counter++;
if (counter == 16)
{

	LCD_CRUSOR_GOTO_XY(2,0);
}
else if (counter==32){
	LCD_clear_screen();
	LCD_CRUSOR_GOTO_XY(1,0);
	counter=0;
}
#endif
#ifdef four_bit_mode

	MCAL_WritePort(LCD_DATA_PORT,(data & 0xF0) );
	MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_RESET);
	MCAL_WritePin(LCD_CTRL_PORT, RS_switch , GPRIO_PIN_SET);
	
	//LCD_PORT= (LCD_PORT & 0x0F) | (data & 0xF0);
	//ClearBit(LCD_CTRL_PORT,RW_switch);
	//SetBit(LCD_CTRL_PORT,RS_switch);
	
	LCD_config();

	MCAL_WritePort(LCD_DATA_PORT, (data <<4) );
	MCAL_WritePin(LCD_CTRL_PORT, RW_switch , GPRIO_PIN_RESET);
	MCAL_WritePin(LCD_CTRL_PORT, RS_switch , GPRIO_PIN_SET);
	
	//LCD_PORT= (LCD_PORT & 0x0F) | (data <<4);
	//ClearBit(LCD_CTRL_PORT,RW_switch);
	//SetBit(LCD_CTRL_PORT,RS_switch);
	
	LCD_config();
#endif
}


void LCD_WRITE_STRING(char *data){
		LCD_busy();

	char count=0;
	while( *data >0 )
	{
		count++;
		LCD_WRITE_CHAR(*data++);

		if (count == 16)
		{

			LCD_CRUSOR_GOTO_XY(2,0);
		}
		else if (count==32){
				LCD_clear_screen();
				LCD_CRUSOR_GOTO_XY(1,0);
				count=0;
			}

	}

}