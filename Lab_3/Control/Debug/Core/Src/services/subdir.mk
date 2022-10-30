################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/services/controller.cpp \
../Core/Src/services/traffic_light.cpp 

OBJS += \
./Core/Src/services/controller.o \
./Core/Src/services/traffic_light.o 

CPP_DEPS += \
./Core/Src/services/controller.d \
./Core/Src/services/traffic_light.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/services/%.o Core/Src/services/%.su: ../Core/Src/services/%.cpp Core/Src/services/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-services

clean-Core-2f-Src-2f-services:
	-$(RM) ./Core/Src/services/controller.d ./Core/Src/services/controller.o ./Core/Src/services/controller.su ./Core/Src/services/traffic_light.d ./Core/Src/services/traffic_light.o ./Core/Src/services/traffic_light.su

.PHONY: clean-Core-2f-Src-2f-services

