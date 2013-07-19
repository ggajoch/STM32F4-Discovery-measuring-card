################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Libraries/STM32F4x7_ETH_Driver/src/stm32f4x7_eth.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Libraries/STM32F4x7_ETH_Driver/src/stm32f4x7_eth.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Libraries/STM32F4x7_ETH_Driver/src/stm32f4x7_eth.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Libraries/STM32F4x7_ETH_Driver/src/%.o: ../Codes/STM32F4xx_Ethernet_Example/Libraries/STM32F4x7_ETH_Driver/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


