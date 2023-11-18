/*
 * Stm32_F103C6_SPI_drivers.c
 *
 *  Created on: NOV 18, 2023
 *      Author: Abdelrahman Elshahat
 */

#include "Stm32_F103C6_SPI_drivers.h"

SPI_Config* Globale_SPI_Confg[]={NULL, NULL};





/**================================================================
 * @Fn			-MCAL_SPI_Init
 * @brief 		-Initialize SPI
 * @param [in] 	- SPIx : where x can be (1,2)
 * @param [in] 	- SPI_Config : All SPI configuration
 * @retval 		-none
 * Note			-
 */

void MCAL_SPI_Init(SPI_TypeDef *SPIx, SPI_Config *SPI_Confg)
{
	//Safety for registers
	uint16_t temp_CR1=0;
	uint16_t temp_CR2=0;

	//enable clock and save global variable according to used SPI 1 or 2
	if (SPIx == SPI1)
	{

		Globale_SPI_Confg[0]=SPI_Confg;
		RCC_SPI1_CLK_ENABLE();

	}
	else if (SPIx == SPI2)
	{
		Globale_SPI_Confg[1]=SPI_Confg;
		RCC_SPI2_CLK_ENABLE();

	}

	//CR1 Bit 6 SPE: SPI enable
	temp_CR1 |= 1<<6;

	//Master or Slave
	temp_CR1 |= SPI_Confg->Device_Mode ;

	//SPI Communication Mode
	temp_CR1 |= SPI_Confg->Communication_Mode;

	//SPI Frame Format
	temp_CR1 |= SPI_Confg->Frame_Format;

	//SPI Data size
	temp_CR1 |= SPI_Confg->Data_Size;

	//SPI Clock Polarity
	temp_CR1 |= SPI_Confg->CLK_Polarity;

	//SPI Clock Phase
	temp_CR1 |= SPI_Confg->CLK_Phase;

	//NSS
	if ( SPI_Confg->NSS == SPI_NSS_HW_Master_SS_Output   )
	{
		temp_CR2 |= SPI_Confg->NSS;
	}
	else if (SPI_Confg->NSS == SPI_NSS_HW_Master_SS_Input )
	{
		temp_CR1 &= ~ SPI_Confg->NSS;

	}
	else
	{
		temp_CR1 |= SPI_Confg->NSS;

	}

	//SPI Baud rate
	temp_CR1 |= SPI_Confg->BaudRatePrescaler;

	//SPI Interrupt Request
	if (SPI_Confg->IRQ_Enable != SPI_IRQ_Enable_None)
	{
		temp_CR2 |= SPI_Confg->IRQ_Enable;

		if (SPIx == SPI1)
		{

			NVIC_IRQ35_SPI1_Enable;
		}
		else if (SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_Enable;
		}


	}


	SPIx->CR1= temp_CR1;
	SPIx->CR2= temp_CR2;

}




/**================================================================
 * @Fn			-MCAL_SPI_DeInit
 * @brief 		-Deinitialize SPI
 * @param [in] 	- SPIx : where x can be (1,2)
 * @retval 		-none
 * Note			-
 */
void MCAL_SPI_DeInit(SPI_TypeDef *SPIx)
{
	if (SPIx == SPI1)
	{

		RCC_SPI1_RESET();
		NVIC_IRQ35_SPI1_Disable;
	}
	else if (SPIx == SPI2)
	{
		RCC_SPI2_RESET();
		NVIC_IRQ36_SPI2_Disable;
	}
}



/**================================================================
 * @Fn			-MCAL_SPI_SendData
 * @brief 		-SPI send data
 * @param [in] 	-SPIx : where x can be (1,2)
 * @param [in] 	-pTxBuffer : Buffer where data to be sent is stored
 * @param [in] 	-Polling_mechanism : choose if Poling mechanism is enabled or disabled
 *
 * @retval 		-none
 * Note			-
 */
void MCAL_SPI_SendData(SPI_TypeDef *SPIx,uint16_t *pTxBuffer, enum SPI_PollingMech Polling_En)
{
	if (Polling_En == SPI_enable)
	{
		while (! (SPIx->SR & (1<<1) ));
	}
	SPIx->DR= *pTxBuffer;

}


/**================================================================
 * @Fn			-MCAL_SPI_RecieveData
 * @brief 		-SPI receive data
 * @param [in] 	-SPIx : where x can be (1,2)
 * @param [in] 	-pTxBuffer : Buffer where data to be receive is stored
 * @param [in] 	-Polling_mechanism : choose if Poling mechanism is enabled or disabled
 *
 * @retval 		-none
 * Note			-
 */
void MCAL_SPI_RecieveData(SPI_TypeDef *SPIx,uint16_t *pRxBuffer, enum SPI_PollingMech Polling_En)
{


	if (Polling_En == SPI_enable)
	{
		while (! (SPIx->SR & (1<<0) ));
	}

	*pRxBuffer = SPIx->DR;

}


/**================================================================
 * @Fn			-MCAL_SPI_Tx_Rx
 * @brief 		-SPI send and receive data in the same time
 * @param [in] 	-SPIx : where x can be (1,2)
 * @param [in] 	-pTxBuffer : Buffer where data to be send and receive is stored
 * @param [in] 	-Polling_mechanism : choose if Poling mechanism is enabled or disabled
 *
 * @retval 		-none
 * Note			-
 */
void MCAL_SPI_Tx_Rx(SPI_TypeDef *SPIx,uint16_t *pTxRxBuffer, enum SPI_PollingMech Polling_En)
{
	if (Polling_En == SPI_enable)
	{
		while (! (SPIx->SR & (1<<1) ));
	}
	SPIx->DR= *pTxRxBuffer;

	if (Polling_En == SPI_enable)
	{
		while (! (SPIx->SR & (1<<0) ));
	}
	*pTxRxBuffer = SPIx->DR;





}


/**================================================================
 * @Fn			-MCAL_SPI_GPIO_SetPins
 * @brief 		-initialize GPIO PINS
 * @param [in] 	-SPIx : where x can be (1,2)
 * @retval 		-none
 * Note			-
 */
void MCAL_SPI_GPIO_SetPins(SPI_TypeDef *SPIx)
{

	GPIO_PinConfig_t PinConfg;

	if (SPIx == SPI1)
	{
		//SPI1 MOSI		PA7
		//SPI1 MISO		PA6
		//SPI1 CLK		PA5
		//SPI1 NSS		PA4

		if (Globale_SPI_Confg[0]->Device_Mode == SPI_Device_Mode_Master)
		{
			//SPI1 NSS		PA4
			PinConfg.GPIO_PinNumber= GPIO_PIN_4;
			switch(Globale_SPI_Confg[0]->NSS)
			{
			case SPI_NSS_HW_Master_SS_Output:
				PinConfg.GPIO_Mode= GPIO_MODE_AF_OUTPUT_PP;
				PinConfg.GPIO_Output_Speed= GPPIO_SPEED_10M;
				break;


			case SPI_NSS_HW_Master_SS_Input:
				PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
				break;
			}
			MCAL_GPIO_Init(GPIOA, &PinConfg);


			//SPI1 CLK		PA5
			PinConfg.GPIO_PinNumber= GPIO_PIN_5;
			PinConfg.GPIO_Mode= GPIO_MODE_AF_OUTPUT_PP;
			PinConfg.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfg);

			//SPI1 MISO		PA6
			PinConfg.GPIO_PinNumber= GPIO_PIN_6;
			PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfg);


			//SPI1 MOSI		PA7
			PinConfg.GPIO_PinNumber= GPIO_PIN_7;
			PinConfg.GPIO_Mode= GPIO_MODE_AF_OUTPUT_PP;
			PinConfg.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfg);


		}
		else
		{
			if (Globale_SPI_Confg[0]->NSS == SPI_NSS_HW_Slave)
			{
				//SPI1 NSS		PA4
				PinConfg.GPIO_PinNumber= GPIO_PIN_4;
				PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &PinConfg);
			}

			//SPI1 CLK		PA5
			PinConfg.GPIO_PinNumber= GPIO_PIN_5;
			PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfg);

			//SPI1 MISO		PA6
			PinConfg.GPIO_PinNumber= GPIO_PIN_6;
			PinConfg.GPIO_Mode= GPIO_MODE_AF_OUTPUT_PP;
			PinConfg.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &PinConfg);


			//SPI1 MOSI		PA7
			PinConfg.GPIO_PinNumber= GPIO_PIN_7;
			PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &PinConfg);



		}

	}

	else if (SPIx == SPI2)
	{
		//SPI1 MOSI		PB15
		//SPI1 MISO		PB14
		//SPI1 CLK		PB13
		//SPI1 NSS		PB12

		if (Globale_SPI_Confg[1]->Device_Mode == SPI_Device_Mode_Master)
		{
			//SPI1 NSS		PB12
			PinConfg.GPIO_PinNumber= GPIO_PIN_12;
			switch(Globale_SPI_Confg[1]->NSS)
			{
			case SPI_NSS_HW_Master_SS_Output:
				PinConfg.GPIO_Mode= GPIO_MODE_AF_OUTPUT_PP;
				PinConfg.GPIO_Output_Speed= GPPIO_SPEED_10M;
				break;


			case SPI_NSS_HW_Master_SS_Input:
				PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
				break;
			}
			MCAL_GPIO_Init(GPIOB, &PinConfg);


			//SPI1 CLK		PB13
			PinConfg.GPIO_PinNumber= GPIO_PIN_13;
			PinConfg.GPIO_Mode= GPIO_MODE_AF_OUTPUT_PP;
			PinConfg.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfg);

			//SPI1 MISO		PB14
			PinConfg.GPIO_PinNumber= GPIO_PIN_14;
			PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfg);


			//SPI1 MOSI		PB15
			PinConfg.GPIO_PinNumber= GPIO_PIN_15;
			PinConfg.GPIO_Mode= GPIO_MODE_AF_OUTPUT_PP;
			PinConfg.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfg);


		}
		else
		{
			if (Globale_SPI_Confg[1]->NSS == SPI_NSS_HW_Slave)
			{
				//SPI1 NSS		PB12
				PinConfg.GPIO_PinNumber= GPIO_PIN_12;
				PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &PinConfg);
			}

			//SPI1 CLK		PB13
			PinConfg.GPIO_PinNumber= GPIO_PIN_13;
			PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfg);

			//SPI1 MISO		PB14
			PinConfg.GPIO_PinNumber= GPIO_PIN_14;
			PinConfg.GPIO_Mode= GPIO_MODE_AF_OUTPUT_PP;
			PinConfg.GPIO_Output_Speed= GPPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &PinConfg);


			//SPI1 MOSI		PB15
			PinConfg.GPIO_PinNumber= GPIO_PIN_15;
			PinConfg.GPIO_Mode= GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &PinConfg);



		}

	}

}






void SPI1_IRQHandler(void)
{
	struct S_IRQ_Source flags;
	//Receive buffer not empty
	flags.RXNEIE= (SPI1->SR & (1<<0) >>0);

	//Transmit buffer empty
	flags.TXEIE= ((SPI1->SR & (1<<1)) >> 1) ;

	//Error from data overrun or data fault
	flags.ERRIE= ((SPI1->SR & (1<<4)) >> 4);


	Globale_SPI_Confg[0]->P_IRQ_CallBack(flags);
}


void SPI2_IRQHandler(void)
{
	struct S_IRQ_Source flags;
	//Receive buffer not empty
	flags.RXNEIE= (SPI2->SR & (1<<0) >>0);

	//Transmit buffer empty
	flags.TXEIE= ((SPI2->SR & (1<<1)) >> 1) ;

	//Error from data overrun or data fault
	flags.ERRIE= ((SPI2->SR & (1<<4)) >> 4);

	Globale_SPI_Confg[1]->P_IRQ_CallBack(flags);
}










































