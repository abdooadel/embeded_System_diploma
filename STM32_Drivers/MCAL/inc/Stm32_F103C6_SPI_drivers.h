/*
 * Stm32_F103C6_SPI_drivers.h
 *
 *  Created on: NOV 18, 2023
 *  Author: Abdelrahman Elshahat
 */

#ifndef GPIO_DRIVER_INC_STM32_F103C6_SPI_DRIVERS_H_
#define GPIO_DRIVER_INC_STM32_F103C6_SPI_DRIVERS_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_drivers.h"
#include "Stm32_F103C6_RCC_drivers.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

//define interrupt source
struct S_IRQ_Source
{
	uint8_t		RXNEIE:1;
	uint8_t		TXEIE:1;
	uint8_t		ERRIE:1;
	uint8_t		reserved:5;

};



typedef struct
{

	uint16_t		Device_Mode;					//Specifies the SPI Operating modes Master or Slave
													//Choose mode from @ref SPI_Device_Mode_define

	uint16_t		Communication_Mode;				//Specifies the SPI Communication Mode BI or UNIdirectional
													//Choose mode from @ref SPI_Communication_Mode_define

	uint16_t		Frame_Format;					//Specifies the SPI frame format MSB first or LSB first
													//Choose format from @ref SPI_Frame_Format_define

	uint16_t		Data_Size;						//Specifies the SPI data size 8 bits or 16 bits
													//Choose size from @ref SPI_Data_Size_define

	uint16_t		CLK_Polarity;					//Specifies the SPI clock polarity 0 Idle or 1 Idle
													//Choose size from @ref SPI_CLK_Polarity_define

	uint16_t		CLK_Phase;						//Specifies the SPI clock phase first Edge or Second Edge
													//Choose size from @ref SPI_CLK_Phase_define


	uint16_t		NSS;							//Specifies whether the NSS is managed by HW or SW
													//Choose size from @ref SPI_NSS_define


	uint16_t		BaudRatePrescaler;				//Specifies SPI baud rate prescaler FCLK/2, 4, 8, 16, 32, 64 or 256
													//Choose prescaler from @ref SPI_BaudRatePrescaler_define

	uint16_t		IRQ_Enable;						//Specifies SPI interrupt mask enable or disable
													//Choose mode from @ref SPI_IRQ_Enable_define

	void(* P_IRQ_CallBack)(struct S_IRQ_Source);	//Pointer to C function that is handled by interrupt service routine




}SPI_Config;







//-----------------------------
//Macros Configuration References
//-----------------------------



//====================================
//@ref SPI_Device_Mode_define
//Bit 2 MSTR: Master selection
#define		SPI_Device_Mode_Master						(uint32_t)(1<<2)
#define		SPI_Device_Mode_Slave						(uint32_t)(0)


//====================================
//@ref SPI_Communication_Mode_define
//Bit 15 BIDIMODE: Bidirectional data mode enable
#define		SPI_Communication_Mode_2LIN					(uint32_t)(0)
#define		SPI_Communication_Mode_2LIN_RECIEVE			(uint32_t)(1<<10)
#define		SPI_Communication_Mode_1LIN_RECIEVE			(uint32_t)(1<<15)
#define		SPI_Communication_Mode_2LIN_TRANSMIT		(uint32_t)(1<<15 | 1<<14)


//====================================
//@ref SPI_Frame_Format_define
//Bit 7 LSBFIRST: Frame format
#define		SPI_Frame_Format_MSB						(uint32_t)(0)
#define		SPI_Frame_Format_LSB						(uint32_t)(1<<7)


//====================================
//@ref SPI_Data_Size_define
//Bit 11 DFF: Data frame format
#define		SPI_Data_Size_8_Bits						(uint32_t)(0)
#define		SPI_Data_Size_16_Bits					(uint32_t)(1<<11)


//====================================
//@ref SPI_CLK_Polarity_define
//Bit1 CPOL: Clock polarity
#define		SPI_CLK_Polarity_LOW						(uint32_t)(0)
#define		SPI_CLK_Polarity_HIGH						(uint32_t)(1<<1)


//====================================
//@ref SPI_CLK_Phase_define
//Bit 0 CPHA: Clock phase
#define		SPI_CLK_Phase_First_Edge					(uint32_t)(0)
#define		SPI_CLK_Phase_Second_Edge					(uint32_t)(1<<0)



//====================================
//@ref SPI_NSS_define
//Bit 9 SSM: Software slave management
#define		SPI_NSS_HW_Slave							(uint32_t)(0)
#define		SPI_NSS_HW_Master_SS_Output					(uint32_t)(1<<2)   //SPI CR2.Bit 2 enable output
#define		SPI_NSS_HW_Master_SS_Input					(uint32_t)(0)		//SPI CR2.Bit 2 disable output

#define		SPI_NSS_SW_SET								(uint32_t)(1<<9 | 1<<8) //output 1 by software on CR1.Bit 8
#define		SPI_NSS_SW_RESET							(uint32_t)(1<<9 ) //output 0 by software on CR1.Bit 8


//====================================
//@ref SPI_BaudRatePrescaler_define
//Bits 5:3 BR[2:0]: Baud rate control
#define		SPI_BaudRatePrescaler_2						(uint32_t)(0b000 <<3)
#define		SPI_BaudRatePrescaler_4						(uint32_t)(0b001 <<3)
#define		SPI_BaudRatePrescaler_8						(uint32_t)(0b010 <<3)
#define		SPI_BaudRatePrescaler_16					(uint32_t)(0b011 <<3)
#define		SPI_BaudRatePrescaler_32					(uint32_t)(0b100 <<3)
#define		SPI_BaudRatePrescaler_64					(uint32_t)(0b101 <<3)
#define		SPI_BaudRatePrescaler_128					(uint32_t)(0b110 <<3)
#define		SPI_BaudRatePrescaler_256					(uint32_t)(0b111 <<3)



//====================================
//@ref SPI_IRQ_Enable_define
#define		SPI_IRQ_Enable_None							(uint32_t)(0)
#define		SPI_IRQ_Enable_TXEIE						(uint32_t)(1<<7) //Tx buffer empty interrupt enable
#define		SPI_IRQ_Enable_RXNEIE						(uint32_t)(1<<6) //RX buffer not empty interrupt enable
#define		SPI_IRQ_Enable_ERRIE						(uint32_t)(1<<5) //Error interrupt enable





enum SPI_PollingMech
{
	SPI_enable,
	SPI_disable
};


/*
 * ===============================================
 * APIs Supported by "MCAL SPI DRIVER"
 * ===============================================
 */

void MCAL_SPI_Init(SPI_TypeDef *SPIx, SPI_Config *SPI_Confg);
void MCAL_SPI_DeInit(SPI_TypeDef *SPIx);

void MCAL_SPI_GPIO_SetPins(SPI_TypeDef *SPIx);

void MCAL_SPI_SendData(SPI_TypeDef *SPIx,uint16_t *pTxBuffer, enum SPI_PollingMech Polling_En);
void MCAL_SPI_RecieveData(SPI_TypeDef *SPIx,uint16_t *pRxBuffer, enum SPI_PollingMech Polling_En);

void MCAL_SPI_Tx_Rx(SPI_TypeDef *SPIx,uint16_t *pTxRxBuffer, enum SPI_PollingMech Polling_En);





#endif
