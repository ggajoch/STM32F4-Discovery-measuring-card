################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/fs.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/fsdata.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/httpd.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/httpd_cgi_ssi.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/main.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/netconf.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/serial_debug.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/stm32f4x7_eth_bsp.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/stm32f4xx_it.c \
../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/system_stm32f4xx.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/fs.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/fsdata.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/httpd.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/httpd_cgi_ssi.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/main.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/netconf.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/serial_debug.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/stm32f4x7_eth_bsp.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/stm32f4xx_it.o \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/system_stm32f4xx.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/fs.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/fsdata.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/httpd.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/httpd_cgi_ssi.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/main.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/netconf.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/serial_debug.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/stm32f4x7_eth_bsp.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/stm32f4xx_it.d \
./Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/%.o: ../Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


