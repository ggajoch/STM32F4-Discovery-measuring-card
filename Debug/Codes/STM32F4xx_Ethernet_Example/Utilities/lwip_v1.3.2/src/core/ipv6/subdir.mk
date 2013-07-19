################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/icmp6.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/inet6.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/ip6.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/ip6_addr.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/icmp6.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/inet6.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/ip6.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/ip6_addr.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/icmp6.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/inet6.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/ip6.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/ip6_addr.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


