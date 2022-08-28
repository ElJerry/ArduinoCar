#include "ComponentManager.h"

ComponentManager *ComponentManager::instance = nullptr;

ComponentManager *ComponentManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ComponentManager();
        return instance;
    }

    return instance;
}

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

void ComponentManager::handleMessages(String message)
{
    for (KeyValueComponent registeredComponent : components)
    {
        registeredComponent.component->handleMessages(message);
    }
}

void ComponentManager::update()
{

    for (KeyValueComponent registeredComponent : components)
    {
        registeredComponent.component->update();
    }
}