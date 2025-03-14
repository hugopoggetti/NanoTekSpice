/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** AndComponent
*/

#include "AndComponent.hpp"

nts::AndComponent::AndComponent(const std::string &name)
{
    _name = name;
    _type = "and";
    _pinsLinks.resize(3);
    _pinsLinksState.resize(3);
    _pinsValue.resize(3);
    for (std::size_t i = 0; i < 3; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::AndComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    nts::Tristate a = this->compute(1);
    nts::Tristate b = this->compute(2);
    nts::Tristate result = AndComponent::andOp(a, b);
    this->setPinVal(3, result);
    this->loadPinVal(3);
}

nts::Tristate nts::AndComponent::andOp(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Undefined || b == nts::Undefined) {
        if (a == false && b == nts::Tristate::Undefined)
            return nts::Tristate::False;
        if (a == true && b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        if (b == false && a == nts::Tristate::Undefined)
            return nts::Tristate::False;
        if (b == true && a == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        if (b == nts::Tristate::Undefined && a == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
    }
    return nts::Tristate(a && b);
}
