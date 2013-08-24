#ifndef __INTERNALDAC_H__
#define __INTERNALDAC_H__

#include <inttypes.h>

#include "arch/cc.h"
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_adc.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
extern "C" {
#include "stm32f4x7_eth.h"
#include "netconf.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "tcpip.h"
#include <string.h>
#include <stdlib.h>
#include "udpecho.h"
#include "LCD.h"
}

void internalDAC_Init(uint8_t pin); // 0 - PA4, 1 - PA5
void internalDAC_Write(uint8_t pin, uint16_t value, uint8_t align);



#endif
