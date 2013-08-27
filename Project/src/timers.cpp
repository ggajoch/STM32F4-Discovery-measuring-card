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


void TIMER_Init(TIM_TypeDef* TIMx, uint32_t period, uint16_t prescaler, uint8_t interrupt = 0, IRQn_Type IRQChannel = TIM2_IRQn)
{
	if( TIMx == TIM2 )
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	else if( TIMx == TIM3 )
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	if( TIMx == TIM4 )
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	if( TIMx == TIM5 )
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5, ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period = period;
  TIM_TimeBaseStructure.TIM_Prescaler = prescaler - 1;//(uint16_t) ((SystemCoreClock / 2) / 28000000) - 1;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIMx, &TIM_TimeBaseStructure);
	
	if( interrupt )
	{
		TIM_ITConfig(TIMx, TIM_IT_Update, ENABLE); 
		NVIC_InitTypeDef NVIC_InitStructure;
		NVIC_InitStructure.NVIC_IRQChannel = IRQChannel;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 15;
		NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
		NVIC_Init(&NVIC_InitStructure);
	}
	TIM_Cmd(TIMx, ENABLE);
	TIM_ARRPreloadConfig(TIMx, ENABLE);
}

void TIMER_SelectOutTrigger(TIM_TypeDef* TIMx)
{
	TIM_SelectOutputTrigger(TIMx, TIM_TRGOSource_Update);
}

