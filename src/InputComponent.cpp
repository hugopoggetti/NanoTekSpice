/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** InputComponent
*/

#include "InputComponent.hpp"

nts::InputComponent::InputComponent(const std::string &name)
{
    _name = name;
    _type = "input";
    _tmpState = nts::Undefined;
    _pinsLinks.resize(1);
    _pinsLinksState.resize(1);
    _pinsValue.resize(1);
    for (std::size_t i = 0; i < 1; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::InputComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    _pinsValue.at(0) = _tmpState;
    if (!this->isLink(1)) {
        return;
    }
    this->loadPinVal(1);
}

nts::Tristate nts::InputComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return _pinsValue.at(0);
}

void nts::InputComponent::setPinVal(__attribute__((unused)) std::size_t pin, nts::Tristate val)
{
    _tmpState = val;
}
