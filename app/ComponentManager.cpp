#include "ComponentManager.h"

void ComponentManager::registerComponent(Component *component, String id)
{
    if (component == nullptr)
    {
        return;
    }

    // check if the id is already registered
    Component *registeredComponent = getComponentById(id);
    if (registeredComponent != nullptr)
    {
        return;
    }

    // add to the vector
    components.push_back({id, component});
}

Component *ComponentManager::getComponentById(String id)
{
    for (KeyValueComponent registeredComponent : components)
    {
        if (registeredComponent.id == id)
        {
            return registeredComponent.component;
        }
    }
    return nullptr;
}

void ComponentManager::setup()
{
    for (KeyValueComponent registeredComponent : components)
    {
        registeredComponent.component->setup();
    }
}

void ComponentManager::handleInputs()
{
    for (KeyValueComponent registeredComponent : components)
    {
        registeredComponent.component->handleInputs();
    }
}

void ComponentManager::update()
{

    for (KeyValueComponent registeredComponent : components)
    {
        registeredComponent.component->update();
    }
}