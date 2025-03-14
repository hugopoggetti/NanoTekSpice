/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4069Component
*/

#ifndef _4069COMPONENT_
    #define _4069COMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class Component4069 : public AComponent {
        public:
            Component4069(const std::string &name);
            ~Component4069() = default;
            void simulate(std::size_t thick);
    };
}

#endif
