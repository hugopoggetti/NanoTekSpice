/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** Component.hpp
*/

#ifndef _COMPONENT_
    #define _COMPONENT_

#include "AComponent.hpp"

#include <string>
#include <memory>
#include <map>
#include <functional>

namespace nts
{
    class ComponentManager {
        public:
            ComponentManager(const std::string componentName);
            ~ComponentManager() = default;
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
        private:
            std::unique_ptr<nts::IComponent> createInput() const;
            std::unique_ptr<nts::IComponent> createOutput() const;
            std::unique_ptr<nts::IComponent> createTrue() const;
            std::unique_ptr<nts::IComponent> createFalse() const;
            std::unique_ptr<nts::IComponent> createClock() const;
            std::unique_ptr<nts::IComponent> createNot() const;
            std::unique_ptr<nts::IComponent> createAnd() const;
            std::unique_ptr<nts::IComponent> createXor() const;
            std::unique_ptr<nts::IComponent> createOr() const;
            std::unique_ptr<nts::IComponent> create4001() const;
            std::unique_ptr<nts::IComponent> create4011() const;
            std::unique_ptr<nts::IComponent> create4030() const;
            std::unique_ptr<nts::IComponent> create4069() const;
            std::unique_ptr<nts::IComponent> create4071() const;
            std::unique_ptr<nts::IComponent> create4081() const;
            std::unique_ptr<nts::IComponent> create4008() const;
            std::unique_ptr<nts::IComponent> create4013() const;
            std::unique_ptr<nts::IComponent> create4017() const;
            std::unique_ptr<nts::IComponent> create4040() const;
            std::unique_ptr<nts::IComponent> create4094() const;
            std::unique_ptr<nts::IComponent> create4512() const;
            std::unique_ptr<nts::IComponent> create4514() const;
            std::unique_ptr<nts::IComponent> create4801() const;
            std::unique_ptr<nts::IComponent> create2716() const;
            std::unique_ptr<nts::IComponent> createLogger() const;

            std::string _componentName;

            std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _creation = {
                {"input", [this]() {return ComponentManager::createInput();}},
                {"output", [this]() {return ComponentManager::createOutput();}},
                {"true", [this]() {return ComponentManager::createTrue();}},
                {"false", [this]() {return ComponentManager::createFalse();}},
                {"clock", [this]() {return ComponentManager::createClock();}},
                {"and", [this]() {return ComponentManager::createAnd();}},
                {"not", [this]() {return ComponentManager::createNot();}},
                {"xor", [this]() {return ComponentManager::createXor();}},
                {"or", [this]() {return ComponentManager::createOr();}},
                {"4001", [this]() {return ComponentManager::create4001();}},
                {"4011", [this]() {return ComponentManager::create4011();}},
                {"4030", [this]() {return ComponentManager::create4030();}},
                {"4069", [this]() {return ComponentManager::create4069();}},
                {"4071", [this]() {return ComponentManager::create4071();}},
                {"4081", [this]() {return ComponentManager::create4081();}},
                {"4008", [this]() {return ComponentManager::create4008();}},
                {"4013", [this]() {return ComponentManager::create4013();}},
                {"4017", [this]() {return ComponentManager::create4017();}},
                {"4040", [this]() {return ComponentManager::create4040();}},
                {"4094", [this]() {return ComponentManager::create4094();}},
                {"4512", [this]() {return ComponentManager::create4512();}},
                {"4514", [this]() {return ComponentManager::create4514();}},
                {"4801", [this]() {return ComponentManager::create4801();}},
                {"2716", [this]() {return ComponentManager::create2716();}},
                {"logger", [this]() {return ComponentManager::createLogger();}}
            };
    };
}

#endif
