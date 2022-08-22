#include "UltrasonicSensorComponent.h"
#include "ComponentManager.h"
#include "ServoComponent.h"

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
    int distance = distanceSensor->getDistanceInCentimeters();

    int angle = map(distance, 0, 20, 0, 180);
    auto servo = (ServoComponent *)ComponentManager::getInstance()->getComponentById("Servo");
    servo->setAngle(angle);

    Serial.print("Distance: ");
    Serial.println(distance);
}