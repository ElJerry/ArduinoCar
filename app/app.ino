#include "DistanceSensor.h"
#include "Servo.h"
#include "Component.h"
#include "LedComponent.h"
#include "UltrasonicSensorComponent.h"
#include "ComponentManager.h"
#include "ServoComponent.h"

#include <ArduinoSTL.h>

const int distanceSensorTriggerPin = 2;
const int distanceSensorEchoPin = 3;
const int ledPin = 4;
const int servoPwmPin = 9;

// component manager
ComponentManager *componentManager;

// define components
LedComponent ledComponent(ledPin, 500);
UltrasonicSensorComponent ultrasonicSensorComponent(distanceSensorTriggerPin, distanceSensorEchoPin);
ServoComponent servoComponent(servoPwmPin);

void setup()
{
  Serial.begin(9600);

  componentManager = ComponentManager::getInstance();

  componentManager->registerComponent(&servoComponent, "Servo");
  componentManager->registerComponent(&ledComponent, "LedComponent");
  componentManager->registerComponent(&ultrasonicSensorComponent, "UltrasonicSensor");

  componentManager->setup();
}

void loop()
{
  componentManager->handleInputs();
  componentManager->update();
}
