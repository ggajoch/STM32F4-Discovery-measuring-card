//FIXME
#include "arch/cc.h"
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_adc.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>

#include "timers.h"

#define USING_GPIO GPIOD

#define ADD_AHB1 (RCC_AHB1Periph_ ## GPIOD)

void digitalIOSetPinMode(u16_t pinNumber, GPIOMode_TypeDef direction, GPIOOType_TypeDef OutType, GPIOPuPd_TypeDef pullUps)
{
	/*ADC_InitTypeDef ADCInit;
	ADCInit.ADC_NbrOfConversion;
	ADCInit.ADC_Resolution;
	//length of conversion*/
	
	//RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC->AHB1ENR |= ADD_AHB1;
	GPIO_InitTypeDef GPIOStruct;
	GPIOStruct.GPIO_Mode = direction;
	GPIOStruct.GPIO_OType = OutType;
	GPIOStruct.GPIO_Pin  = pinNumber;
	GPIOStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIOStruct.GPIO_Speed = GPIO_Speed_100MHz;	
	GPIO_Init(USING_GPIO, &GPIOStruct);
}

void digitalIOWritePin(uint8_t pinNumber, uint8_t pinValue)
{
	USING_GPIO->ODR = (pinValue << pinNumber);
}

uint8_t digitalIOreadPin(uint8_t pinNumber)
{
	return (USING_GPIO->IDR & (1 << pinNumber));
}

void digitalIOWritePort(uint16_t portValue)
{
	USING_GPIO->ODR = portValue;
}

uint16_t digitalIOReadPort()
{
	return USING_GPIO->IDR;
}


uint8_t WriteMode = 0, ReadMode = 0;
uint16_t waveformSamples[1000];
uint16_t OutNrOfSamples, OutActualSample, OutSamplePos, OutPin;

extern "C" void TIM4_IRQHandler()
{
	if( TIM_GetITStatus(TIM4, TIM_IT_Update) )
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
		
		if( WriteMode )
		{
			//GPIO_WriteBit(GPIOD, OutPin, ));
			if( waveformSamples[OutActualSample] & ( 1 << OutSamplePos ) )
			{
				//GPIOD->ODR |= OutPin;
				GPIOD->BSRRL |= OutPin;
			}
			else
			{
				//GPIOD->ODR &= ~(OutPin);
				GPIOD->BSRRH |= OutPin;
			}
			++OutSamplePos;
			if( OutSamplePos == 16 )
			{
				OutSamplePos = 0;
				++OutActualSample;
			}
			if( OutActualSample == OutNrOfSamples )
			{
				OutActualSample = 0;
			}
		}
		if( ReadMode )
		{
		}
		
		
	}
}

void writeWaveform(uint16_t pin, uint16_t * values, uint8_t nrOfSamples, uint32_t period, uint16_t presc, uint8_t repetition)
{
	for(uint16_t i = 0; i < nrOfSamples; ++i)
	{
		waveformSamples[i] = values[i];
	}
	//waveformSamples = values;
	OutPin = pin;
	OutNrOfSamples = nrOfSamples;
	OutActualSample = 0;
	OutSamplePos = 0;
	TIMER_Init(TIM4, period, presc, true, TIM4_IRQn);	
}

void readWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays)
{
}
