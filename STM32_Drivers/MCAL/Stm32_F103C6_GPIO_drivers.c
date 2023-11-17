/*
 * Stm32_F103C6_GPIO_drivers.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Abdelrahman Elshahat
 */

#include "Stm32_F103C6_GPIO_drivers.h"


uint8_t Get_CRLH_Position(uint16_t PinNummber)
{
	switch(PinNummber){
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}





/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-Initialize GPIOX according to specified parameters
 * @param [in] 	- GPIOX, GPIO_PinConfig_t PinConfig
 * @param [in] 	-PinConfig
 * @retval 		-none
 * Note			-
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOX, GPIO_PinConfig_t *PinConfig ){
	//Port configuration register low((GPIOx_CRL)) configure pin 0 >>> 7
	//Port configuration register high((GPIOx_CRH)) configure pin 8 >>> 15
	volatile uint32_t *configRegister= NULL;
	uint8_t Pinconfig;
	configRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ?  &GPIOX->CRL :  &GPIOX->CRH;

	//clear CNF[1:0]  MODE[1:0]
	*configRegister &= ~(0b1111<< Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//if pin is output
	if (PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP || PinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_Mode == GPIO_MODE_AF_OUTPUT_PP|| PinConfig->GPIO_Mode == GPIO_MODE_AF_OUTPUT_OD )
	{
		Pinconfig = (((PinConfig->GPIO_Mode - 4)	 << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0F;
	}
	else
	{
		if ( PinConfig->GPIO_Mode == GPIO_MODE_INPUT_FLO||  PinConfig->GPIO_Mode == GPIO_MODE_Analog)
		{
			Pinconfig= (PinConfig->GPIO_Mode <<2) & 0x0f;
		}
		else if(PinConfig->GPIO_Mode == GPIO_MODE_AF_INPUT)
		{
			Pinconfig=( GPIO_MODE_INPUT_FLO << 2) & 0x0f;
		}
		else {
			Pinconfig= (GPIO_MODE_INPUT_PU <<2) & 0x0f;
			if (PinConfig->GPIO_Mode == GPIO_MODE_INPUT_PU)
				GPIOX->ODR |= PinConfig->GPIO_PinNumber;
			else
				GPIOX->ODR &= ~(PinConfig->GPIO_PinNumber);

		}

	}

	*configRegister |=  Pinconfig << Get_CRLH_Position(PinConfig->GPIO_PinNumber);

}


/**================================================================
 * @Fn			-MCAL_GPIO_DEInit
 * @brief 		-Resets GPIOX according to specified parameters
 * @param [in] 	- GPIOX
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_DEInit(GPIO_TypeDef *GPIOX){

	//	GPIOX->BRR=0x00000000;
	//	GPIOX->BSRR=0x00000000;
	//	GPIOX->CRH=0x44444444;
	//	GPIOX->CRL=0x44444444;
	//	GPIOX->LCKR=0x00000000;
	//	GPIOX->ODR=0x00000000;

	if( GPIOX == GPIOA)
	{
		RCC->APB2RSTR |= 1<<2;
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOX == GPIOB)
	{
		RCC->APB2RSTR |= 1<<3;
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOX == GPIOC)
	{
		RCC->APB2RSTR |= 1<<4;
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOX == GPIOD)
	{
		RCC->APB2RSTR |= 1<<5;
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOX == GPIOE)
	{
		RCC->APB2RSTR |= 1<<6;
		RCC->APB2RSTR &= ~(1<<2);
	}

}





/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief 		-Read specific PIN
 * @param [in] 	- GPIOX
 * @param [in] 	- PinNummber
 * @retval 		-the input read pin based on @ref GPIO_PIN_state
 * Note			-none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOX, uint16_t PinNummber)
{

	uint8_t bitStatus;
	if( ((GPIOX->IDR) & (PinNummber)) != GPIO_PIN_reset )
	{
		bitStatus= GPIO_PIN_set;
	}
	else
	{
		bitStatus= GPIO_PIN_reset;
	}
	return bitStatus;
}



/**================================================================
 * @Fn			-MCAL_GPIO_ReadPprt
 * @brief 		-Read  PORT value
 * @param [in] 	- GPIOX
 * @retval 		-the input  port value
 * Note			-none
 */
uint16_t MCAL_GPIO_ReadPprt(GPIO_TypeDef *GPIOX){

	uint16_t portVal;
	portVal= (uint16_t)(GPIOX->IDR);
	return portVal;

}



/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief 		-Write specific PIN
 * @param [in] 	- GPIOX
 * @param [in] 	- PinNummber
 * @param [in] 	- value
 *
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOX, uint16_t PinNummber , uint8_t value)
{
	if( value  != ( uint32_t)GPIO_PIN_set )
	{
		//		GPIOX->ODR &= ~(PinNummber);
		GPIOX->BRR = (uint32_t)PinNummber;
	}
	else
	{
		//			GPIOX->ODR |= 	(PinNummber);
		GPIOX->BSRR = (uint32_t)PinNummber;

	}
}



/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief 		-write  PORT value
 * @param [in] 	- GPIOX
 * @param [in] 	- value
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOX, uint16_t value)
{
	GPIOX->ODR = (uint32_t)value;
}



/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief 		-toggle specific GPIO PIN
 * @param [in] 	- GPIOX
 * @retval 		-none
 * Note			-none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOX, uint16_t PinNummber){

	GPIOX->ODR ^= (uint32_t)PinNummber;

}



/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief 		-lock specific GPIO PIN
 * @param [in] 	- GPIOX
 * @retval 		-return status from @ref GPIO_RETURN_LOCK
 * Note			-none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOX, uint16_t PinNummber){
	uint32_t temp=1<<16;
	temp |= (uint32_t)PinNummber;

	GPIOX->LCKR  = temp;

	GPIOX->LCKR = PinNummber;

	GPIOX->LCKR  = temp;

	temp = GPIOX->LCKR ;

	temp = GPIOX->LCKR ;
	if ( GPIOX->LCKR & 1<<16 )
	{
		return GPIO_RETURN_LOCK_ENABLE;
	}
	else
		return GPIO_RETURN_LOCK_ERROR;
}




