#ifndef __ANALOGIN_H__
#define __ANALOGIN_H__

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

void analogInit(ADC_TypeDef * ADCx, uint32_t resolution, GPIO_TypeDef * GPIOx, uint8_t pin);
void analogInitChannel(ADC_TypeDef * ADCx, uint8_t channel, uint8_t ADC_SampleTime);
uint16_t analogReadPin(ADC_TypeDef * ADCx, uint8_t channel);



#endif
