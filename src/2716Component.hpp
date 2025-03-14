#pragma once

#include <cstdint>
#include <cstddef>
#include "AComponent.hpp"

namespace nts {
    class Component2716: public nts::AComponent {
        public:
            Component2716(const std::string& name); 
            ~Component2716() = default;
            void simulate(std::size_t tick);
            void init_ram_by_file();
        private:
            std::vector<uint8_t> _ram;
    };
}
