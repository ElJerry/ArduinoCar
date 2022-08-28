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
}

void LedComponent::handleMessages(String message)
{
    if (message.equals("LED1"))
    {
        ledState = HIGH;
    }

    if (message.equals("LED0"))
    {
        ledState = LOW;
    }

    if (message.equals("LEDB"))
    {
        mode = 0;
    }

    if (message.equals("LEDM"))
    {
        mode = 1;
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