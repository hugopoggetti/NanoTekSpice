/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** XorComponent
*/

#ifndef _XORCOMPONENT_
    #define _XORCOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class XorComponent : public AComponent {
        public:
            XorComponent(const std::string &name);
            ~XorComponent() = default;
            void simulate(std::size_t thick);
            static nts::Tristate xorOp(nts::Tristate a, nts::Tristate b);
    };
}

#endif
