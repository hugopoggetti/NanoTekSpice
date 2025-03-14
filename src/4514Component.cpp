/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4514Component
*/

#include "4514Component.hpp"

nts::Component4514::Component4514(const std::string &name)
{
    _name = name;
    _type = "4514";
    _pinsLinks.resize(24);
    _pinsLinksState.resize(24);
    _pinsValue.resize(24);
    for (std::size_t i = 0; i < 24; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::Component4514::simulate(__attribute__((unused)) std::size_t thick)
{
    if (this->compute(23) == nts::True) {
        for (auto it = _truthTable.begin(); it != _truthTable.end(); ++it) {
            this->setPinVal((*it).second, nts::False);
            this->loadPinVal((*it).second);
        }
        return;
    }
    if (this->compute(1) == nts::False || this->compute(1) == nts::Undefined) {
        return;
    }
    std::array<nts::Tristate, 4> inputs = {this->compute(22), this->compute(21),
        this->compute(3), this->compute(2)};
    for (auto it = _truthTable.begin(); it != _truthTable.end(); ++it) {
        std::size_t define = 0;
        for (std::size_t i = 0; i < inputs.size(); i++) {
            if (inputs[i] != nts::Undefined) {
                define++;
            }
        }
        std::size_t matching = 0;
        for (std::size_t i = 0; i < inputs.size(); i++) {
            if (inputs[i] == (*it).first.at(i)) {
                matching++;
            }
        }
        if (matching == 0) {
            continue;
        }
        if (matching == 4) {
            this->setPinVal((*it).second, nts::True);
            this->loadPinVal((*it).second);
            continue;
        }
        if (matching == define) {
            this->setPinVal((*it).second, nts::Undefined);
            this->loadPinVal((*it).second);
            continue;
        }
    }
}
