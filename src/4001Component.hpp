/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4001Component
*/

#ifndef _4001COMPONENT_
    #define _4001COMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class Component4001 : public nts::AComponent {
        public:
            Component4001(const std::string &name);
            ~Component4001() = default;
            void simulate(std::size_t thick);
            static nts::Tristate norOp(nts::Tristate a, nts::Tristate b);
    };
}

#endif
