#include "DistanceSensor.h"
#include "Servo.h"
#include "Component.h"
#include "LedComponent.h"
#include "UltrasonicSensorComponent.h"
#include "ComponentManager.h"

#include <ArduinoSTL.h>

const int distanceSensorTriggerPin = 2;
const int distanceSensorEchoPin = 3;
const int ledPin = 4;
const int servoPwmPin = 9;

// component manager
ComponentManager componentManager;

// define components
LedComponent ledComponent(ledPin, 500);
UltrasonicSensorComponent ultrasonicSensorComponent(distanceSensorTriggerPin, distanceSensorEchoPin);

void setup()
{
  Serial.begin(9600);

  componentManager.registerComponent(&ledComponent, "LedComponent");
  componentManager.registerComponent(&ultrasonicSensorComponent, "UltrasonicSensor");

  componentManager.setup();
}

void loop()
{
  componentManager.handleInputs();

  componentManager.update();
}
