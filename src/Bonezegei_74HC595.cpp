#include "Bonezegei_74HC595.h"


Bonezegei_74HC595::Bonezegei_74HC595(int dataPin, int clockPin, int latchPin, int numRegisters) {
        _dataPin = dataPin;
        _clockPin = clockPin;
        _latchPin = latchPin;
        _numRegisters = numRegisters;
        
        pinMode(_dataPin, OUTPUT);
        pinMode(_clockPin, OUTPUT);
        pinMode(_latchPin, OUTPUT);
}

void Bonezegei_74HC595::begin() {
    digitalWrite(_latchPin, LOW);
    clear();
    digitalWrite(_latchPin, HIGH);
}


void Bonezegei_74HC595::shift8(uint8_t data) {
    for(int i = 0; i < 8; i++) {
        digitalWrite(_clockPin, LOW);
        digitalWrite(_dataPin, (data & (1 << (7 - i))) ? HIGH : LOW);
        digitalWrite(_clockPin, HIGH);
    }
}


void Bonezegei_74HC595::write(uint64_t data) {
    digitalWrite(_latchPin, LOW);
    for (size_t i = 0; i < _numRegisters; i++){
        shift8((data >> (8 * (_numRegisters - 1 - i))) & 0xFF);
    }
    digitalWrite(_latchPin, HIGH);
}     

void Bonezegei_74HC595::clear() {
    digitalWrite(_latchPin, LOW);
    for (int i = 0; i < _numRegisters; i++) {
        shift8(0x00);
    }
    digitalWrite(_latchPin, HIGH);
}

