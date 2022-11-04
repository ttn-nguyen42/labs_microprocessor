################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/component/led.cpp \
../Core/Src/component/segment_led.cpp \
../Core/Src/component/switch.cpp 

OBJS += \
./Core/Src/component/led.o \
./Core/Src/component/segment_led.o \
./Core/Src/component/switch.o 

CPP_DEPS += \
./Core/Src/component/led.d \
./Core/Src/component/segment_led.d \
./Core/Src/component/switch.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/component/%.o Core/Src/component/%.su: ../Core/Src/component/%.cpp Core/Src/component/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-component

clean-Core-2f-Src-2f-component:
	-$(RM) ./Core/Src/component/led.d ./Core/Src/component/led.o ./Core/Src/component/led.su ./Core/Src/component/segment_led.d ./Core/Src/component/segment_led.o ./Core/Src/component/segment_led.su ./Core/Src/component/switch.d ./Core/Src/component/switch.o ./Core/Src/component/switch.su

.PHONY: clean-Core-2f-Src-2f-component

