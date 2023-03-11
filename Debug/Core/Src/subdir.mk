################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c 

CPP_SRCS += \
../Core/Src/Function.cpp \
../Core/Src/main.cpp \
../Core/Src/stm32f1xx_it.cpp 

C_DEPS += \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d 

OBJS += \
./Core/Src/Function.o \
./Core/Src/main.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o 

CPP_DEPS += \
./Core/Src/Function.d \
./Core/Src/main.d \
./Core/Src/stm32f1xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Core/Inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Drivers/CMSIS/inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Library" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Drivers/CMSIS/inc" -I"C:/Users/itste/STM32CubeIDE/workspace_1.9.0/Metal_Detector_F103_cpp/Library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Function.cyclo ./Core/Src/Function.d ./Core/Src/Function.o ./Core/Src/Function.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su

.PHONY: clean-Core-2f-Src

