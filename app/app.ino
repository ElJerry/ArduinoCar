#include "DistanceSensor.h"
#include "Servo.h"
#include "Component.h"
#include "LedComponent.h"
#include "UltrasonicSensorComponent.h"
#include "ComponentManager.h"
#include "ServoComponent.h"
#include "DcMotorDriver.h"
#include "DcMotorsComponent.h"
#include "SerialMessageReader.h"

#include <stdint.h>
#include <ArduinoSTL.h>

// Define pins to be used
const int distanceSensorTriggerPin = 12;
const int distanceSensorEchoPin = 11;
const int ledPin = 8;
const int servoPwmPin = 9;

const int motorAPwm = 6;
const int motorADirection = 3;

const int motorBPwm = 5;
const int motorBDirection = 4;

// component manager
ComponentManager *componentManager;

// define components
LedComponent ledComponent(ledPin, 500);
UltrasonicSensorComponent ultrasonicSensorComponent(distanceSensorTriggerPin, distanceSensorEchoPin);
ServoComponent servoComponent(servoPwmPin);
DcMotorsComponent dcMotorsComponent;

void setup()
{
  Serial.begin(9600);

  // register DcMotors
  dcMotorsComponent.attachMotor(motorAPwm, motorADirection, 0);
  dcMotorsComponent.attachMotor(motorBPwm, motorBDirection, 14);

  componentManager = ComponentManager::getInstance();

  componentManager->registerComponent(&servoComponent, "Servo");
  componentManager->registerComponent(&ledComponent, "LedComponent");
  componentManager->registerComponent(&ultrasonicSensorComponent, "UltrasonicSensor");
  componentManager->registerComponent(&dcMotorsComponent, "DcMotors");

  componentManager->setup();

  // delaying 2 seconds post upload
  delay(2000);
}

void loop()
{

  // read for serial messages
  String message = readSerialMessage();
  componentManager->handleMessages(message);
  componentManager->handleInputs();
  componentManager->update();
}
