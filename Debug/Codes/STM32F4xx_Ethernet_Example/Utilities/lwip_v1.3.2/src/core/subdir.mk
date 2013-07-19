################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/dhcp.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/dns.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/init.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/mem.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/memp.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/netif.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/pbuf.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/raw.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/stats.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/sys.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp_in.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp_out.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/udp.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/dhcp.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/dns.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/init.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/mem.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/memp.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/netif.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/pbuf.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/raw.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/stats.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/sys.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp_in.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp_out.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/udp.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/dhcp.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/dns.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/init.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/mem.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/memp.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/netif.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/pbuf.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/raw.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/stats.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/sys.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp_in.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/tcp_out.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


