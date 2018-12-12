#include "API.h"
#define Arduino

#ifdef pic18
#include "pic18Pins"
#endif

#ifdef pic32
#include "pic32Pins.h"
#endif

#ifdef Arduino 
#include "AtMega328Pins.h"
#endif

void setup(){
   //Reset IO to clear garbage and setup timers
  resetIO();

  //Flag to catch errors in setup
  bool error = false;

  //Setting up ports for input and output
  if (error = pinDirection(Led1, OUTPUT));
}

void loop(){
    setPin(Led1, HIGH,0);
}
