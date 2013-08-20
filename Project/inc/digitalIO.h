#ifndef __DIGITALIO_H__
#define __DIGITALIO_H__

#include <inttypes.h>
void digitalIOSetPinMode(uint8_t pinNumber, uint8_t direction);

void digitalIOWritePin(uint8_t pinNumber, uint8_t pinValue);

uint8_t digitalIOreadPinValue(uint8_t pinNumber);

void digitalIOWritePort(uint16_t portValue);

uint16_t digitalIOReadPort();

void writeWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays, uint8_t repetition);

void readWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays);
#endif
