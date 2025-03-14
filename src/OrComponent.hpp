/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** OrComponent
*/

#ifndef _ORCOMPONENT_
    #define _ORCOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class OrComponent : public nts::AComponent {
        public:
            OrComponent(const std::string &name);
            ~OrComponent() = default;
            void simulate(std::size_t tick);
            static nts::Tristate orOp(nts::Tristate a, nts::Tristate b);
    };
}

#endif
