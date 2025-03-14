/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4071Component
*/

#ifndef _4071COMPONENT_
    #define _4071COMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class Component4071 : public AComponent {
        public:
            Component4071(const std::string &name);
            ~Component4071() = default;
            void simulate(std::size_t thick);
    };
}

#endif
