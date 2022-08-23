#ifndef JERRY_MOTOR_DRIVER_H
#define JERRY_MOTOR_DRIVER_H

#include <stdint.h>

// based on a KS0448 Keyestudio L298P 4-Channel Motor Drive Shield
class DcMotorDriver
{
private:
    int pwmSpeedPin;
    int directionPin;
    uint8_t speed;
    uint8_t direction;

public:
    DcMotorDriver(int pwmSpeedPin, int directionPin);

    void setSpeed(uint8_t speed);
    void goForward();
    void goBackwards();

    void setup();
    void update();
};

#endif // JERRY_MOTOR_DRIVER_H