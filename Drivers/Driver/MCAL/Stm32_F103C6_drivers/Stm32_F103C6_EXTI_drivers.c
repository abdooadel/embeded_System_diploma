/*
 * Stm32_F103C6_GPIO_drivers.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Abdelrahman Elshahat
 */

#include "Stm32_F103C6_EXTI_drivers.h"



void (*GP_IRQCallBack[15])(void);




#define AFIO_EXTI_GPIO_Mapping(x)			(	(x == GPIOA) ? 0:\
											(x == GPIOB) ? 1:\
											(x == GPIOC) ? 2:\
											(x == GPIOD) ? 3:0  )






void ENABLE_NVIC(uint16_t IRQ){

	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXT0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXT1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXT2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXT3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXT4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXT5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXT10_15_Enable;
		break;


	}

}


void DISABLE_NVIC(uint16_t IRQ){

	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXT0_disable;
		break;
	case 1:
		NVIC_IRQ7_EXT1_disable;
		break;
	case 2:
		NVIC_IRQ8_EXT2_disable;
		break;
	case 3:
		NVIC_IRQ9_EXT3_disable;
		break;
	case 4:
		NVIC_IRQ10_EXT4_disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXT5_9_disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXT10_15_disable;
		break;


	}
}





	void Update_EXTI(EXTI_PinConfig_t* EXTI_Config){

		//1- Configure GPIO to be AF INPUT ->>>  Floating INPUT
		GPIO_PinConfig_t  PIN_CONFIG;
		PIN_CONFIG.GPIO_PinNumber= (EXTI_Config->EXTI_PIN.GPIO_PIN);
		PIN_CONFIG.GPIO_Mode= GPIO_MODE_AF_INPUT;
		MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PIN_CONFIG);
		//=======================================================================

		//2- Update AFIO to route external input line with port A,B,C,D
		uint8_t AFIO_EXTICR_index= (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber)/4 ;
		uint8_t AFIO_EXTICR_position = (EXTI_Config->EXTI_PIN.EXTI_InputLineNumber %4) *4 ;

		// clear four bit
		AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF<<AFIO_EXTICR_position);
		AFIO->EXTICR[AFIO_EXTICR_index] |= (AFIO_EXTI_GPIO_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) & 0xF  )<< AFIO_EXTICR_position;

		//=======================================================================================
		//3- Update rising and falling edge

		EXTI->RTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->FTSR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

		if (EXTI_Config->Trigger_case == EXTI_Trigger_RISING)
		{
			EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

		}
		else if (EXTI_Config->Trigger_case == EXTI_Trigger_FALLING)
		{
			EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

		}
		else if (EXTI_Config->Trigger_case == EXTI_Trigger_RISINGAndFalling)
		{
			EXTI->RTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
			EXTI->FTSR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);

		}


		//=======================================================================================
		//4- Handle function call back

		GP_IRQCallBack[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] = EXTI_Config->P_IRQCallBack ;




		//=======================================================================================
		//5- Enable/ Disable EXTI mask and NVIC_IRQ mask

		if (EXTI_Config ->IRQ_EN == EXTI_IRQ_Enable)
		{
			EXTI->IMR |= (1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
			ENABLE_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		}
		else if (EXTI_Config ->IRQ_EN == EXTI_IRQ_Disable)
		{
			EXTI->IMR &= ~(1 << EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
			DISABLE_NVIC(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		}

	}









	/**================================================================
	 * @Fn			-MCAL_EXTI_GPIO_DeInit
	 * @brief 		-Reset EXTI interrupt registers and NVIC IRQ Mask
	 * @param [in] 	- none
	 * @retval 		-none
	 * Note			-
	 */
	void MCAL_EXTI_GPIO_DeInit(void  ){

		EXTI->IMR=0x00000000;
		EXTI->EMR=0x00000000;
		EXTI->FTSR=0x00000000;
		EXTI->PR=0xFFFFFFFF;
		EXTI->RTSR=0x00000000;
		EXTI->SWIER=0x00000000;


		//Disable all external interrupts from NVIC

		NVIC_IRQ6_EXT0_disable;
		NVIC_IRQ7_EXT1_disable;
		NVIC_IRQ8_EXT2_disable;
		NVIC_IRQ9_EXT3_disable;
		NVIC_IRQ10_EXT4_disable;
		NVIC_IRQ23_EXT5_9_disable;
		NVIC_IRQ40_EXT10_15_disable;

	}




	/**================================================================
	 * @Fn			-MCAL_EXTI_GPIO_Init
	 * @brief 		-Used to initialize the external interrupt
	 * @param [in] 	- EXTI_Config
	 * @retval 		-none
	 * Note			-
	 */
	void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t * EXTI_Config  )
	{

		Update_EXTI(EXTI_Config);

	}



	/**================================================================
	 * @Fn			-MCAL_EXTI_GPIO_Update
	 * @brief 		-Used to update the external interrupt
	 * @param [in] 	-EXTI_Config
	 * @retval 		-none
	 * Note			-
	 */
	void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t * EXTI_Config  ){

		Update_EXTI(EXTI_Config);

	}












	void EXTI0_IRQHandler(void)
	{
		EXTI->PR |= 1 << 0;
		GP_IRQCallBack[0]();
	}

	void EXTI1_IRQHandler(void)
	{
		EXTI->PR |= 1 << 1;
		GP_IRQCallBack[1]();

	}


	void EXTI2_IRQHandler(void)
	{
		EXTI->PR |= 1 << 2;
		GP_IRQCallBack[2]();

	}

	void EXTI3_IRQHandler(void)
	{
		EXTI->PR |= 1 << 3;
		GP_IRQCallBack[3]();

	}


	void EXTI4_IRQHandler(void)
	{
		EXTI->PR |= 1 << 4;
		GP_IRQCallBack[4]();

	}

	void EXTI9_5_IRQHandler(void)
	{

		//select which interrupet was requested

		if (EXTI->PR &  1 << 5){ 	EXTI->PR |= 1 << 5; 	GP_IRQCallBack[5]();}
		if (EXTI->PR &  1 << 6){ 	EXTI->PR |= 1 << 6; 	GP_IRQCallBack[6]();}
		if (EXTI->PR &  1 << 7){ 	EXTI->PR |= 1 << 7; 	GP_IRQCallBack[7]();}
		if (EXTI->PR &  1 << 8){ 	EXTI->PR |= 1 << 8; 	GP_IRQCallBack[8]();}
		if (EXTI->PR &  1 << 9){ 	EXTI->PR |= 1 << 9; 	GP_IRQCallBack[9]();}


	}



	void EXTI15_10_IRQHandler(void)
	{
		if (EXTI->PR &  1 << 10){ 	EXTI->PR |= 1 << 10; 	GP_IRQCallBack[10]();}
		if (EXTI->PR &  1 << 11){ 	EXTI->PR |= 1 << 11; 	GP_IRQCallBack[11]();}
		if (EXTI->PR &  1 << 12){ 	EXTI->PR |= 1 << 12; 	GP_IRQCallBack[12]();}
		if (EXTI->PR &  1 << 13){ 	EXTI->PR |= 1 << 13; 	GP_IRQCallBack[13]();}
		if (EXTI->PR &  1 << 14){ 	EXTI->PR |= 1 << 14; 	GP_IRQCallBack[14]();}
		if (EXTI->PR &  1 << 15){ 	EXTI->PR |= 1 << 15; 	GP_IRQCallBack[15]();}
	}
