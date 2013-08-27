#ifndef __DIGITALIO_H__
#define __DIGITALIO_H__

#include "commandProcessing.h"
#include "arch/cc.h"
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
#include <inttypes.h>


void digitalIOSetPinMode(u16_t pinNumber, GPIOMode_TypeDef direction, GPIOOType_TypeDef OutType, GPIOPuPd_TypeDef pullUps);

void digitalIOWritePin(uint8_t pinNumber, uint8_t pinValue);

uint8_t digitalIOreadPin(uint8_t pinNumber);

void digitalIOWritePort(uint16_t portValue);

uint16_t digitalIOReadPort();

void writeWaveform(uint16_t pin, uint16_t * values, uint8_t nrOfSamples, uint32_t period, uint16_t presc, uint8_t repetition);

void readWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays);



class BitTable 
{
private:
	uint16_t pointerAtInt, pointerAtElement;
public:
	#define WORD_SIZE 16
	uint8_t repeat;
	uint16_t * table;
	uint16_t elements;
	bool getActualValue()
	{
		return (table[pointerAtInt] & ( 1 << pointerAtElement ) );
	}
	void writeValue(bool x)
	{
		if( x )
			table[pointerAtInt] |= ( 1 << pointerAtElement );
		else
			table[pointerAtInt] &= (~( 1 << pointerAtElement ));
	}
	bool next_value()
	{
		if( pointerAtElement == 0 )
		{
			pointerAtElement = 15;
			++pointerAtInt;
		}
		else 
		{
			--pointerAtElement;
		}
		if( pointerAtInt == elements && !repeat) 
		{
			return false;
		}
		return true;
	}
	void resetCounter()
	{
		pointerAtElement = pointerAtInt = 0;
	}
};

struct GPIOWaveFormWriter : BitTable
{
public:
	uint16_t pins;
	void make_new_sample()
	{
		if( ! next_value() )
		{
			if( repeat )
			{
				resetCounter();
			}
			else 
			{
				return;
			}
		}
		if( getActualValue() )
		{
		GPIOD->BSRRL |= pins;
		}
		else
		{
			GPIOD->BSRRH |= pins;
		}
	}
};

struct GPIOWaveFormReader : BitTable
{
public:
	uint16_t ValuesTable[540];
	uint16_t pin;
	OnePacket ret;
	GPIOWaveFormReader()
	{
		ret.length = 540 | (1 << 13);
		this->table = &ValuesTable[0];
	}
	bool write_new_sample()
	{
		bool x = (GPIOD->ODR & pin);
		writeValue(x);
		if( pointerAtElement == 0 )
		{
			pointerAtElement = 15;
			++pointerAtInt;
		}
		else 
		{
			--pointerAtElement;
		}
		if( pointerAtInt == 270 )
		{
			send_half_transfer();
		}			
		if( pointerAtInt == elements ) 
		{
			send_transfer_complete();
			if( repeat )
			{
				pointerAtInt = 0;
				return true;
			}
			return false;
		}
		return true;
	}
	void send_half_transfer()
	{
		ret.data = (uint8_t *)(&this->ValuesTable[0]);
		xQueueSend(sendQueue, &ret, 0);
	}
	void send_transfer_complete()
	{
		ret.data = (uint8_t *)(&this->ValuesTable[270]);
		xQueueSend(sendQueue, &ret, 0);
	}
};


#endif
