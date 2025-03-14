#pragma once

#include "AComponent.hpp"

namespace nts {
    class Component4040 : public nts::AComponent {
        public:
            Component4040(const std::string &name);
            ~Component4040() = default;
            void simulate(std::size_t thick);
            void binary_12_bits_add();
            void binary_12_bits_reset();
        private:
            std::vector<std::size_t> _index;
            nts::Tristate _prev_clock;
    };
}

