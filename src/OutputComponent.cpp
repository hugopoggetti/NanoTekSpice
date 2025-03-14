/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** OutputComponent
*/

#include "OutputComponent.hpp"

nts::OutputComponent::OutputComponent(const std::string &name)
{
    _name = name;
    _type = "output";
    _tmpValue = nts::Undefined;
    _pinsLinks.resize(1);
    _pinsLinksState.resize(1);
    _pinsValue.resize(1);
    for (std::size_t i = 0; i < 1; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::OutputComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    _pinsValue.at(0) = _tmpValue;
}

nts::Tristate nts::OutputComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return _pinsValue[0];
}

void nts::OutputComponent::setPinVal(__attribute__((unused)) std::size_t pin, nts::Tristate val)
{
    _tmpValue = val;
}
