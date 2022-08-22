#include "DistanceSensor.h"
#include "Servo.h"
#include "Component.h"
#include "LedComponent.h"
#include "UltrasonicSensorComponent.h"

#include <ArduinoSTL.h>

const int servoPwmPin = 9;
const int distanceSensorTriggerPin = 2;
const int distanceSensorEchoPin = 3;
const int ledPin = 4;

std::vector<Component *> components;

// define components
LedComponent ledComponent(ledPin, 500);
UltrasonicSensorComponent ultrasonicSensorComponent(distanceSensorTriggerPin, distanceSensorEchoPin);

void setup()
{
  Serial.begin(9600);
  ledComponent.setup();
  ultrasonicSensorComponent.setup();

  components.push_back(&ledComponent);
  components.push_back(&ultrasonicSensorComponent);
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
