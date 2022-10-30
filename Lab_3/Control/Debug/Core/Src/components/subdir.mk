################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/components/led.cpp \
../Core/Src/components/segment_led.cpp \
../Core/Src/components/switch_button.cpp 

OBJS += \
./Core/Src/components/led.o \
./Core/Src/components/segment_led.o \
./Core/Src/components/switch_button.o 

CPP_DEPS += \
./Core/Src/components/led.d \
./Core/Src/components/segment_led.d \
./Core/Src/components/switch_button.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/components/%.o Core/Src/components/%.su: ../Core/Src/components/%.cpp Core/Src/components/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-components

clean-Core-2f-Src-2f-components:
	-$(RM) ./Core/Src/components/led.d ./Core/Src/components/led.o ./Core/Src/components/led.su ./Core/Src/components/segment_led.d ./Core/Src/components/segment_led.o ./Core/Src/components/segment_led.su ./Core/Src/components/switch_button.d ./Core/Src/components/switch_button.o ./Core/Src/components/switch_button.su

.PHONY: clean-Core-2f-Src-2f-components

