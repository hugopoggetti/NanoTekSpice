/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** OutputComponent
*/

#ifndef _OUTPUTCOMPONENT_
    #define _OUTPUTCOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class OutputComponent : public nts::AComponent {
        public:
            OutputComponent(const std::string &name);
            ~OutputComponent() = default;
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void setPinVal(std::size_t pin, nts::Tristate val);
        private:
            nts::Tristate _tmpValue;
    };
}

#endif
