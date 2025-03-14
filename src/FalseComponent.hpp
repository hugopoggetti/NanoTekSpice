/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** FalseComponent
*/

#ifndef _FALSECOMPONENT_
    #define _FALSECOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class FalseComponent : public AComponent {
        public:
            FalseComponent(const std::string &name);
            ~FalseComponent() = default;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void setPinVal(std::size_t pin, nts::Tristate val);
    };
}

#endif
