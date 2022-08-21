
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