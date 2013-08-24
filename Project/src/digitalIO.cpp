//FIXME
#include "arch/cc.h"
#include <stm32f4xx_gpio.h>
<<<<<<< HEAD
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
=======
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_tim.h>

#define USING_GPIO GPIOA


void digitalIOSetPinMode(u8_t pinNumber, u8_t direction)
{
	//RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC->AHB1ENR |= RCC_AHB1Periph_GPIOA;
	GPIO_InitTypeDef GPIOStruct;
	if( direction == 0 )
	{
			GPIOStruct.GPIO_Mode = GPIO_Mode_IN;
	}
	else 
	{
			GPIOStruct.GPIO_Mode = GPIO_Mode_OUT;
	}
	GPIOStruct.GPIO_OType = GPIO_OType_PP;
>>>>>>> 4d952ce31d2b42dcf8df8c3f090d012ebe0be2d7
	GPIOStruct.GPIO_Pin  = pinNumber;
	GPIOStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIOStruct.GPIO_Speed = GPIO_Speed_100MHz;	
	GPIO_Init(USING_GPIO, &GPIOStruct);
}

void digitalIOWritePin(uint8_t pinNumber, uint8_t pinValue)
{
	USING_GPIO->ODR = (pinValue << pinNumber);
}

<<<<<<< HEAD
uint8_t digitalIOreadPin(uint8_t pinNumber)
=======
uint8_t digitalIOreadPinValue(uint8_t pinNumber)
>>>>>>> 4d952ce31d2b42dcf8df8c3f090d012ebe0be2d7
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

<<<<<<< HEAD

=======
>>>>>>> 4d952ce31d2b42dcf8df8c3f090d012ebe0be2d7
void writeWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays, uint8_t repetition)
{
}

void readWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays)
{
}
