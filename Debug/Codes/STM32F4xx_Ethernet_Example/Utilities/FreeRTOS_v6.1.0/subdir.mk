################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/croutine.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/list.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/queue.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/tasks.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/croutine.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/list.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/queue.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/tasks.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/croutine.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/list.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/queue.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


