#ifndef __TIMERS_H__
#define __TIMERS_H__

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


uint32_t getCoreClock();
void TIMER_Init(TIM_TypeDef* TIMx, uint32_t period, uint16_t prescaler);


#endif
