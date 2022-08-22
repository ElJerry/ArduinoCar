#include "UltrasonicSensorComponent.h"

UltrasonicSensorComponent::UltrasonicSensorComponent(int triggerPin, int echoPin)
{
    this->distanceSensor = new DistanceSensor(echoPin, triggerPin);
    this->echoPin = echoPin;
    this->triggerPin = triggerPin;
}

void UltrasonicSensorComponent::setup()
{
    distanceSensor->setup();
}

void UltrasonicSensorComponent::handleInputs()
{
}

void UltrasonicSensorComponent::update()
{
    float distance = distanceSensor->getDistanceInCentimeters();
    Serial.print("Distance: ");
    Serial.println(distance);
}