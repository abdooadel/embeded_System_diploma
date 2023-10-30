/*
 * Stm32_F103C6_GPIO_drivers.h
 *
 *  Created on: Oct 29, 2023
 *      Author: abdoo
 */

#ifndef GPIO_DRIVER_INC_STM32_F103C6_GPIO_DRIVERS_H_
#define GPIO_DRIVER_INC_STM32_F103C6_GPIO_DRIVERS_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"



//-----------------------------
//User type definitions (structures)
//-----------------------------

typedef struct{

	uint16_t GPIO_PinNumber ;    //specifies GPIO pin number
								//choose a value from @ref GPPIO_PINS_define

	uint8_t GPIO_Mode ;			//specifies GPIO pin mode
								//choose a value from @ref GPPIO_MODE_define

	uint8_t GPIO_Output_Speed;	//specifies GPIO output speed
							   //choose a value from @ref GPPIO_SPEED_define


}GPIO_PinConfig_t;







//-----------------------------
//Macros Configuration References
//-----------------------------
//@ref GPPIO_PINS_define
#define GPIO_PIN_0						((uint16_t )0x0001)
#define GPIO_PIN_1						((uint16_t )0x0002)
#define GPIO_PIN_2						((uint16_t )0x0004)
#define GPIO_PIN_3						((uint16_t )0x0008)
#define GPIO_PIN_4						((uint16_t )0x0010)
#define GPIO_PIN_5						((uint16_t )0x0020)
#define GPIO_PIN_6						((uint16_t )0x0040)
#define GPIO_PIN_7						((uint16_t )0x0080)
#define GPIO_PIN_8						((uint16_t )0x0100)
#define GPIO_PIN_9						((uint16_t )0x0200)
#define GPIO_PIN_10						((uint16_t )0x0400)
#define GPIO_PIN_11						((uint16_t )0x0800)
#define GPIO_PIN_12						((uint16_t )0x1000)
#define GPIO_PIN_13						((uint16_t )0x2000)
#define GPIO_PIN_14						((uint16_t )0x4000)
#define GPIO_PIN_15						((uint16_t )0x8000)
#define GPIO_PIN_ALL					((uint16_t )0xFFFF)

#define GPIO_PIN_MASK					0x0000FFFFu


//@ref GPPIO_MODE_define
//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain
//8: Alternate function input

#define GPIO_MODE_Analog					0x00000000u
#define GPIO_MODE_INPUT_FLO		 			0x00000001u
#define GPIO_MODE_INPUT_PD					0x00000002u
#define GPIO_MODE_INPUT_PU					0x00000003u
#define GPIO_MODE_OUTPUT_PP					0x00000004u
#define GPIO_MODE_OUTPUT_OD					0x00000005u
#define GPIO_MODE_AF_OUTPUT_PP				0x00000006u
#define GPIO_MODE_AF_OUTPUT_OD				0x00000007u
#define GPIO_MODE_AF_INPUT					0x00000008u


//@ref GPPIO_SPEED_define
//1: Output mode, max speed 10 MHz.
//2: Output mode, max speed 2 MHz.
//3: Output mode, max speed 50 MHz.

#define GPPIO_SPEED_10M						0x00000001u
#define GPPIO_SPEED_2M						0x00000002u
#define GPPIO_SPEED_50M						0x0000000#u



//@ref GPIO_PIN_state
#define GPIO_PIN_set			1
#define GPIO_PIN_reset			0


//@ref @ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_ENABLE		1
#define GPIO_RETURN_LOCK_ERROR		0

/*@ref Module_REF_NAME_define
*/
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_Init(GPIO_TypeDef *GPIOX, GPIO_PinConfig_t *PinConfig );
void MCAL_GPIO_DEInit(GPIO_TypeDef *GPIOX);
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOX, uint16_t PinNummber);
uint16_t MCAL_GPIO_ReadPprt(GPIO_TypeDef *GPIOX);
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOX, uint16_t PinNummber , uint8_t value);
void MCAL_GPIO_WritePprt(GPIO_TypeDef *GPIOX ,uint16_t value);
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOX, uint16_t PinNummber);
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOX, uint16_t PinNummber);






#endif /* GPIO_DRIVER_INC_STM32_F103C6_GPIO_DRIVERS_H_ */
