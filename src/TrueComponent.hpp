/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** TrueComponent
*/

#ifndef _TRUECOMPONENT_
    #define _TRUECOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class TrueComponent : public nts::AComponent {
        public:
            TrueComponent(const std::string &name);
            ~TrueComponent() = default;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void setPinVal(std::size_t pin, nts::Tristate val);
    };
}

#endif
