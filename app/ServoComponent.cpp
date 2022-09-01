#include "ServoComponent.h"

const int FRONT_ANGLE = 98;

ServoComponent::ServoComponent(int pwmPin)
{
    this->servoPin = pwmPin;
}

void ServoComponent::setup()
{
    servo.attach(servoPin);
    angle = FRONT_ANGLE;
}

void ServoComponent::handleInputs()
{
}

void ServoComponent::handleMessages(String message)
{

    if (message.equals("SERVO:LEFT"))
    {
        setAngle(FRONT_ANGLE - 45);
    }

    if (message.equals("SERVO:RIGHT"))
    {
        setAngle(FRONT_ANGLE + 45);
    }

    if (message.equals("SERVO:FRONT"))
    {
        setAngle(FRONT_ANGLE);
    }

    if (message.startsWith("SERVO:ANGLE:"))
    {
        String angleStr = message.substring(12);
        int angleInt = angleStr.toInt();
        Serial.println(angleInt);
        setAngle(angleInt);
    }
}

void ServoComponent::update()
{
    servo.write(angle);
}

void ServoComponent::setAngle(int angle)
{
    this->angle = angle;
}