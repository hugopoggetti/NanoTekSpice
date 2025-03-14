/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** NotComponent
*/

#ifndef _NOTCOMPONENT_
    #define _NOTCOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class NotComponent : public AComponent {
        public:
            NotComponent(const std::string &name);
            ~NotComponent() = default;
            void simulate(std::size_t thick);
            static nts::Tristate notOp(nts::Tristate a);
    };
}

#endif
