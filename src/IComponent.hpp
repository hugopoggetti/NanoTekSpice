/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** IComponent.hpp
*/

#ifndef _ICOMPONENT_
    #define _ICOMPONENT_

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define TRUE nts::Tristate::True
#define FALSE nts::Tristate::False
#define UNDEF nts::Tristate::Undefined

namespace nts
{
    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;

            virtual const std::string &getName() const = 0;
            virtual const std::string &getType() const = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void setPinVal(std::size_t pin, nts::Tristate val) = 0;
            virtual void loadPinVal(std::size_t pin) = 0;
            virtual std::size_t getNbPins() const = 0;
            virtual bool isLink(std::size_t pin) const = 0;
            virtual std::size_t getNbLinks(std::size_t pin) const = 0;
            virtual bool getLinkState(std::size_t pin, std::size_t otherPin) const = 0;
            virtual void setLinkState(std::size_t pin, std::size_t otherPin, bool state) = 0;
            virtual void setBidirectionalLinkState(std::size_t pin, const std::string &componentName, bool state) = 0;
            virtual void resetLinkState() = 0;
            virtual nts::IComponent &getLinkComponent(std::size_t pin, std::size_t otherPin) = 0;
    };
}

#endif
