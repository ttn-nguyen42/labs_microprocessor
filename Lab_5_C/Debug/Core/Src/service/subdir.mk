################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/service/command_parser.cpp \
../Core/Src/service/controller.cpp \
../Core/Src/service/led_controller.cpp \
../Core/Src/service/sensor_reader.cpp 

OBJS += \
./Core/Src/service/command_parser.o \
./Core/Src/service/controller.o \
./Core/Src/service/led_controller.o \
./Core/Src/service/sensor_reader.o 

CPP_DEPS += \
./Core/Src/service/command_parser.d \
./Core/Src/service/controller.d \
./Core/Src/service/led_controller.d \
./Core/Src/service/sensor_reader.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/service/%.o Core/Src/service/%.su: ../Core/Src/service/%.cpp Core/Src/service/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103x6 -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-service

clean-Core-2f-Src-2f-service:
	-$(RM) ./Core/Src/service/command_parser.d ./Core/Src/service/command_parser.o ./Core/Src/service/command_parser.su ./Core/Src/service/controller.d ./Core/Src/service/controller.o ./Core/Src/service/controller.su ./Core/Src/service/led_controller.d ./Core/Src/service/led_controller.o ./Core/Src/service/led_controller.su ./Core/Src/service/sensor_reader.d ./Core/Src/service/sensor_reader.o ./Core/Src/service/sensor_reader.su

.PHONY: clean-Core-2f-Src-2f-service

