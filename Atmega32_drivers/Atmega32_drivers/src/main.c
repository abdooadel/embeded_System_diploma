
#include "GPIO.h"
#include "atmega32_driver.h"
#include "GPIO.h"
#include "KEYBAD.h"
#include "LCD.h"
#include <util/delay.h>

int main (void)
{ 
	GPIO_PinConfig_t PinConfig;
	PinConfig.Pin_Number= GPIO_PIN_7;
	PinConfig.mode = GPIO_MODE_OUTPUT;
	MCAL_GPIO_Init(PORTD, &PinConfig);
	PinConfig.Pin_Number= GPIO_PIN_0;
	PinConfig.mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(PORTD, &PinConfig);
	
	LCD_init();
	LCD_WRITE_STRING("LEARN IN DEPTH");
	while(1)
	{
		if ( MCAL_READPin(PORTD, GPIO_PIN_0) == GPRIO_PIN_SET)
		MCAL_WritePin(PORTD, GPIO_PIN_7,GPRIO_PIN_SET );
		else
				MCAL_WritePin(PORTD, GPIO_PIN_7,GPRIO_PIN_RESET );

		_delay_ms(1000);

	}
	return 0;
}
