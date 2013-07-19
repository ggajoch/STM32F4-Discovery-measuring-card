################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/Standalone/ethernetif.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/Standalone/ethernetif.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/Standalone/ethernetif.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/Standalone/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/Standalone/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


