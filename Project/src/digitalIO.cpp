//FIXME
#include "arch/cc.h"
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_adc.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>

#define USING_GPIO GPIOD

#define ADD_AHB1 (RCC_AHB1Periph_ ## GPIOD)

void digitalIOSetPinMode(u8_t pinNumber, GPIOMode_TypeDef direction, GPIOOType_TypeDef OutType, GPIOPuPd_TypeDef pullUps)
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


void writeWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays, uint8_t repetition)
{
}

void readWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays)
{
}
