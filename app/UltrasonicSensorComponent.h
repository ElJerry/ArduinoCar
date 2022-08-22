#ifndef JERRY_ULTRASONIC_SENSOR_CMP
#define JERRY_ULTRASONIC_SENSOR_CMP

#include "Component.h"
#include "DistanceSensor.h"

class UltrasonicSensorComponent : public Component
{
private:
    int triggerPin, echoPin;
    DistanceSensor *distanceSensor;

public:
    UltrasonicSensorComponent(int triggerPin, int echoPin);

    void setup();
    void handleInputs();
    void update();
};

#endif // JERRY_ULTRASONIC_SENSOR_CMP