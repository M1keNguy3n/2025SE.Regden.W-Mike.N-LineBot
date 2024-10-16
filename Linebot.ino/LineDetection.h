#ifndef LINE_DETECTION_H 
#define LINE_DETECTION_H 
 
class LineDetection { 
private: 
    int leftSensorPin; 
    int rightSensorPin; 
 
public: 
    LineDetection(int leftPin, int rightPin); 
    void init(); 
    int readLeftSensor(); 
    int readRightSensor(); 
    int readLeftAnalog(); 
    int readRightAnalog(); 
}; 
 
#endif