/*
 * SPI.h
 *
 * Created: 11/1/2023 1:52:16 PM
 *  Author: abdoo
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "GPIO.h"
#include "atmega32_driver.h"

#define SPI_SS		GPIO_PIN_4
#define SPI_MOSI	GPIO_PIN_5
#define SPI_MISO	GPIO_PIN_6
#define SPI_CLK		GPIO_PIN_7

#define SPI_MASTER_PORT			PORTB
#define SPI_SLAVE_PORT			PORTB

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
uint8_t SPI_Master_Transmit(uint8_t data);
uint8_t SPI_Slave_Recieve(uint8_t data);


#endif /* SPI_H_ */