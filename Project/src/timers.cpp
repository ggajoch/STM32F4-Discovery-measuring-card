#include "arch/cc.h"

extern "C" {
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_adc.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include "stm32f4x7_eth.h"
#include "netconf.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "tcpip.h"
#include <string.h>
#include "udpecho.h"
#include "LCD.h"
}


uint32_t getCoreClock()
{
	SystemCoreClockUpdate();
	return SystemCoreClock;
}


void TIMER_Init(TIM_TypeDef* TIMx, uint32_t period, uint16_t prescaler)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = period;
  TIM_TimeBaseStructure.TIM_Prescaler = prescaler - 1;//(uint16_t) ((SystemCoreClock / 2) / 28000000) - 1;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure);
	
	TIM_Cmd(TIMx, ENABLE);
	TIM_ARRPreloadConfig(TIMx, ENABLE);
	/*
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE); 
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 15;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);*/
}

void TIMER_SelectOutTrigger(TIM_TypeDef* TIMx)
{
	TIM_SelectOutputTrigger(TIMx, TIM_TRGOSource_Update);
}

