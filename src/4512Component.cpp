/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4512Component
*/

#include "4512Component.hpp"

nts::Component4512::Component4512(const std::string &name)
{
    _name = name;
    _type = "4512";
    _pinsLinks.resize(16);
    _pinsLinksState.resize(16);
    _pinsValue.resize(16);
    for (std::size_t i = 0; i < 16; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::Component4512::simulate(__attribute__((unused)) std::size_t thick)
{
    if (this->compute(15) == nts::True) {
        this->setPinVal(14, nts::Undefined);
        this->loadPinVal(14);
        return;
    }
    if (this->compute(10) == nts::True) {
        this->setPinVal(14, nts::False);
        this->loadPinVal(14);
        return;
    }
    nts::Tristate in1 = this->compute(11);
    nts::Tristate in2 = this->compute(12);
    nts::Tristate in3 = this->compute(13);
    if (in1 == nts::Undefined || in2 == nts::Undefined || in3 == nts::Undefined) {
        this->setPinVal(14, nts::Undefined);
        this->loadPinVal(14);
        return;
    }
    std::size_t iSelector = 0;
    std::size_t selector[3] = {};
    selector[2] = (in3 == nts::True) ? 1 : 0;
    selector[1] = (in2 == nts::True) ? 1 : 0;
    selector[0] = (in1 == nts::True) ? 1 : 0;
    for(std::size_t i  = 0; i < 3; ++i) {
        iSelector |= (selector[i] << i);
    }
    nts::Tristate channelData[8] = {this->compute(1), this->compute(2), this->compute(3),
    this->compute(4), this->compute(5), this->compute(6), this->compute(7),
    this->compute(9)};
    this->setPinVal(14, channelData[iSelector]);
    this->loadPinVal(14);
}
