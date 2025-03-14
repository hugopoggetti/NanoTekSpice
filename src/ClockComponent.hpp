/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** ClockComponent
*/

#ifndef _CLOCKCOMPONENT_
    #define _CLOCKCOMPONENT_

#include "AComponent.hpp"
#include "IComponent.hpp"

namespace nts
{
    class ClockComponent : public AComponent {
        public:
            ClockComponent(const std::string &name);
            ~ClockComponent() = default;
            void simulate(std::size_t thick);
            nts::Tristate compute(std::size_t pin);
            void setPinVal(std::size_t pin, nts::Tristate val);
        private:
            nts::Tristate _tmpValue;
            bool _first;
    };
}

#endif
