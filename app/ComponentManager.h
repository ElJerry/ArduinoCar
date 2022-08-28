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
    static ComponentManager *instance;

public:
    static ComponentManager *getInstance();
    void registerComponent(Component *component, String id);
    Component *getComponentById(String id);

    void setup();
    void handleInputs();
    void update();
    void handleMessages(String message);
};

#endif // JERRY_COMPONENT_MANAGER