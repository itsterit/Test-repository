################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Library/ClockControl/ClockControl.cpp 

OBJS += \
./Library/ClockControl/ClockControl.o 

CPP_DEPS += \
./Library/ClockControl/ClockControl.d 


# Each subdirectory must supply rules for building sources it contributes
Library/ClockControl/%.o Library/ClockControl/%.su: ../Library/ClockControl/%.cpp Library/ClockControl/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103/Drivers/CMSIS/inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103/Core/Inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Library" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Library-2f-ClockControl

clean-Library-2f-ClockControl:
	-$(RM) ./Library/ClockControl/ClockControl.d ./Library/ClockControl/ClockControl.o ./Library/ClockControl/ClockControl.su

.PHONY: clean-Library-2f-ClockControl

