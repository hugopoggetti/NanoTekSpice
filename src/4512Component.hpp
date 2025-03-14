/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4512Component
*/

#ifndef _4512COMPONENT_
    #define _4512COMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class Component4512 : public AComponent {
        public:
            Component4512(const std::string &name);
            ~Component4512() = default;
            void simulate(std::size_t thick);
    };
}

#endif
