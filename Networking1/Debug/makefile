################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Networking1.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Networking1.list \


# All Target
all: Networking1.elf secondary-outputs

# Tool invocations
Networking1.elf: $(OBJS) $(USER_OBJS) C:\Users\hatri\OneDrive\ -\ Milwaukee\ School\ of\ Engineering\Networking\ 1\ (2019)\Project_Working\Networking_1_Project_C\Networking1\STM32F446RETX_FLASH.ld
	arm-none-eabi-gcc -o "Networking1.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\hatri\OneDrive - Milwaukee School of Engineering\Networking 1 (2019)\Project_Working\Networking_1_Project_C\Networking1\STM32F446RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Networking1.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Networking1.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Networking1.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
