/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
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



#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif



void mywait(int x){
	volatile uint32_t z,y;
	for(y=0;y<x;y++)
	{
		for(z=0;z<255;z++);

	}
}



int main(void)
{
	// Enable PortA and PortB clocks
	RCC_GPIOA_CLK_ENABLE();
	RCC_GPIOB_CLK_ENABLE();
	GPIO_PinConfig_t PIN_CONFIG;
	PIN_CONFIG.GPIO_PinNumber=GPIO_PIN_1;
	PIN_CONFIG.GPIO_Mode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PIN_CONFIG);

	PIN_CONFIG.GPIO_PinNumber=GPIO_PIN_1;
	PIN_CONFIG.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	PIN_CONFIG.GPIO_Output_Speed= GPPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PIN_CONFIG);

	PIN_CONFIG.GPIO_PinNumber=GPIO_PIN_13;
	PIN_CONFIG.GPIO_Mode=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PIN_CONFIG);

	PIN_CONFIG.GPIO_PinNumber=GPIO_PIN_13;
	PIN_CONFIG.GPIO_Mode=GPIO_MODE_OUTPUT_PP;
	PIN_CONFIG.GPIO_Output_Speed= GPPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PIN_CONFIG);

	while(1){

		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)  == 0);
		}

		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13)  == 1 )
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);


		}

//		if ( MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1)
//			MCAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_set);
		mywait(1);
	}
}
