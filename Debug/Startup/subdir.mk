################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f103c8tx.s 

S_DEPS += \
./Startup/startup_stm32f103c8tx.d 

OBJS += \
./Startup/startup_stm32f103c8tx.o 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Drivers/CMSIS/inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Library" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f103c8tx.d ./Startup/startup_stm32f103c8tx.o

.PHONY: clean-Startup

