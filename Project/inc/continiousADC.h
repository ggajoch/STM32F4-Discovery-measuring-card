#ifndef __CONTINIOUSADC_H__
#define __CONTINIOUSADC_H__

#include <inttypes.h>

#include "arch/cc.h"
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_adc.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include "commandProcessing.h"
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



void continiousADC_init(uint32_t period, uint16_t prescaler);

#endif
