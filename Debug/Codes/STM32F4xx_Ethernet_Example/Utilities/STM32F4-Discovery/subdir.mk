################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/fonts.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/lcd_log.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_debug.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_lcd.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.c \
../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_sdio_sd.c 

OBJS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/fonts.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/lcd_log.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_debug.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_lcd.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.o \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_sdio_sd.o 

C_DEPS += \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/fonts.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/lcd_log.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_audio_codec.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_debug.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_lcd.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_lis302dl.d \
./Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/stm32f4_discovery_sdio_sd.d 


# Each subdirectory must supply rules for building sources it contributes
Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/%.o: ../Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


