#include "DcMotorsComponent.h"
#include <ArduinoSTL.h>

void DcMotorsComponent::attachMotor(int pwmPin, int directionPin)
{
    DcMotorDriver driver(pwmPin, directionPin);
    motors.push_back(driver);

    Serial.print("Motors: ");
    Serial.println(motors.size());
}

void DcMotorsComponent::setup()
{
    for (int i = 0; i < motors.size(); i++)
    {
        DcMotorDriver *ptr = &motors[i];
        ptr->setup();
    }
}

void DcMotorsComponent::handleInputs()
{
}

void DcMotorsComponent::handleMessages(String message)
{
    if (message.equals("MOTOR1"))
    {
        setSpeed(50);
    }

    if (message.equals("MOTOR0"))
    {
        setSpeed(0);
    }

    if (message.startsWith("MOTORSPEED:"))
    {
        // i.e MOTORSPEED:50;
        // Set the speed to 50

        String speedStr = message.substring(11);
        int speedInt = speedStr.toInt();

        setSpeed(std::min(speedInt, 250));

        Serial.print("Setting speed: ");
        Serial.println(speedInt);
        Serial.print("String speed: ");
        Serial.println(speedStr);
    }
}

void DcMotorsComponent::update()
{
    for (int i = 0; i < motors.size(); i++)
    {
        DcMotorDriver *ptr = &motors[i];
        ptr->update();
    }
}

void DcMotorsComponent::goForward()
{
    for (int i = 0; i < motors.size(); i++)
    {
        DcMotorDriver *ptr = &motors[i];
        ptr->goForward();
    }
}

void DcMotorsComponent::goBackwards()
{
    for (int i = 0; i < motors.size(); i++)
    {
        DcMotorDriver *ptr = &motors[i];
        ptr->goBackwards();
    }
}

void DcMotorsComponent::stopMotors()
{
    for (int i = 0; i < motors.size(); i++)
    {
        DcMotorDriver *ptr = &motors[i];
        ptr->setSpeed(0);
    }
}

void DcMotorsComponent::setSpeed(uint8_t speed)
{
    for (int i = 0; i < motors.size(); i++)
    {
        DcMotorDriver *ptr = &motors[i];
        ptr->setSpeed(speed);
    }
}
