/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4011Component
*/

#ifndef _4011COMPONENT_
    #define _4011COMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class Component4011 : public nts::AComponent {
        public:
            Component4011(const std::string &name);
            ~Component4011() = default;
            void simulate(std::size_t thick);
            static nts::Tristate nandOp(nts::Tristate a, nts::Tristate b);
    };
}

#endif
