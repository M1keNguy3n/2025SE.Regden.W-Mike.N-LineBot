#ifndef LINE_DETECTION_H
#define LINE_DETECTION_H


class LineDetection {
public:
    LineDetection(int leftPin, int rightPin);
    void init();
    int detectLine();
private:
    int leftSensorPin;
    int rightSensorPin;
};


#endif



