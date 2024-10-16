#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
protected:
    int pin;

public:
    Sensor(int p);
    virtual int readValue() = 0; // Abstract method
};

class LineSensor : public Sensor {
private:
    int threshold;

public:
    LineSensor(int p, int thresh);
    int readValue() override;
    bool isOnLine();
};

#endif
