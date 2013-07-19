################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/ppp/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/netif/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/snmp/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv6/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/ipv4/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/core/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/src/api/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/Standalone/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/lwip_v1.3.2/port/STM32F4x7/FreeRTOS/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/STM32F4-Discovery/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/TASKING/ARM_CM3/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MemMang/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/MDK-ARM/ARM_CM3/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/GCC/ARM_CM3_MPU/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/GCC/ARM_CM3/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/portable/EWARM/ARM_CM3/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FreeRTOS_v6.1.0/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/option/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Utilities/FatFs_vR0.08a/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/Standalone/udp_echo_server/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/Standalone/udp_echo_client/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_server/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/Standalone/tcp_echo_client/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/Standalone/httpserver/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/udptcp_echo_server_netconn/MDK-ARM/Discover-More/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_socket/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Project/FreeRTOS/httpserver_netconn/MDK-ARM/Discover-More/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Libraries/STM32F4xx_StdPeriph_Driver/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Libraries/STM32F4x7_ETH_Driver/src/subdir.mk
-include Codes/STM32F4xx_Ethernet_Example/Libraries/CMSIS/Device/ST/STM32F4xx/Source/Templates/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: udp

# Tool invocations
udp: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-none-eabi-gcc  -o "udp" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) udp
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
