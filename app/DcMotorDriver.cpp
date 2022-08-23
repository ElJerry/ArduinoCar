#include "DcMotorDriver.h"
#include "Arduino.h"

DcMotorDriver::DcMotorDriver(int pwmSpeedPin, int directionPin)
{
    this->directionPin = directionPin;
    this->pwmSpeedPin = pwmSpeedPin;
}

void DcMotorDriver::setSpeed(uint8_t speed)
{
    this->speed = speed;
}

void DcMotorDriver::goForward()
{
    direction = HIGH;
}

void DcMotorDriver::goBackwards()
{
    direction = LOW;
}

void DcMotorDriver::setup()
{
    pinMode(pwmSpeedPin, OUTPUT);
    pinMode(directionPin, OUTPUT);

    // defaulting to forward
    direction = HIGH;

    // starting with speed 0
    speed = 0;
}

void DcMotorDriver::update()
{
    digitalWrite(directionPin, direction);
    analogWrite(pwmSpeedPin, speed);
}