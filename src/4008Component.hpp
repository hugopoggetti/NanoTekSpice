#pragma once

#include "AComponent.hpp"

namespace nts {
    class Component4008 : public nts::AComponent {
        public:
            Component4008(const std::string &name);
            ~Component4008() = default;
            void simulate(std::size_t thick);
            std::pair<nts::Tristate, nts::Tristate>
                adder(nts::Tristate b1,
                nts::Tristate b2, nts::Tristate carry);
            void set_out_flase();
    };
}
