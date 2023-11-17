/*
 * Stm32_F103C6_USART_drivers.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Abdelrahman Elshahat
 */

#include "Stm32_F103C6_USART_drivers.h"


USART_Config * Global_UART_Config=NULL;





/**================================================================
 * @Fn			-MCAL_USART_Init
 * @brief 		-Initialize USART
 * @param [in] 	- USARTx : where x can be (1,2,3)
 * @param [in] 	- UART_Config : All USART configuration
 * @retval 		-none
 * Note			-
 */
void MCAL_USART_Init(USART_TypeDef *USARTx ,USART_Config *UART_Config)
{

	uint32_t PCLK;
	Global_UART_Config= UART_Config;

	//Enable UART CLOCK for given USART

	if (USARTx == USART1)
		RCC_USART1_CLK_ENABLE();

	else if (USARTx == USART2)
		RCC_USART2_CLK_ENABLE();

	else if(USARTx == USART3)
		RCC_USART3_CLK_ENABLE();

	//Enable USART module
	//CR1 Bit 13 UE: USART enable
	USARTx->CR1 |= 1<<13;


	//Enable USART Tx and Rx  according to USART configration mode
	//CR1 Bit 3 TE: Transmitter enable & Bit 2 RE: Receiver enable
	USARTx->CR1 |= UART_Config->USART_Mode;


	//Payload  length
	//CR1 Bit 12 M: Word length
	USARTx->CR1 |= UART_Config->Payload_length;


	//Configure parirty Mode
	//CR1 Bit 10 PCE: Parity control enable & Bit 9 PS: Parity selection
	USARTx->CR1 |= UART_Config->Parity;



	//Configure Stop Bits
	//CR2 Bits 13:12 STOP: STOP bits
	USARTx->CR2 |= UART_Config->StopBits;


	//Configure Flow contol
	//CR3 Bit 9 CTSE: CTS enable &  Bit 8 RTSE: RTS enable
	USARTx->CR3 |= UART_Config->HwFlowControl;


	//Configuration of UART BRR(Baudrate register)
	if (USARTx == USART1)
		PCLK= MCAL_RCC_GetPLCK2Freq();

	else
		PCLK= MCAL_RCC_GetPLCK1Freq();

	USARTx->BRR = USART_BRR_Register(PCLK, UART_Config->Baudrate );



	//Enable / Disable IRQ
	//CR1 Bit 4 IDLEIE: IDLE interrupt enable
	if (UART_Config->IRQ_Enable != USART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |= UART_Config->IRQ_Enable;

		//Enable NVIC for USART IRQ
		if (USARTx == USART1)
			NVIC_IRQ37_USART1_Enable;

		else if (USARTx == USART2)
			NVIC_IRQ38_USART2_Enable;

		else if(USARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}

}





/**================================================================
 * @Fn			-MCAL_USART_DeInit
 * @brief 		-Deinitialize USART
 * @param [in] 	- USARTx : where x can be (1,2,3)
 * @retval 		-none
 * Note			-
 */


void MCAL_USART_DeInit(USART_TypeDef *USARTx )
{

	if (USARTx == USART1)
	{
		NVIC_IRQ37_USART1_Disable;
		RCC_USART1_Reset();
	}
	else if (USARTx == USART2)
	{
		NVIC_IRQ38_USART2_Disable;
		RCC_USART2_Reset();
	}
	else if(USARTx == USART3)
	{
		NVIC_IRQ39_USART3_Disable;
		RCC_USART3_Reset();
	}

}






/**================================================================
 * @Fn			-MCAL_USART_SendData
 * @brief 		-USART send data
 * @param [in] 	-USARTx : where x can be (1,2,3)
 * @param [in] 	-pTxBuffer : Buffer where data to be sent is stored
 * @param [in] 	-Polling_mechanism : choose if booling mechanism is enabled or disabled
 *
 * @retval 		-none
 * Note			-
 */

void MCAL_USART_SendData(USART_TypeDef *USARTx ,uint16_t *pTxBuffer, enum Polling_mechanism PollingEn)
{

	// check if Polling mechanism is enabled or not
	if (PollingEn == enable)
		while(!(USARTx->SR & 1<<7));

	// check if the data length is 8 bits or 9 bits

	//	When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
	//	the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
	//	because it is replaced by the parity.
	//	When receiving with the parity enabled, the value read in the MSB bit is the received parity bit.

	if (Global_UART_Config->Payload_length == USART_Payload_length_9bit)
	{
		USARTx->DR= (*pTxBuffer & (uint16_t)0x01FF);
	}
	else
	{
		USARTx->DR= (uint16_t)(*pTxBuffer & (uint16_t)0xFF);
	}



}



/**================================================================
 * @Fn			-MCAL_USART_TC
 * @brief 		-checks if the Transmission is complete or not
 * @param [in] 	-USARTx : where x can be (1,2,3)
 * @retval 		-none
 * Note			-
 */
void MCAL_USART_TC(USART_TypeDef *USARTx )
{
	while(!(USARTx->SR & 1<<6));
}






/**================================================================
 * @Fn			-MCAL_USART_RecieveData
 * @brief 		-USART recieve data
 * @param [in] 	-USARTx : where x can be (1,2,3)
 * @param [in] 	-pTxBuffer : Buffer where data to be recieved is stored
 * @param [in] 	-Polling_mechanism : choose if booling mechanism is enabled or disabled
 *
 * @retval 		-none
 * Note			-
 */

void MCAL_USART_RecieveData(USART_TypeDef *USARTx ,uint16_t *pTxBuffer, enum Polling_mechanism PollingEn)
{

	// check if Polling mechanism is enabled or not
	if (PollingEn == enable)
		while(!(USARTx->SR & 1<<5));

	// check if the data length is 8 bits or 9 bits
	if (Global_UART_Config->Payload_length == USART_Payload_length_9bit)
	{
		if (Global_UART_Config->Parity == USART_Parity_Disable)
		{
			*pTxBuffer= (USARTx->DR &  (uint16_t) 0x01FF);
		}
		else
		{
			//parity is used so the 9th bit is parity
			*pTxBuffer= (USARTx->DR &  (uint16_t) 0xFF);
		}
	}
	else
	{
		if (Global_UART_Config->Parity == USART_Parity_Disable)
		{
			*pTxBuffer= (USARTx->DR &  (uint16_t) 0xFF);
		}
		else
		{
			//parity is used so the 8th bit is parity
			*pTxBuffer= (USARTx->DR &  (uint16_t) 0x7F);
		}
	}



}




/**================================================================
 * @Fn			-MCAL_USART_GPIO_SetPins
 * @brief 		-initialize GPIO PINS
 * @param [in] 	-USARTx : where x can be (1,2,3)
 * @retval 		-none
 * Note			-
 */
void MCAL_USART_GPIO_SetPins(USART_TypeDef *USARTx)
{

	GPIO_PinConfig_t GPIO_PinConfig;
	if (USARTx == USART1)
	{
		//PA9  	Tx
		//PA10	Rx
		//PA11	CTS
		//PA12	RTS


		//PA9  	Tx
		GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_9;
		GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_OUTPUT_PP;
		GPIO_PinConfig.GPIO_Output_Speed= GPPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &GPIO_PinConfig);

		//PA10  Rx
		GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_10;
		GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &GPIO_PinConfig);

		//check if the CTS is enabled or not
		if(Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS || Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS_RTS)
		{
			//PA11	CTS
			GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_11;
			GPIO_PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &GPIO_PinConfig);
		}

		//check if the RTS is enabled or not
		if(Global_UART_Config->HwFlowControl== USART_HwFlowControl_RTS || Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS_RTS)
		{
			//PA12	RTS
			GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_12;
			GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_OUTPUT_PP;
			GPIO_PinConfig.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &GPIO_PinConfig);
		}
	}
	else if (USARTx == USART2)
	{

		//PA2  	Tx
		//PA3	Rx
		//PA0	CTS
		//PA1	RTS


		//PA2  	Tx
		GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_2;
		GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_OUTPUT_PP;
		GPIO_PinConfig.GPIO_Output_Speed= GPPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOA, &GPIO_PinConfig);

		//PA3  Rx
		GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_3;
		GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOA, &GPIO_PinConfig);

		//check if the CTS is enabled or not
		if(Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS || Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS_RTS)
		{
			//PA0	CTS
			GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_0;
			GPIO_PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &GPIO_PinConfig);
		}

		//check if the RTS is enabled or not
		if(Global_UART_Config->HwFlowControl== USART_HwFlowControl_RTS || Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS_RTS)
		{
			//PA1	RTS
			GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_1;
			GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_OUTPUT_PP;
			GPIO_PinConfig.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &GPIO_PinConfig);
		}

	}
	else if (USARTx == USART3)
	{

		//PB10  Tx
		//PB11	Rx
		//PB13	CTS
		//Pb14	RTS


		//PB10  Tx
		GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_10;
		GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_OUTPUT_PP;
		GPIO_PinConfig.GPIO_Output_Speed= GPPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &GPIO_PinConfig);

		//PB11  Rx
		GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_11;
		GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(GPIOB, &GPIO_PinConfig);

		//check if the CTS is enabled or not
		if(Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS || Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS_RTS)
		{
			//PB13	CTS
			GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_13;
			GPIO_PinConfig.GPIO_Mode = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &GPIO_PinConfig);
		}

		//check if the RTS is enabled or not
		if(Global_UART_Config->HwFlowControl== USART_HwFlowControl_RTS || Global_UART_Config->HwFlowControl== USART_HwFlowControl_CTS_RTS)
		{
			//Pb14	RTS
			GPIO_PinConfig.GPIO_PinNumber= GPIO_PIN_14;
			GPIO_PinConfig.GPIO_Mode = GPIO_MODE_AF_OUTPUT_PP;
			GPIO_PinConfig.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &GPIO_PinConfig);
		}

	}
}


void USART1_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack();
}

void USART2_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack();

}

void USART3_IRQHandler(void)
{
	Global_UART_Config->P_IRQ_CallBack();

}

