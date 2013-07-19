################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/diskio.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/ff.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/diskio.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/ff.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/diskio.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/ff.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


