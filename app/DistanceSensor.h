#ifndef JERRY_DISTANCESENSOR_H
#define JERRY_DISTANCESENSOR_H

#include "Arduino.h"

class DistanceSensor
{

private:
    int echoPin, triggerPin;

    void triggerSensor();
    float readDurationFromEcho();

    DistanceSensor();

public:
    DistanceSensor(int echoPin, int triggerPin);

    float getDistanceInCentimeters();
    void setup();
};

#endif // JERRY_DISTANCESENSOR_H