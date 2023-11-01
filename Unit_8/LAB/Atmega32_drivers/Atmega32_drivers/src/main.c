
#include "GPIO.h"
#include "atmega32_driver.h"
#include "GPIO.h"
#include "KEYBAD.h"
#include "LCD.h"
#define  F_CPU 1000000UL
#include <util/delay.h>
#include "UART.h"
#include "SPI.h"


int main (void)
{ 
	SPI_Master_Init();
	GPIO_DDRA = 0xFF;
	uint8_t data;
	for (data=0; data<= 255; data++)
	{
		_delay_ms(1000);
		 GPIO_PORTA = SPI_Master_Transmit(data) ;
		
	}




	return 0;
}
