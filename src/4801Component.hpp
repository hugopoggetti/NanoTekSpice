#pragma once

#include "AComponent.hpp"
#include "IComponent.hpp"
#include <cstddef>
#include <cstdint>

namespace nts {
    class Component4801 : public nts::AComponent {
        public:
            Component4801(const std::string &name);
            ~Component4801() = default;
            void simulate(std::size_t thick);
            nts::Tristate get_in_or_out(std::size_t pin);
            void set_in_or_out(std::size_t pin, nts::Tristate val);
        private:
             std::vector<uint8_t> _ram;
    };
}
