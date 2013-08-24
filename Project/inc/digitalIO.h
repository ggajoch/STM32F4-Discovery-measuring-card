#ifndef __DIGITALIO_H__
#define __DIGITALIO_H__

#include <inttypes.h>
<<<<<<< HEAD
void digitalIOSetPinMode(u8_t pinNumber, GPIOMode_TypeDef direction, GPIOOType_TypeDef OutType, GPIOPuPd_TypeDef pullUps);

void digitalIOWritePin(uint8_t pinNumber, uint8_t pinValue);

uint8_t digitalIOreadPin(uint8_t pinNumber);
=======
void digitalIOSetPinMode(uint8_t pinNumber, uint8_t direction);

void digitalIOWritePin(uint8_t pinNumber, uint8_t pinValue);

uint8_t digitalIOreadPinValue(uint8_t pinNumber);
>>>>>>> 4d952ce31d2b42dcf8df8c3f090d012ebe0be2d7

void digitalIOWritePort(uint16_t portValue);

uint16_t digitalIOReadPort();

void writeWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays, uint8_t repetition);

void readWaveform(uint8_t pin, uint8_t * values, uint8_t nrOfSamples, uint8_t delays);
#endif
