################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/etharp.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/loopif.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/slipif.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/etharp.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/loopif.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/slipif.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/etharp.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/loopif.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/slipif.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


