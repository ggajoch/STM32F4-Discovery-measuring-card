//FIXME
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
#include <stdlib.h>
#include "udpecho.h"
#include "LCD.h"
}

#define USING_GPIO GPIOD

#define ADD_AHB1 (RCC_AHB1Periph_ ## GPIOD)

xSemaphoreHandle waitForADC;
xQueueHandle analogINReadQueue;

void analogInit(ADC_TypeDef * ADCx, uint32_t resolution, GPIO_TypeDef * GPIOx, uint8_t pin)
{
	if( ADCx == ADC1 )
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	else if( ADCx == ADC2 )
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);
	else if( ADCx == ADC3 )
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);
	
	if( GPIOx == GPIOA )
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA, ENABLE );
	else if( GPIOx == GPIOB )
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOB, ENABLE );
	else if( GPIOx == GPIOC )
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOC, ENABLE );
	else if( GPIOx == GPIOD )
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOD, ENABLE );
	else if( GPIOx == GPIOE )
		RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOE, ENABLE );
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStruct.GPIO_Pin = (1 << pin);
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(GPIOx, &GPIO_InitStruct);
	
	
	ADC_InitTypeDef ADC_InitStruct;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStruct.ADC_Resolution = resolution;
	ADC_InitStruct.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConvEdge_None;
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None; 
	ADC_InitStruct.ADC_NbrOfConversion = 1;
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	ADC_Init(ADCx, &ADC_InitStruct);
	
	ADC_ITConfig(ADCx, ADC_IT_EOC, ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 15;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	
	ADC_Cmd(ADCx, ENABLE);
	//Select the channel to be read from
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_480Cycles);*/
	
}



void analogInitChannel(ADC_TypeDef * ADCx, uint8_t channel, uint8_t ADC_SampleTime)
{
	ADC_RegularChannelConfig(ADCx, channel, 1, ADC_SampleTime);
}



uint16_t analogReadPin(ADC_TypeDef * ADCx, uint8_t channel)
{
	ADC_SoftwareStartConv(ADCx);
	uint16_t xxx;
	while (xQueueReceive(analogINReadQueue, &xxx, portMAX_DELAY) != pdTRUE);

	return xxx;
			
}
