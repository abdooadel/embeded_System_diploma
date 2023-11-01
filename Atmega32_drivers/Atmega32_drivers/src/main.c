
#include "GPIO.h"
#include "atmega32_driver.h"
#include "GPIO.h"
#include "KEYBAD.h"
#include "LCD.h"
#include <util/delay.h>
#include "UART.h"


int main (void)
{ 
	
	/*
	GPIO_PinConfig_t PinConfig;
	PinConfig.Pin_Number= GPIO_PIN_7;
	PinConfig.mode = GPIO_MODE_OUTPUT;
	MCAL_GPIO_Init(PORTD, &PinConfig);
	PinConfig.Pin_Number= GPIO_PIN_0;
	PinConfig.mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(PORTD, &PinConfig);
	*/
	LCD_init();
	//LCD_WRITE_STRING("LEARN IN DEPTH");
	
	uint8_t data;
	
	UART_Init();
	
	Uart_Send('A');
	Uart_Send('B');
	Uart_Send('D');
	Uart_Send('O');
	uint8_t *string[5];
	volatile uint8_t *x=120 ;
	UART_Send_String("ABDO\r");
	LCD_WRITE_STRING("ABDO##");

	while(1)
	{
		/*
		if ( MCAL_READPin(PORTD, GPIO_PIN_0) == GPRIO_PIN_SET)
		MCAL_WritePin(PORTD, GPIO_PIN_7,GPRIO_PIN_SET );
		else
				MCAL_WritePin(PORTD, GPIO_PIN_7,GPRIO_PIN_RESET );

		_delay_ms(1000);
*/
		
		
		//data= Uart_Recieve();
		
		
	Uart_Recieve_String(x);
	LCD_clear_screen();
	LCD_WRITE_STRING(x);
	_delay_ms(500);

		
		
	}
	return 0;
}
