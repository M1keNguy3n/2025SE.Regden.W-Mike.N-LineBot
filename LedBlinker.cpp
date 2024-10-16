#include "LedBlinker.h"

LedBlinker::LedBlinker(Led &led)
{
  this->led = led;
}

void LedBlinker::initLed()
{
  led.init();

}   

void LedBlinker::toggleLed()
{
  led.toggle();
}