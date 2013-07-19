################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/api_lib.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/api_msg.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/err.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netbuf.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netdb.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netifapi.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/sockets.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/tcpip.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/api_lib.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/api_msg.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/err.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netbuf.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netdb.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netifapi.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/sockets.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/tcpip.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/api_lib.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/api_msg.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/err.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netbuf.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netdb.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/netifapi.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/sockets.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


