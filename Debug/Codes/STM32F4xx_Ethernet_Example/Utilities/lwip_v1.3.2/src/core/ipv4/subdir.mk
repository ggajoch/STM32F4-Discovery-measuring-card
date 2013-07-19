################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/autoip.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/icmp.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/igmp.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/inet.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/inet_chksum.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip_addr.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip_frag.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/autoip.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/icmp.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/igmp.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/inet.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/inet_chksum.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip_addr.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip_frag.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/autoip.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/icmp.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/igmp.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/inet.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/inet_chksum.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip_addr.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/ip_frag.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


