/*
 * Stm32_F103C6_RCC_drivers.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Abdelrahman Elshahat
 */

#include <Stm32_F103C6_RCC_drivers.h>
//
//PPRE1: APB low-speed prescaler (APB1)
//Set and cleared by software to control the division factor of the APB low-speed clock
//(PCLK1).
//Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16

uint8_t APBPrescTable[]= {0,0,0,0,1,2,3,4};
uint8_t AHBPrescTable[]= {0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};


uint32_t MCAL_RCC_GetSYSCKFreq(void)
{

	//	SWS: System clock switch status
	//	Set and cleared by hardware to indicate which clock source is used as system clock.
	//	00: HSI oscillator used as system clock
	//	01: HSE oscillator used as system clock
	//	10: PLL used as system clock
	//	11: not applicable

	switch ((RCC->CFGR >> 2 )& 0b11) {
	case 0:
		return HSI_RC_CLCK;

		break;
	case 1:
		break;
	case 2:

		break;
	default:
		break;
	}
	return 0;
}


uint32_t MCAL_RCC_GetHLCKFreq(void)
{

	return	(MCAL_RCC_GetSYSCKFreq() >> 	AHBPrescTable[(RCC->CFGR >>4) & 0b1111]);
}


uint32_t MCAL_RCC_GetPLCK1Freq(void)
{

	return (MCAL_RCC_GetHLCKFreq() >> APBPrescTable[(RCC->CFGR >> 8) & 0b111]);

}


uint32_t MCAL_RCC_GetPLCK2Freq(void)
{

	return (MCAL_RCC_GetHLCKFreq() >> APBPrescTable[(RCC->CFGR >> 11) & 0b111]);

}

