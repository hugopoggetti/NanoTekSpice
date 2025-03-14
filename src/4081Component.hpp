/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4081Component
*/

#ifndef _4081COMPONENT_
    #define _4081COMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class Component4081 : public AComponent {
        public:
            Component4081(const std::string &name);
            ~Component4081() = default;
            void simulate(std::size_t thick);
    };
}

#endif
