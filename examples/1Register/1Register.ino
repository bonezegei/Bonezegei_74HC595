/*
  Bonezegei_74HC595 Usage
  Author: Jofel Batutay (Bonezegei)
  Date: November 4 2025
*/

#include <Bonezegei_74HC595.h>

#define PIN_DATA  14
#define PIN_CLK   27
#define PIN_LATCH 26

/*
  Set pins and number of registers
  @param dataPin   : Data Pin
  @param clockPin  : Clock Pin  
  @param latchPin  : Latch Pin
  @param numRegisters: Number of Registers (default is 1) this corresponds to the number of daisy chained 74HC595
*/
Bonezegei_74HC595 reg(PIN_DATA, PIN_CLK, PIN_LATCH);

void setup() {

  // initialize the 74HC595
  reg.begin();

  reg.clear();     // clear all outputs
  reg.write(0xff); // set all outputs HIGH
  delay(1000);
}

void loop() {

  for(int a=0; a<8; a++){
    reg.write(0xff>>a);   
    delay(100);
  }

  for(int a=7; a>0; a--){
    reg.write(0xff>>a);
    delay(100);
  }

    for(int a=0; a<8; a++){
    reg.write(0xff<<a);
    delay(100);
  }

  for(int a=7; a>0; a--){
    reg.write(0xff<<a);
    delay(100);
  }

}
