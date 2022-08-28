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
    void setup();
    void handleInputs();
    void update();
    void handleMessages(String message);
};