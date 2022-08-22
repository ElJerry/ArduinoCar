#ifndef JERRY_LEDCOMPONENT_H
#define JERRY_LEDCOMPONENT_H

#include "LedComponent.h"
#include "Arduino.h"

LedComponent::LedComponent(int ledPin, int interval)
{
    this->ledPin = ledPin;
    this->interval = interval;
}

void LedComponent::setup()
{
    pinMode(ledPin, OUTPUT);
    lastExecution = millis();
    nextExecution = lastExecution + interval;
}

void LedComponent::handleInputs()
{
    if (Serial.available() > 0)
    {
        // read instruction
        char instruction = Serial.read();
        Serial.print("=");
        Serial.print(instruction);
        Serial.println("=");

        // for serial control, enables led
        if (instruction == '1')
        {
            ledState = HIGH;
        }

        // for serial control, disables led
        if (instruction == '0')
        {
            ledState = LOW;
        }

        // enables blinking mode
        if (instruction == 'q')
        {
            mode = 0;
        }

        // enables serial control mode
        if (instruction == 'w')
        {
            mode = 1;
        }
    }
}

void LedComponent::update()
{

    // mode a blinks, mode b enables serial control

    if (mode == 0)
    {
        unsigned long currentMillis = millis();

        if (currentMillis >= nextExecution)
        {
            // toggle led
            digitalWrite(ledPin, !digitalRead(ledPin));
            // Serial.println("toggling!");

            // set next toggle time
            nextExecution = currentMillis + interval;
            lastExecution = currentMillis;
        }
    }

    if (mode == 1)
    {
        digitalWrite(ledPin, ledState);
    }
}

#endif //JERRY_LEDCOMPONENT_H