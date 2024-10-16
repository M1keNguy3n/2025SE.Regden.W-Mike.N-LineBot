#ifndef CONTROL_H 
#define CONTROL_H 

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h" 
 
class Control { 
private: 
    ArduinoLEDMatrix matrix; 
    uint8_t frame[8][12]; 
 
public: 
    Control(); 
    void init(); 
    void displayVersion(const char* version); 
    void displayLineStatus(bool onBlack); 
}; 
 
#endif 
 