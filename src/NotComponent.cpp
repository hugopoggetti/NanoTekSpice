/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** NotComponent
*/

#include "NotComponent.hpp"

nts::NotComponent::NotComponent(const std::string &name)
{
    _name = name;
    _type = "not";
    _pinsLinks.resize(3);
    _pinsLinksState.resize(3);
    _pinsValue.resize(3);
    for (std::size_t i = 0; i < 3; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::NotComponent::simulate(__attribute__((unused)) std::size_t thick)
{
    nts::Tristate a = this->compute(1);
    nts::Tristate result = NotComponent::notOp(a);
    this->setPinVal(2, result);
    this->loadPinVal(2);
}

nts::Tristate nts::NotComponent::notOp(nts::Tristate a)
{
    if (a == nts::Undefined) {
        return nts::Undefined;
    }
    if (a == nts::True) {
        return nts::False;
    }
    return nts::True;
}
