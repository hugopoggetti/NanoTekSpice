/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** OrComponent
*/

#include "OrComponent.hpp"

nts::OrComponent::OrComponent(const std::string &name)
{
    _name = name;
    _type = "or";
    _pinsLinks.resize(3);
    _pinsLinksState.resize(3);
    _pinsValue.resize(3);
    for (std::size_t i = 0; i < 3; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::OrComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    nts::Tristate a = this->compute(1);
    nts::Tristate b = this->compute(2);
    nts::Tristate result = OrComponent::orOp(a, b);
    this->setPinVal(3, result);
    this->loadPinVal(3);
}

nts::Tristate nts::OrComponent::orOp(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::Undefined ||
        b == nts::Tristate::Undefined) {
        if (a == false && b == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        if (a == true && b == nts::Tristate::Undefined)
            return nts::Tristate::True;
        if (b == false && a == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
        if (b == true && a == nts::Tristate::Undefined)
            return nts::Tristate::True;
        if (b == nts::Tristate::Undefined && a == nts::Tristate::Undefined)
            return nts::Tristate::Undefined;
    }
    return nts::Tristate(a || b);
}
