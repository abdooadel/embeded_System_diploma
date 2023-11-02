/*
 * atmega32_driver.h
 *
 * Created: 10/31/2023 10:26:44 AM
 *  Author: abdoo
 */ 


#ifndef ATMEGA32_DRIVER_H_
#define ATMEGA32_DRIVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define F_CPU 1000000UL

// GPIO MEMORY MAP

#define	GPIO_PORTA		 *((volatile uint8_t*) (0x3b))
#define	GPIO_DDRA		 *((volatile uint8_t*) (0x3A))
#define GPIO_PINA		 *((volatile uint8_t*) (0x39))

#define	GPIO_PORTB		 *((volatile uint8_t*) (0x38))
#define	GPIO_DDRB		 *((volatile uint8_t*) (0x37))
#define GPIO_PINB		 *((volatile uint8_t*) (0x36))

#define	GPIO_PORTC		 *((volatile uint8_t*) (0x35))
#define	GPIO_DDRC		 *((volatile uint8_t*) (0x34))
#define GPIO_PINC		 *((volatile uint8_t*) (0x33))

#define	GPIO_PORTD		 *((volatile uint8_t*) (0x32))
#define	GPIO_DDRD		 *((volatile uint8_t*) (0x31))
#define GPIO_PIND		 *((volatile uint8_t*) (0x30))



#define PORTA	0x3b
#define PORTB	0x38
#define PORTC	0x35
#define PORTD	0x32



// UART MEMORY MAP

#define UART_UBRRL			*((volatile uint8_t*) (0x29))
#define UART_UCSRA			*((volatile uint8_t*) (0x2B))
#define UART_UCSRB			*((volatile uint8_t*) (0x2A))
#define UART_UBRRH			*((volatile uint8_t*) (0x40))
#define UART_UCSRC			*((volatile uint8_t*) (0x40))
#define UART_UCSRB			*((volatile uint8_t*) (0x2A))
#define UART_UDR			*((volatile uint8_t*) (0x2C))
#define UART_UCSRA			*((volatile uint8_t*) (0x2B))
 




// SPI MEMORY MAP

#define SPI_SPDR			*((volatile uint8_t*) (0x2F))
#define SPI_SPSR			*((volatile uint8_t*) (0x2E))
#define SPI_SPCR			*((volatile uint8_t*) (0x2D))



#endif /* ATMEGA32_DRIVER_H_ */