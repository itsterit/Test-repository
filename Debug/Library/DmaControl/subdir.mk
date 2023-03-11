################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Library/DmaControl/DmaControl.cpp \
../Library/DmaControl/DmaControl_it.cpp 

OBJS += \
./Library/DmaControl/DmaControl.o \
./Library/DmaControl/DmaControl_it.o 

CPP_DEPS += \
./Library/DmaControl/DmaControl.d \
./Library/DmaControl/DmaControl_it.d 


# Each subdirectory must supply rules for building sources it contributes
Library/DmaControl/%.o Library/DmaControl/%.su Library/DmaControl/%.cyclo: ../Library/DmaControl/%.cpp Library/DmaControl/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Core/Inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Drivers/CMSIS/inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Library" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Library-2f-DmaControl

clean-Library-2f-DmaControl:
	-$(RM) ./Library/DmaControl/DmaControl.cyclo ./Library/DmaControl/DmaControl.d ./Library/DmaControl/DmaControl.o ./Library/DmaControl/DmaControl.su ./Library/DmaControl/DmaControl_it.cyclo ./Library/DmaControl/DmaControl_it.d ./Library/DmaControl/DmaControl_it.o ./Library/DmaControl/DmaControl_it.su

.PHONY: clean-Library-2f-DmaControl

