################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/7seg.c \
../HAL/LCD.c \
../HAL/keypad.c 

OBJS += \
./HAL/7seg.o \
./HAL/LCD.o \
./HAL/keypad.o 

C_DEPS += \
./HAL/7seg.d \
./HAL/LCD.d \
./HAL/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/7seg.o: ../HAL/7seg.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Master Embeded system course/Workspace/STM32_Drivers/HAL/inc" -I"D:/Master Embeded system course/Workspace/STM32_Drivers/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/7seg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Master Embeded system course/Workspace/STM32_Drivers/HAL/inc" -I"D:/Master Embeded system course/Workspace/STM32_Drivers/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/keypad.o: ../HAL/keypad.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Master Embeded system course/Workspace/STM32_Drivers/HAL/inc" -I"D:/Master Embeded system course/Workspace/STM32_Drivers/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

