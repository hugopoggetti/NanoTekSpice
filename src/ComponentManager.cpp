/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** Component.cpp
*/

#include "ComponentManager.hpp"
#include "2716Component.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "AndComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include "NotComponent.hpp"
#include "ClockComponent.hpp"
#include "XorComponent.hpp"
#include "OrComponent.hpp"
#include "4001Component.hpp"
#include "4011Component.hpp"
#include "4030Component.hpp"
#include "4069Component.hpp"
#include "4071Component.hpp"
#include "4081Component.hpp"
#include "4008Component.hpp"
#include "4801Component.hpp"
#include "4013Component.hpp"
#include "4017Component.hpp"
#include "4040Component.hpp"
#include "4094Component.hpp"
#include "4512Component.hpp"
#include "4514Component.hpp"
#include "LoggerComponent.hpp"

// Constructor which take a component name given in paramter
nts::ComponentManager::ComponentManager(const std::string componentName) : _componentName(componentName) {}

// Create a specific component with a type string for access a function in the factory
std::unique_ptr<nts::IComponent> nts::ComponentManager::createComponent(const std::string &type)
{
    return (*_creation.find(type)).second();
}

// Create input component
std::unique_ptr<nts::IComponent> nts::ComponentManager::createInput() const
{
    return std::unique_ptr<nts::IComponent>(new InputComponent(_componentName));
}

// Create output component
std::unique_ptr<nts::IComponent> nts::ComponentManager::createOutput() const
{
    return std::unique_ptr<nts::IComponent>(new OutputComponent(_componentName));
}

// Create true component
std::unique_ptr<nts::IComponent> nts::ComponentManager::createTrue() const
{
    return std::unique_ptr<nts::IComponent>(new TrueComponent(_componentName));
}

// Create false component
std::unique_ptr<nts::IComponent> nts::ComponentManager::createFalse() const
{
    return std::unique_ptr<nts::IComponent>(new FalseComponent(_componentName));
}

// Create clock component
std::unique_ptr<nts::IComponent> nts::ComponentManager::createClock() const
{
    return std::unique_ptr<nts::IComponent>(new ClockComponent(_componentName));
}

// Create not component
std::unique_ptr<nts::IComponent> nts::ComponentManager::createNot() const
{
    return std::unique_ptr<nts::IComponent>(new NotComponent(_componentName));
}


std::unique_ptr<nts::IComponent> nts::ComponentManager::createAnd() const
{
    return std::unique_ptr<nts::IComponent>(new AndComponent(_componentName));
}

// Create xor component
std::unique_ptr<nts::IComponent> nts::ComponentManager::createXor() const
{
    return std::unique_ptr<nts::IComponent>(new XorComponent(_componentName));
}

// Create or component
std::unique_ptr<nts::IComponent> nts::ComponentManager::createOr() const
{
    return std::unique_ptr<nts::IComponent>(new OrComponent(_componentName));
}

// Create 4001 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4001() const
{
    return std::unique_ptr<nts::IComponent>(new Component4001(_componentName));
}

// Create 4011 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4011() const
{
    return std::unique_ptr<nts::IComponent>(new Component4011(_componentName));
}

// Create 4030 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4030() const
{
    return std::unique_ptr<nts::IComponent>(new Component4030(_componentName));
}

// Create 4069 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4069() const
{
    return std::unique_ptr<nts::IComponent>(new Component4069(_componentName));
}

// Create 4071 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4071() const
{
    return std::unique_ptr<nts::IComponent>(new Component4071(_componentName));
}

// Create 4081 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4081() const
{
    return std::unique_ptr<nts::IComponent>(new Component4081(_componentName));
}

// Create 4008 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4008() const
{
    return std::unique_ptr<nts::IComponent>(new Component4008(_componentName));
}

// Create 4013 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4013() const
{
    return std::unique_ptr<nts::IComponent>(new Component4013(_componentName));
}

// Create 4017 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4017() const
{
    return std::unique_ptr<nts::IComponent>(new Component4017(_componentName));
}

// Create 4040 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4040() const
{
    return std::unique_ptr<nts::IComponent>(new Component4040(_componentName));
}

// Create 4094 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4094() const
{
    return std::unique_ptr<nts::IComponent>(new Component4094(_componentName));
}

// Create 4512 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4512() const
{
    return std::unique_ptr<nts::IComponent>(new Component4512(_componentName));
}

// Create 4514 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4514() const
{
    return std::unique_ptr<nts::IComponent>(new Component4514(_componentName));
}

// Create 4801 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create4801() const
{
    return std::unique_ptr<nts::IComponent>(new Component4801(_componentName));
}

// Create 2716 component
std::unique_ptr<nts::IComponent> nts::ComponentManager::create2716() const
{
    return std::unique_ptr<nts::IComponent>(new Component2716(_componentName));
}

std::unique_ptr<nts::IComponent> nts::ComponentManager::createLogger() const
{
    return std::unique_ptr<nts::IComponent>(new LoggerComponent(_componentName));
}
