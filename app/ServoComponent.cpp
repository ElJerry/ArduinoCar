#include "ServoComponent.h"

ServoComponent::ServoComponent(int pwmPin)
{
    this->servoPin = pwmPin;
}

void ServoComponent::setup()
{
    servo.attach(servoPin);
}

void ServoComponent::handleInputs()
{
}

void ServoComponent::handleMessages(String message)
{
}

void ServoComponent::update()
{
    servo.write(angle);
}

void ServoComponent::setAngle(int angle)
{
    this->angle = angle;
}