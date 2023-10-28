/*
 * main.c
 *
 * Created: 10/28/2023 11:35:17 AM
 *  Author: Abdelrahman
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t state=0;
int main(void)
{
	/* Replace with your application code */
	DDRC |= (15<<PC0);
	PORTC&=~(15<<PC0);

	MCUCR |= (1<<ISC01);
	GICR |= (1<<INT0);
	SREG |=(1<<PC7);

	DDRD &=~(1<<PD2);
	PORTD |=(1<<PD2);
	
	// set INT0 ANY CAHANGE and INT1 for raising
	MCUCR |= 0b01101<<0;
	
	// set INT2 for falling 
	MCUCSR &= ~(0<<6);
	// Enable INT0,1,2
	GICR |= 0b111<<5;
	
	// global interrupt enable
	SREG |= 1<<7;
	
	
	sei();
	while (1)
	{
			PORTD |= 1<<7;
		if (state==1)
		{
			_delay_ms(1000);
			if (state==1)
			{
				PORTC--;
				state=0;
			}
		}
	}
}

ISR(INT0_vect)
{
	PORTD |= 1<<7;
	_delay_ms(100);
	PORTD &= ~(1<<7);
	_delay_ms(100);
	GIFR |= 1<<6;
	}



ISR(INT1_vect)
{
	PORTD |= 1<<7;
	_delay_ms(100);
	PORTD &= ~(1<<7);
	_delay_ms(100);
	GIFR |= 1<<7;
}


ISR(INT2_vect)
{
	PORTD |= 1<<7;
	_delay_ms(100);
	PORTD &= ~(1<<7);
	_delay_ms(100);
	GIFR |= 1<<5;
}



