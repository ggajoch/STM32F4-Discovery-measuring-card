################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/main.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/netconf.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/serial_debug.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/stm32f4x7_eth_bsp.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/stm32f4xx_it.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/system_stm32f4xx.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/tcpecho.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/udpecho.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/main.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/netconf.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/serial_debug.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/stm32f4x7_eth_bsp.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/stm32f4xx_it.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/system_stm32f4xx.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/tcpecho.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/udpecho.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/main.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/netconf.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/serial_debug.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/stm32f4x7_eth_bsp.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/stm32f4xx_it.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/system_stm32f4xx.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/tcpecho.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/udpecho.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/%.o: ../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


