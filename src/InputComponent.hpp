/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** InputComponent
*/

#ifndef _INPUTCOMPONENT_
    #define _INPUTCOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class InputComponent : public nts::AComponent {
        public:
            InputComponent(const std::string &name);
            ~InputComponent() = default;
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void setPinVal(std::size_t pin, nts::Tristate val);
        private:
            nts::Tristate _tmpState;
    };
}

#endif
