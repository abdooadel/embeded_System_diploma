#include "GPIO.h"
#include "atmega32_driver.h"
#include "GPIO.h"
#include "KEYBAD.h"
#define  F_CPU 1000000UL
#include "LCD.h"
#include <util/delay.h>
#include "UART.h"
#include "SPI.h"
 
#include <asf.h>

int main (void)
{
	
SPI_Slave_Init();
GPIO_DDRA = 0xFF;
uint8_t data;

for (data=0; data <= 255; data++)
{
	_delay_ms(1000);
	GPIO_PORTA= SPI_Slave_Recieve(data) ;
}

	GPIO_PORTA=0xFF;


}
