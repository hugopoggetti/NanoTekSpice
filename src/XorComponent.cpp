/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** XorComponent
*/

#include "XorComponent.hpp"

nts::XorComponent::XorComponent(const std::string &name)
{
    _name = name;
    _type = "xor";
    _pinsLinks.resize(3);
    _pinsLinksState.resize(3);
    _pinsValue.resize(3);
    for (std::size_t i = 0; i < 3; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::XorComponent::simulate(__attribute__((unused)) std::size_t thick)
{
    nts::Tristate a = this->compute(1);
    nts::Tristate b = this->compute(2);
    nts::Tristate result = XorComponent::xorOp(a, b);
    this->setPinVal(3, result);
    this->loadPinVal(3);
}

nts::Tristate nts::XorComponent::xorOp(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Undefined || b == nts::Undefined) {
        return nts::Tristate::Undefined;
    }
    return nts::Tristate(a ^ b);
}
