#include "Component.h"
class LedComponent : virtual public Component
{
private:
    int ledPin;
    int interval;
    int ledState = 0;

    int mode = 0;

    unsigned long lastExecution;
    unsigned long nextExecution;

public:
    LedComponent(int ledPin, int interval);
    virtual void setup();
    virtual void handleInputs();
    virtual void update();
};