################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/fs.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/fsdata.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/httpserver-netconn.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/main.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/netconf.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/serial_debug.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/stm32f4x7_eth_bsp.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/stm32f4xx_it.c \
../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/system_stm32f4xx.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/fs.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/fsdata.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/httpserver-netconn.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/main.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/netconf.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/serial_debug.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/stm32f4x7_eth_bsp.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/stm32f4xx_it.o \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/system_stm32f4xx.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/fs.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/fsdata.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/httpserver-netconn.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/main.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/netconf.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/serial_debug.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/stm32f4x7_eth_bsp.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/stm32f4xx_it.d \
./Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/%.o: ../Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

