################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Library/UartWrap/Uart.cpp \
../Library/UartWrap/Uart_it.cpp 

OBJS += \
./Library/UartWrap/Uart.o \
./Library/UartWrap/Uart_it.o 

CPP_DEPS += \
./Library/UartWrap/Uart.d \
./Library/UartWrap/Uart_it.d 


# Each subdirectory must supply rules for building sources it contributes
Library/UartWrap/%.o Library/UartWrap/%.su Library/UartWrap/%.cyclo: ../Library/UartWrap/%.cpp Library/UartWrap/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Core/Inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Drivers/CMSIS/inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Library" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Library-2f-UartWrap

clean-Library-2f-UartWrap:
	-$(RM) ./Library/UartWrap/Uart.cyclo ./Library/UartWrap/Uart.d ./Library/UartWrap/Uart.o ./Library/UartWrap/Uart.su ./Library/UartWrap/Uart_it.cyclo ./Library/UartWrap/Uart_it.d ./Library/UartWrap/Uart_it.o ./Library/UartWrap/Uart_it.su

.PHONY: clean-Library-2f-UartWrap

