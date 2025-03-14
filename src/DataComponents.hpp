/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** DataComponents.hpp
*/

#ifndef _DATACOMPONENTS_
    #define _DATACOMPONENTS_

#include <string>
#include <map>

namespace nts
{
    const std::map<std::string, std::size_t> dataComponents {
        {"input", 1}, {"true", 1}, {"false", 1}, {"clock", 1},
        {"and", 3}, {"or", 3}, {"xor", 3}, {"not", 2}, {"4001", 14},
        {"4011", 14}, {"4030", 14}, {"4069", 14}, {"4071", 14},
        {"4081", 14}, {"4008", 16}, {"4013", 13}, {"4017", 15},
        {"4040", 16}, {"4094", 15}, {"4512", 16}, {"4514", 24},
        {"4801", 24}, {"2716", 24}, {"logger", 10}, {"output", 1}
    };
}

#endif
