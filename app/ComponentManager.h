#ifndef JERRY_COMPONENT_MANAGER
#define JERRY_COMPONENT_MANAGER

#include "Component.h"

#include <ArduinoSTL.h>

class ComponentManager
{
private:
    // TODO: Extract to a generic data structures file
    struct KeyValueComponent
    {
        String id;
        Component *component;
    };

    std::vector<KeyValueComponent> components;

public:
    void registerComponent(Component *component, String id);
    Component *getComponentById(String id);

    void setup();
    void handleInputs();
    void update();
};

#endif // JERRY_COMPONENT_MANAGER