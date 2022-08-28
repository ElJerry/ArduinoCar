#ifndef JERRY_COMPONENT_H
#define JERRY_COMPONENT_H

#include "Arduino.h"

class Component
{
private:
public:
    virtual void setup() = 0;
    virtual void handleInputs() = 0;
    virtual void update() = 0;
    virtual void handleMessages(String message) = 0;
};
#endif // JERRY_COMPONENT_H