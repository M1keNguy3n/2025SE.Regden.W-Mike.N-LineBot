#include "Control.h" 
#include <string.h> 
#include <arduino.h>
 
Control::Control() { 
    memset(frame, 0, sizeof(frame)); 
} 
 
void Control::init() { 
    matrix.begin(); 
} 
 
void Control::displayVersion(const char* version) { 
    matrix.clear(); 
    matrix.print(version); 
    delay(2000); // Display the version for 2 seconds 
} 
 
void Control::displayLineStatus(bool onBlack) { 
    matrix.clear(); 
    if (onBlack) { 
        matrix.print("ON BLACK"); 
    } else { 
        matrix.print("NOT BLACK"); 
    } 
    delay(1000); 
} 
 