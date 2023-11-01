/*
 * SPI.c
 *
 * Created: 11/1/2023 1:52:01 PM
 *  Author: abdoo
 */ 

#include "SPI.h"




void SPI_Master_Init(void)
{
	GPIO_PinConfig_t *PinConfig;
	PinConfig->Pin_Number = SPI_MOSI;
	PinConfig->mode = GPIO_MODE_OUTPUT;
	MCAL_GPIO_Init(SPI_MASTER_PORT,PinConfig);
	PinConfig->Pin_Number = SPI_CLK;
	PinConfig->mode = GPIO_MODE_OUTPUT;
	MCAL_GPIO_Init(SPI_MASTER_PORT,PinConfig);
	PinConfig->Pin_Number = SPI_SS;
	PinConfig->mode = GPIO_MODE_OUTPUT;
	MCAL_GPIO_Init(SPI_MASTER_PORT,PinConfig);

	
	//Select Master 
	SPI_SPCR |= 1<<4;
	
	// configure clock to be divided by 64
		SPI_SPCR |= 0b1<<0;
	//	SPI_SPSR |= 1<<0;

	//Enable SPI
	SPI_SPCR |= 1<<6;
	
	
	
}


void SPI_Slave_Init(void)
{
	volatile GPIO_PinConfig_t *PinConfig;
	PinConfig->Pin_Number = SPI_MISO;
	PinConfig->mode = GPIO_MODE_OUTPUT ;
	MCAL_GPIO_Init(SPI_SLAVE_PORT, PinConfig);

	
	//Select SLAVE
	SPI_SPCR &= ~(1<<4);
	
	// configure clock to be divided by 64
	//SPI_SPCR |= 0b11<<0;
	//SPI_SPSR |= 1<<0;
		//Enable SPI
		SPI_SPCR |= 1<<6;
	
}


uint8_t SPI_Master_Transmit(uint8_t data)
{
	SPI_SPDR = data;
	while( !(SPI_SPSR & 1<<7));
	return SPI_SPDR;
}

uint8_t SPI_Slave_Recieve(uint8_t data)
{
	SPI_SPDR = data;
	while(! (SPI_SPSR & 1<<7));
	return SPI_SPDR;
}