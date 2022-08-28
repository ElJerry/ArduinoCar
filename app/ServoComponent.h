#include "Component.h"

#include <Servo.h>

class ServoComponent : public Component
{
private:
    int servoPin;
    int angle = 0;

    Servo servo;

public:
    ServoComponent(int pwmPin);

    void setup();
    void handleInputs();
    void update();
    void setAngle(int angle);
    void handleMessages(String message);
};