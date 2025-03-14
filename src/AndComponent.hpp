/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** AndComponent
*/

#ifndef _ANDCOMPONENT_
    #define _ANDCOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class AndComponent : public AComponent {
        public:
            AndComponent(const std::string &name);
            ~AndComponent() = default;
            void simulate(std::size_t tick);
            static nts::Tristate andOp(nts::Tristate a, nts::Tristate b);
    };
}

#endif
