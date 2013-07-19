################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc932.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc936.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc949.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc950.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/ccsbcs.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/syscall.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc932.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc936.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc949.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc950.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/ccsbcs.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/syscall.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc932.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc936.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc949.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/cc950.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/ccsbcs.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


