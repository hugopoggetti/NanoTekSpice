/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** LoggerComponent
*/

#include "LoggerComponent.hpp"

#include <array>
#include <fstream>

nts::LoggerComponent::LoggerComponent(const std::string &name)
{
    _name = name;
    _type = "logger";
    _prevClock = nts::Undefined;
    _pinsLinks.resize(10);
    _pinsLinksState.resize(10);
    _pinsValue.resize(10);
    for (std::size_t i = 0; i < 10; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::LoggerComponent::simulate(__attribute__((unused)) std::size_t thick)
{
    if (this->compute(10)) {
        return;
    }
    nts::Tristate clock = this->compute(9);
    if (clock == nts::True && _prevClock == nts::False) {
        std::array<std::size_t, 8> pins = {8, 7, 6, 5, 4, 3, 2, 1};
        std::array<std::size_t, 8> byte;
        for (std::size_t i = 0; i < pins.size(); i++) {
            byte[i] = (this->compute(pins[i]) == nts::True) ? 1 : 0;
        }
        char byteValue = 0;
        for(std::size_t i  = 0; i < byte.size(); i++) {
            byteValue |= (byte[i] << (7-i));
        }
        std::ofstream file("log.bin", std::ofstream::app);
        if (!file.is_open()) {
            return;
        }
        file.put(byteValue);
    }
    _prevClock = clock;
}
