################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_1.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_2.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_3.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_1.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_2.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_3.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_1.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_2.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/heap_3.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


