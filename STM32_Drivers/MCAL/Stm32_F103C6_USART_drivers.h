/*
 * Stm32_F103C6_USART_drivers.h
 *
 *  Created on: Oct 29, 2023
 *  Author: Abdelrahman Elshahat
 */

#ifndef GPIO_DRIVER_INC_STM32_F103C6_USART_DRIVERS_H_
#define GPIO_DRIVER_INC_STM32_F103C6_USART_DRIVERS_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_drivers.h"
#include "Stm32_F103C6_RCC_drivers.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------


typedef struct
{

	uint8_t 			USART_Mode;			  	//Specifies USART Tx/Rx Enable/Disable
												//Choose mode base on @ref USART_MODE_deine


	uint32_t			Baudrate;				//Specifies USART baudrate
												//Choose baudrate base on @ref USART_BaudRate_deine

	uint8_t				Payload_length;			//Specifies the number of data bits used in transmit and recieve
												//Choose Number of bits base on @ref USART_Payload_length_deine


	uint8_t				Parity;					//Specifies USART parity mode
												//Choose parity mode base on @ref USART_Parity_deine

	uint8_t				StopBits;				//Specifies the number of stop bits used in transmit and recieve
												//Choose Number of bits base on @ref USART_StopBits_deine


	uint8_t				HwFlowControl;			//Specifies the hardware flow control is enabled or disabled
												//Choose mode based on @ref USART_HwFlowControl_deine


	uint8_t				IRQ_Enable;				//Specifies USART interrupt is enabled or disabled
												//Choose which interrupt you want to enable from @ref USART_IRQ_Enable_deine


	void(* P_IRQ_CallBack)(void);				//Set the C Function which is needed to be called when the interrupt requested

}USART_Config;







//-----------------------------
//Macros Configuration References
//-----------------------------



//====================================
//@ref USART_Mode_define
#define USART_Mode_Tx					(uint32_t)(1<<3)
#define USART_Mode_Rx					(uint32_t)(1<<2)
#define USART_Mode_Tx_Rx				(uint32_t)(1<<2 | 1<<3)


//====================================
//@ref USART_BaudRate_deine
#define 	USART_BaudRate_2400						2400
#define 	USART_BaudRate_9600						9600
#define 	USART_BaudRate_19200					19200
#define 	USART_BaudRate_57600					57600
#define 	USART_BaudRate_115200					115200
#define 	USART_BaudRate_230400					230400
#define 	USART_BaudRate_460800					460800
#define 	USART_BaudRate_921600					921600
#define 	USART_BaudRate_2250000					2250000
#define 	USART_BaudRate_4500000					4500000





//====================================
//@ref USART_Payload_length_deine
#define		USART_Payload_length_8bit				(uint32_t)(0)
#define		USART_Payload_length_9bit				(uint32_t)(1<<12)



//====================================
//@ref USART_Parity_deine
#define 	USART_Parity_Disable	     			(uint32_t)(0)
#define 	USART_Parity_EVEN						(uint32_t)(1<<10)
#define 	USART_Parity_ODD						(uint32_t)(1<<10 | 1<<9  )


//====================================
//@ref USART_StopBits_deine
#define		USART_StopBits_Half_Bit					(uint32_t)(1<<12)
#define		USART_StopBits_1Bit						(uint32_t)(0)
#define		USART_StopBits_1_half_Bit				(uint32_t)(3<<12)
#define		USART_StopBits_2Bit						(uint32_t)(2<<12)



//====================================
//@ref USART_HwFlowControl_deine
#define 	USART_HwFlowControl_None				(uint32_t)(0)
#define 	USART_HwFlowControl_RTS					(uint32_t)(1<<8)
#define 	USART_HwFlowControl_CTS					(uint32_t)(1<<9)
#define 	USART_HwFlowControl_CTS_RTS				(uint32_t)(1<<8 | 1<<9)




//====================================
//@ref USART_IRQ_Enable_deine
#define 	USART_IRQ_Enable_NONE					(uint32_t)(0)
#define 	USART_IRQ_Enable_TXE					(uint32_t)(1<<7)	//Transmit data register empty
#define 	USART_IRQ_Enable_TC						(uint32_t)(1<<6)	//Transmit complete
#define 	USART_IRQ_Enable_RXNE					(uint32_t)(1<<5)	//Received data ready to read
#define 	USART_IRQ_Enable_PE						(uint32_t)(1<<8)	//Parity error



enum Polling_mechanism
{
	enable,
	disable
};




//USART Baudrate Calculations
//USARTDIV= fclk/ (16*Baudrate)
//USARTDIV_MUL100= (100*fclk)/ (16*Baudrate)= (25*fclk)/ (4*Baudrate)
//DIV_Mentissa = Integeer Part of USARTDIV
//DIV_Fraction= ((USARTDIV_MUL100 - DIV_Mentissa*100)*16)/100

#define USARTDIV(_PCLK_, _BAUD_)						(uint32_t) (_PCLK_/(16*_BAUD_))
#define USARTDIV_MUL100(_PCLK_,_BAUD_ )					(uint32_t) ((25*_PCLK_) / (4*_BAUD_))
#define Mantisaa_MUL100(_PCLK_,_BAUD_ )					(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantisaa(_PCLK_,_BAUD_ )						(uint32_t) (USARTDIV(_PCLK_, _BAUD_) )
#define DIV_Fraction(_PCLK_,_BAUD_ )					(uint32_t) ( ((USARTDIV_MUL100(_PCLK_,_BAUD_ ) - Mantisaa_MUL100(_PCLK_,_BAUD_ ))*16 )  / 100 )
#define USART_BRR_Register(_PCLK_,_BAUD_ )				( (Mantisaa(_PCLK_,_BAUD_ ) <<4) | (DIV_Fraction(_PCLK_,_BAUD_ )&0b1111))






/*
 * ===============================================
 * APIs Supported by "MCAL USART DRIVER"
 * ===============================================
 */

void MCAL_USART_Init(USART_TypeDef *USARTx ,USART_Config *UART_Config);
void MCAL_USART_DeInit(USART_TypeDef *USARTx );

void MCAL_USART_GPIO_SetPins(USART_TypeDef *USARTx);

void MCAL_USART_SendData(USART_TypeDef *USARTx ,uint16_t *pTxBuffer, enum Polling_mechanism PollingEn);

void MCAL_USART_RecieveData(USART_TypeDef *USARTx ,uint16_t *pTxBuffer, enum Polling_mechanism PollingEn);

void MCAL_USART_TC(USART_TypeDef *USARTx );





#endif
