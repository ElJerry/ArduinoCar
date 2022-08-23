#ifndef JERRY_DCMOTORCOMPONENT_H
#define JERRY_DCMOTORCOMPONENT_H

#include "Component.h"
#include "DcMotorDriver.h"

#include <ArduinoSTL.h>

class DcMotorsComponent : public Component
{
private:
    std::vector<DcMotorDriver> motors;

public:
    void attachMotor(int pwmPin, int directionPin);

    void goForward();
    void goBackwards();
    void stopMotors();
    void setSpeed(uint8_t speed);

    void setup();
    void handleInputs();
    void update();
};

#endif //JERRY_DCMOTORCOMPONENT_H