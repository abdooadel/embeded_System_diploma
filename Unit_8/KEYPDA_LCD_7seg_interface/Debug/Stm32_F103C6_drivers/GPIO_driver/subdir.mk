################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32_F103C6_drivers/GPIO_driver/Stm32_F103C6_GPIO_drivers.c 

OBJS += \
./Stm32_F103C6_drivers/GPIO_driver/Stm32_F103C6_GPIO_drivers.o 

C_DEPS += \
./Stm32_F103C6_drivers/GPIO_driver/Stm32_F103C6_GPIO_drivers.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32_F103C6_drivers/GPIO_driver/Stm32_F103C6_GPIO_drivers.o: ../Stm32_F103C6_drivers/GPIO_driver/Stm32_F103C6_GPIO_drivers.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Master Embeded system course/Workspace/Unit_8/KEYPDA_LCD_7seg_interface/Stm32_F103C6_drivers/GPIO_driver/inc" -I"D:/Master Embeded system course/Workspace/Unit_8/KEYPDA_LCD_7seg_interface/Stm32_F103C6_drivers/7seg" -I"D:/Master Embeded system course/Workspace/Unit_8/KEYPDA_LCD_7seg_interface/Stm32_F103C6_drivers/KEYPAD" -I"D:/Master Embeded system course/Workspace/Unit_8/KEYPDA_LCD_7seg_interface/Stm32_F103C6_drivers/LCD_driver" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32_F103C6_drivers/GPIO_driver/Stm32_F103C6_GPIO_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

