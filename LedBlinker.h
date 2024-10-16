#ifndef LED_BLINKER_H
#define LED_BLINKER_H

#include <Arduino.h> //dont need to have because we included Led.h
#include "Led.h"

class LedBlinker
{
private:
  Led led;

  void toggleLed();

public:
  LedBlinker() {} //do not use
  LedBlinker(Led &led);

  void initLed();   
};



#endif