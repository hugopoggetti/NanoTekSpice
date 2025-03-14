/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4030Component
*/

#ifndef _4030COMPONENT_
    #define _4030COMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class Component4030 : public AComponent {
        public:
            Component4030(const std::string &name);
            ~Component4030() = default;
            void simulate(std::size_t thick);
    };
}

#endif
