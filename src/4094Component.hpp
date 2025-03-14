#pragma once

#include "AComponent.hpp"
#include "IComponent.hpp"

namespace nts {
    class Component4094 : public nts::AComponent {
        public:
            Component4094(const std::string &name);
            ~Component4094() = default;
            void simulate(std::size_t thick);
        private:
            std::vector<nts::Tristate> _shitf_tmp;
            std::vector<nts::Tristate> _latch;
            nts::Tristate _prev_cl;
            nts::Tristate _prev_qs;
            nts::Tristate _prev_strobe;

    };
}
