#pragma once

#include "AComponent.hpp"

namespace nts {
    class Component4013 : public nts::AComponent {
        public:
            Component4013(const std::string &name);
            ~Component4013() = default;
            void simulate(std::size_t thick);
            nts::Tristate flip_flop(
                    nts::Tristate set,
                    nts::Tristate reset,
                    nts::Tristate data,
                    nts::Tristate clock,
                    nts::Tristate prev);
        private:
            nts::Tristate _prev_cl1;
            nts::Tristate _prev_cl2;
    };
}
