################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Stm32_F103C6_drivers/LCD_driver/subdir.mk
-include Stm32_F103C6_drivers/KEYPAD/subdir.mk
-include Stm32_F103C6_drivers/GPIO_driver/subdir.mk
-include Stm32_F103C6_drivers/7seg/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
KEYPDA_LCD_7seg_interface.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
KEYPDA_LCD_7seg_interface.list \

OBJCOPY_BIN += \
KEYPDA_LCD_7seg_interface.bin \


# All Target
all: KEYPDA_LCD_7seg_interface.elf secondary-outputs

# Tool invocations
KEYPDA_LCD_7seg_interface.elf: $(OBJS) $(USER_OBJS) D:\Master\ Embeded\ system\ course\Workspace\Unit_8\KEYPDA_LCD_7seg_interface\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc  -gdwarf-2 -o "KEYPDA_LCD_7seg_interface.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Master Embeded system course\Workspace\Unit_8\KEYPDA_LCD_7seg_interface\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="KEYPDA_LCD_7seg_interface.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

KEYPDA_LCD_7seg_interface.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "KEYPDA_LCD_7seg_interface.list"
	@echo 'Finished building: $@'
	@echo ' '

KEYPDA_LCD_7seg_interface.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "KEYPDA_LCD_7seg_interface.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
