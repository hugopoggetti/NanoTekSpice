#pragma once

#include "AComponent.hpp"
#include "IComponent.hpp"

namespace nts {
    class Component4017 : public nts::AComponent {
        public:
            Component4017(const std::string &name);
            ~Component4017() = default;
            void simulate(std::size_t thick);
            void all_out_false();
        private:
            std::vector<std::size_t> _index;
            std::size_t cur_idx;
            nts::Tristate prev_cp0;
            nts::Tristate prev_cp1;
    };
}
