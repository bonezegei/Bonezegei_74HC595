/*
  Bonezegei 74HC595 library
  Author: Bonezegei (Jofel Batutay)
  Date : November 4 2025
*/

#include <Arduino.h>

#ifndef _BONEZEGEI_74HC595_H_
#define _BONEZEGEI_74HC595_H_

class Bonezegei_74HC595 {
public:
  Bonezegei_74HC595(int dataPin, int clockPin, int latchPin, int numRegisters = 1);
  void begin();
  void shift8(uint8_t data);
  void write(uint64_t data);
  void clear();
//private:
  int _dataPin;
  int _clockPin;
  int _latchPin;
  int _numRegisters;
};

#endif
