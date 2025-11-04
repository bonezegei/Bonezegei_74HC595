/*
  Bonezegei 74HC595 library
  Author: Bonezegei (Jofel Batutay)
  Date : November 4 2025
*/



#ifndef _BONEZEGEI_74HC595_H_
#define _BONEZEGEI_74HC595_H_
#include <Arduino.h>


class Bonezegei_74HC595 {
  public:
    Bonezegei_74HC595(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t numRegisters=1);
    void begin();
    void shift8(uint8_t data);
    void write(uint64_t data);
    void clear();
  //private:
    uint8_t _dataPin;
    uint8_t _clockPin;
    uint8_t _latchPin;
    uint8_t _numRegisters;
};

#endif
