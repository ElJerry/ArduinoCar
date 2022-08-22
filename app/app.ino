#include "DistanceSensor.h"
#include "Servo.h"
#include "Component.h"
#include "LedComponent.h"

#include <ArduinoSTL.h>

const int servoPwmPin = 9;
const int distanceSensorTriggerPin = 2;
const int distanceSensorEchoPin = 3;
const int ledPin = 4;

DistanceSensor distanceSensor(distanceSensorEchoPin, distanceSensorTriggerPin);
Servo servo;
std::vector<Component *> components;

// define components
LedComponent ledComponent(ledPin, 500);

void setup()
{
  Serial.begin(9600);
  ledComponent.setup();

  components.push_back(&ledComponent);
}

void loop()
{
  // handle inputs
  for (int i = 0; i < components.size(); i++)
  {
    Component *component = components[i];
    component->handleInputs();
  }

  // update components
  for (int i = 0; i < components.size(); i++)
  {
    Component *component = components[i];
    component->update();
  }
}
