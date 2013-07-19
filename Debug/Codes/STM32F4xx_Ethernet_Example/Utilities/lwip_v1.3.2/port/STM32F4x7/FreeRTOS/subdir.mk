################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/ethernetif.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/sys_arch.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/ethernetif.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/sys_arch.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/ethernetif.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/sys_arch.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


