/*
 * Stm32_F103C6_GPIO_drivers.h
 *
 *  Created on: Oct 29, 2023
 *      Author: abdoo
 */

#ifndef GPIO_DRIVER_INC_STM32_F103C6_RCC_DRIVERS_H_
#define GPIO_DRIVER_INC_STM32_F103C6_RCC_DRIVERS_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_drivers.h"


//-----------------------------
//User type definitions (structures)
//-----------------------------





//-----------------------------
//Macros Configuration References
//-----------------------------

#define HSI_RC_CLCK				(uint32_t)8000000

/*
* ===============================================
* APIs Supported by "MCAL RCC DRIVER"
* ===============================================
*/

uint32_t MCAL_RCC_GetSYSCKFreq(void);
uint32_t MCAL_RCC_GetHLCKFreq(void);
uint32_t MCAL_RCC_GetPLCK1Freq(void);
uint32_t MCAL_RCC_GetPLCK2Freq(void);



#endif /* GPIO_DRIVER_INC_STM32_F103C6_GPIO_DRIVERS_H_ */
