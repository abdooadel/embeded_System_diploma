/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman Elshahat
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "Stm32_F103C6_GPIO_drivers.h"
#include "Stm32f103x6.h"
#include "Stm32_F103C6_USART_drivers.h"
#include "Stm32_F103C6_SPI_drivers.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define MCU_Act_As_Master
//#define MCU_Act_As_Slave




uint16_t data;

void USART_IRQ(void)
{

#ifdef MCU_Act_As_Master

	MCAL_USART_RecieveData(USART1, &data, disable);
	MCAL_USART_SendData(USART1, &data, enable);

	//Send data to SPI

	//OUTPUT HIGH on SS PIN PA4
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	MCAL_SPI_Tx_Rx(SPI1, &data, SPI_enable);

	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

#endif

}

void SPI_IRQ(struct S_IRQ_Source SRC)
{
#ifdef MCU_Act_As_Slave
	if (SRC.RXNEIE)
	{
		MCAL_SPI_Tx_Rx(SPI1, &data, SPI_enable);
		MCAL_USART_SendData(USART1, &data, enable);
	}

#endif
}

int main(void)
{
	// Enable PortA and PortB clocks
	RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOB_CLK_ENABLE();
	RCC_AFIO_CLK_ENABLE();

	//UART Configure
	USART_Config UART_confg;
	UART_confg.Baudrate= USART_BaudRate_115200;
	UART_confg.HwFlowControl= USART_HwFlowControl_None;
	UART_confg.IRQ_Enable= USART_IRQ_Enable_RXNE;
	UART_confg.P_IRQ_CallBack= USART_IRQ;
	UART_confg.Parity= USART_Parity_Disable;
	UART_confg.Payload_length= USART_Payload_length_8bit;
	UART_confg.StopBits= USART_StopBits_1Bit;
	UART_confg.USART_Mode= USART_Mode_Tx_Rx;
	MCAL_USART_Init(USART1, &UART_confg);
	MCAL_USART_GPIO_SetPins(USART1);

	//SPI Configure
	SPI_Config SPI1_Confg;

	// Common configuration
	SPI1_Confg.CLK_Phase = SPI_CLK_Phase_Second_Edge;
	SPI1_Confg.CLK_Polarity= SPI_CLK_Polarity_HIGH;
	SPI1_Confg.Data_Size= SPI_Data_Size_8_Bits;
	SPI1_Confg.Frame_Format= SPI_Frame_Format_MSB;
	SPI1_Confg.BaudRatePrescaler= SPI_BaudRatePrescaler_8;
	SPI1_Confg.Communication_Mode= SPI_Communication_Mode_2LIN;

#ifdef MCU_Act_As_Master
	SPI1_Confg.Device_Mode= SPI_Device_Mode_Master;
	SPI1_Confg.IRQ_Enable= SPI_IRQ_Enable_None;
	SPI1_Confg.NSS= SPI_NSS_SW_SET;
	SPI1_Confg.P_IRQ_CallBack=NULL;

	MCAL_SPI_Init(SPI1, &SPI1_Confg);
	MCAL_SPI_GPIO_SetPins(SPI1);

	// Configure SS on PA4 by GPIO
	GPIO_PinConfig_t GPIO_CFG;
	GPIO_CFG.GPIO_Mode= GPIO_MODE_OUTPUT_PP;
	GPIO_CFG.GPIO_Output_Speed= GPPIO_SPEED_10M;
	GPIO_CFG.GPIO_PinNumber= GPIO_PIN_4;
	MCAL_GPIO_Init(GPIOA, &GPIO_CFG);


	//OUTPUT HIGH on SS PIN PA4
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

#endif

#ifdef MCU_Act_As_Slave

	SPI1_Confg.Device_Mode= SPI_Device_Mode_Slave;
	SPI1_Confg.NSS= SPI_NSS_HW_Slave;
	SPI1_Confg.IRQ_Enable= SPI_IRQ_Enable_RXNEIE;
	SPI1_Confg.P_IRQ_CallBack=SPI_IRQ;

	MCAL_SPI_Init(SPI1, &SPI1_Confg);
	MCAL_SPI_GPIO_SetPins(SPI1);
#endif








	while(1)
	{


	}
}
