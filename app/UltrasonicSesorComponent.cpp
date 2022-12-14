#include "UltrasonicSensorComponent.h"
#include "ComponentManager.h"
#include "ServoComponent.h"
#include "DcMotorsComponent.h"

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

void UltrasonicSensorComponent::handleMessages(String message)
{
}

void UltrasonicSensorComponent::update()
{
    int distance = distanceSensor->getDistanceInCentimeters();
}