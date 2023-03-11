################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/src/system_stm32f1xx.c 

C_DEPS += \
./Drivers/CMSIS/src/system_stm32f1xx.d 

OBJS += \
./Drivers/CMSIS/src/system_stm32f1xx.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/src/%.o Drivers/CMSIS/src/%.su Drivers/CMSIS/src/%.cyclo: ../Drivers/CMSIS/src/%.c Drivers/CMSIS/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Drivers/CMSIS/inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-CMSIS-2f-src

clean-Drivers-2f-CMSIS-2f-src:
	-$(RM) ./Drivers/CMSIS/src/system_stm32f1xx.cyclo ./Drivers/CMSIS/src/system_stm32f1xx.d ./Drivers/CMSIS/src/system_stm32f1xx.o ./Drivers/CMSIS/src/system_stm32f1xx.su

.PHONY: clean-Drivers-2f-CMSIS-2f-src

