################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/main.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/netconf.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/serial_debug.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/stm32f4x7_eth_bsp.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/stm32f4xx_it.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/system_stm32f4xx.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/tcp_echoserver.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/main.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/netconf.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/serial_debug.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/stm32f4x7_eth_bsp.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/stm32f4xx_it.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/system_stm32f4xx.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/tcp_echoserver.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/main.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/netconf.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/serial_debug.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/stm32f4x7_eth_bsp.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/stm32f4xx_it.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/system_stm32f4xx.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/tcp_echoserver.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/%.o: ../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


