#include "DistanceSensor.h"
#include "Servo.h"

const int servoPwmPin = 9;
const int distanceSensorTriggerPin = 2;
const int distanceSensorEchoPin = 3;

DistanceSensor distanceSensor(distanceSensorEchoPin, distanceSensorTriggerPin);
Servo servo;

void setup()
{
  Serial.begin(9600);
  distanceSensor.setup();
  servo.attach(servoPwmPin);
}

void loop()
{

  float distance = distanceSensor.getDistanceInCentimeters();
  Serial.println(distance);

  // for testin, controlling a servo with the distance
  int angle = map(distance, 0, 30, 0, 180);
  angle = min(180, angle);
  servo.write(angle);

  Serial.print("Angle: ");
  Serial.println(angle);
  delay(50);
}
