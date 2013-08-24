//FIXME
#include "arch/cc.h"
#include "errorHandlers.h"
extern "C" {
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_adc.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>
#include <stm32f4xx_dac.h>
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

void internalDAC_Init(uint8_t pin) // 0 - PA4, 1 - PA5
{
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
	GPIO_InitTypeDef GPIO_InitStructure;
	DAC_InitTypeDef DAC_InitStructure;
	
	if( pin == 0 )
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_4;
	else if( pin == 1 )
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5;
	else 
	{
		send_error_code(4);
		return;
	}
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
  DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
  DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	
	if( pin == 0 )
	{
		DAC_Init(DAC_Channel_1, &DAC_InitStructure);
		DAC_Cmd(DAC_Channel_1, ENABLE);
	}
	else if( pin == 1 )
	{
		DAC_Init(DAC_Channel_2, &DAC_InitStructure);
		DAC_Cmd(DAC_Channel_2, ENABLE);
	}
  
  /* Enable DAC Channel1: Once the DAC channel1 is enabled, PA.04 is 
     automatically connected to the DAC converter. */
  
}

void internalDAC_Write(uint8_t pin, uint16_t value, uint8_t align)
{
	uint16_t al = (align);
	al <<= 2;
	if( pin == 0 )
	{
		DAC_SetChannel1Data(al, value);
	}
	else if( pin == 1 )
	{
		DAC_SetChannel2Data(al, value);
	}
	else
		send_error_code(4);
}


