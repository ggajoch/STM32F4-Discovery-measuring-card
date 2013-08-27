#ifndef __DIGITALIO_H__
#define __DIGITALIO_H__

#include <inttypes.h>
void digitalIOSetPinMode(u16_t pinNumber, GPIOMode_TypeDef direction, GPIOOType_TypeDef OutType, GPIOPuPd_TypeDef pullUps);

void digitalIOWritePin(uint8_t pinNumber, uint8_t pinValue);

uint8_t digitalIOreadPin(uint8_t pinNumber);

void digitalIOWritePort(uint16_t portValue);

uint16_t digitalIOReadPort();

void writeWaveform(uint16_t pin, uint16_t * values, uint8_t nrOfSamples, uint32_t period, uint16_t presc, uint8_t repetition);

void readWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays);
#endif
