/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** LoggerComponent
*/

#ifndef _LOGGERCOMPONENT_
    #define _LOGGERCOMPONENT_

#include "AComponent.hpp"

namespace nts
{
    class LoggerComponent : public AComponent {
        public:
            LoggerComponent(const std::string &name);
            ~LoggerComponent() = default;
            void simulate(std::size_t thick);
        private:
            nts::Tristate _prevClock;
    };
}

#endif
