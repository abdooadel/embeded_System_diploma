################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Stm32_F103C6_EXTI_drivers.c \
../MCAL/Stm32_F103C6_GPIO_drivers.c \
../MCAL/Stm32_F103C6_RCC_drivers.c \
../MCAL/Stm32_F103C6_USART_drivers.c 

OBJS += \
./MCAL/Stm32_F103C6_EXTI_drivers.o \
./MCAL/Stm32_F103C6_GPIO_drivers.o \
./MCAL/Stm32_F103C6_RCC_drivers.o \
./MCAL/Stm32_F103C6_USART_drivers.o 

C_DEPS += \
./MCAL/Stm32_F103C6_EXTI_drivers.d \
./MCAL/Stm32_F103C6_GPIO_drivers.d \
./MCAL/Stm32_F103C6_RCC_drivers.d \
./MCAL/Stm32_F103C6_USART_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Stm32_F103C6_EXTI_drivers.o: ../MCAL/Stm32_F103C6_EXTI_drivers.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Master Embeded system course/Workspace/STM32_Drivers/HAL/inc" -I"D:/Master Embeded system course/Workspace/STM32_Drivers/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_EXTI_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_GPIO_drivers.o: ../MCAL/Stm32_F103C6_GPIO_drivers.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Master Embeded system course/Workspace/STM32_Drivers/HAL/inc" -I"D:/Master Embeded system course/Workspace/STM32_Drivers/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_GPIO_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_RCC_drivers.o: ../MCAL/Stm32_F103C6_RCC_drivers.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Master Embeded system course/Workspace/STM32_Drivers/HAL/inc" -I"D:/Master Embeded system course/Workspace/STM32_Drivers/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_RCC_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Stm32_F103C6_USART_drivers.o: ../MCAL/Stm32_F103C6_USART_drivers.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Master Embeded system course/Workspace/STM32_Drivers/HAL/inc" -I"D:/Master Embeded system course/Workspace/STM32_Drivers/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Stm32_F103C6_USART_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

