################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/fs.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/fsdata.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/httpserver-socket.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/main.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/netconf.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/serial_debug.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/stm32f4x7_eth_bsp.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/stm32f4xx_it.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/system_stm32f4xx.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/fs.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/fsdata.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/httpserver-socket.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/main.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/netconf.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/serial_debug.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/stm32f4x7_eth_bsp.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/stm32f4xx_it.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/system_stm32f4xx.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/fs.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/fsdata.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/httpserver-socket.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/main.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/netconf.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/serial_debug.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/stm32f4x7_eth_bsp.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/stm32f4xx_it.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/%.o: ../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


