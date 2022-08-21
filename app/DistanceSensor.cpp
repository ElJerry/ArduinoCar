#include "DistanceSensor.h"

const float SOUND_SPEED = .032;

DistanceSensor::DistanceSensor(int echoPin, int triggerPin)
{
    this->echoPin = echoPin;
    this->triggerPin = triggerPin;

    // Setup pins
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
}

void DistanceSensor::setup()
{
    // Setup pins
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
    digitalWrite(triggerPin, LOW);
}

void DistanceSensor::triggerSensor()
{
    digitalWrite(triggerPin, LOW);
    delay(2);

    digitalWrite(triggerPin, HIGH);
    delay(20);

    digitalWrite(triggerPin, LOW);
}

float DistanceSensor::readDurationFromEcho()
{
    return pulseIn(echoPin, HIGH);
}

float DistanceSensor::getDistanceInCentimeters()
{
    triggerSensor();
    float duration = readDurationFromEcho();
    return duration * SOUND_SPEED / 2; // we want the distance, so we divide by 2 to get only one trip
}