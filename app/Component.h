#ifndef JERRY_COMPONENT_H
#define JERRY_COMPONENT_H

class Component
{
private:
public:
    virtual void setup() = 0;
    virtual void handleInputs() = 0;
    virtual void update() = 0;
};
#endif // JERRY_COMPONENT_H