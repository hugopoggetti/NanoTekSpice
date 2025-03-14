/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4514Component
*/

#ifndef _4514COMPONENT_
    #define _4514COMPONENT_

#include "AComponent.hpp"

#include <array>

namespace nts
{
    class Component4514 : public AComponent {
        public:
            Component4514(const std::string &name);
            ~Component4514() = default;
            void simulate(std::size_t thick);
        private:
            std::vector<std::pair<std::vector<nts::Tristate>, std::size_t>> _truthTable = {
                {{nts::False, nts::False, nts::False, nts::False}, 11},
                {{nts::False, nts::False, nts::False, nts::True}, 9},
                {{nts::False, nts::False, nts::True, nts::False}, 10},
                {{nts::False, nts::False, nts::True, nts::True}, 8},
                {{nts::False, nts::True, nts::False, nts::False}, 7},
                {{nts::False, nts::True, nts::False, nts::True}, 6},
                {{nts::False, nts::True, nts::True, nts::False}, 5},
                {{nts::False, nts::True, nts::True, nts::True}, 4},
                {{nts::True, nts::False, nts::False, nts::False}, 18},
                {{nts::True, nts::False, nts::False, nts::True}, 17},
                {{nts::True, nts::False, nts::True, nts::False}, 20},
                {{nts::True, nts::False, nts::True, nts::True}, 19},
                {{nts::True, nts::True, nts::False, nts::False}, 14},
                {{nts::True, nts::True, nts::False, nts::True}, 13},
                {{nts::True, nts::True, nts::True, nts::False}, 16},
                {{nts::True, nts::True, nts::True, nts::True}, 15},
            };
    };
}

#endif
