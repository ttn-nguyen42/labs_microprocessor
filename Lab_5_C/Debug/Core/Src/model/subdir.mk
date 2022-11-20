################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/model/adc_input.cpp \
../Core/Src/model/input.cpp \
../Core/Src/model/output.cpp \
../Core/Src/model/pin.cpp \
../Core/Src/model/uart_input.cpp 

OBJS += \
./Core/Src/model/adc_input.o \
./Core/Src/model/input.o \
./Core/Src/model/output.o \
./Core/Src/model/pin.o \
./Core/Src/model/uart_input.o 

CPP_DEPS += \
./Core/Src/model/adc_input.d \
./Core/Src/model/input.d \
./Core/Src/model/output.d \
./Core/Src/model/pin.d \
./Core/Src/model/uart_input.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/model/%.o Core/Src/model/%.su: ../Core/Src/model/%.cpp Core/Src/model/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-model

clean-Core-2f-Src-2f-model:
	-$(RM) ./Core/Src/model/adc_input.d ./Core/Src/model/adc_input.o ./Core/Src/model/adc_input.su ./Core/Src/model/input.d ./Core/Src/model/input.o ./Core/Src/model/input.su ./Core/Src/model/output.d ./Core/Src/model/output.o ./Core/Src/model/output.su ./Core/Src/model/pin.d ./Core/Src/model/pin.o ./Core/Src/model/pin.su ./Core/Src/model/uart_input.d ./Core/Src/model/uart_input.o ./Core/Src/model/uart_input.su

.PHONY: clean-Core-2f-Src-2f-model

