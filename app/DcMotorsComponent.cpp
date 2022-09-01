#include "DcMotorsComponent.h"
#include <ArduinoSTL.h>

void DcMotorsComponent::attachMotor(int pwmPin, int directionPin, uint8_t offset)
{
    DcMotorDriver driver(pwmPin, directionPin);
    driver.setOffset(offset);
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
        return;
    }

    if (message.equals("MOTOR0"))
    {
        setSpeed(0);
        return;
    }

    if (message.equals("MOTOR:BACKWARDS"))
    {
        goBackwards();
    }

    if (message.equals("MOTOR:FORWARD"))
    {
        goForward();
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
        return;
    }

    if (message.startsWith("MOTOROFFSET:"))
    {
        // i.e MOTOROFFSET:0:50;
        // Set the motor in index 0 offset to 50;

        String offsetInfo = message.substring(12);
        // Serial.print("motor offset info: ");
        // Serial.println(offsetInfo);
        // int speedInt = speedStr.toInt();

        // setSpeed(std::min(speedInt, 250));

        // Serial.print("Setting speed: ");
        // Serial.println(speedInt);
        // Serial.print("String speed: ");
        // Serial.println(speedStr);
    }

    if (message.startsWith("INCREASE"))
    {
        motors[1].offset += 1;
    }

    if (message.startsWith("DECREASE"))
    {
        motors[1].offset -= 1;
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
