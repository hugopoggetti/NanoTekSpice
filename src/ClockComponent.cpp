/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** ClockComponent
*/

#include "ClockComponent.hpp"
#include "IComponent.hpp"
#include <csignal>

nts::ClockComponent::ClockComponent(const std::string &name)
{
    _name = name;
    _type = "clock";
    _tmpValue = nts::Undefined;
    _first = true;
    _pinsLinks.resize(1);
    _pinsLinksState.resize(1);
    _pinsValue.resize(1);
    for (std::size_t i = 0; i < 1; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::ClockComponent::simulate(__attribute__((unused))
        std::size_t thick)
{
    nts::Tristate res = _tmpValue;

    if (res != nts::Tristate::Undefined && !_first)
        res = (nts::Tristate)!res;

    _first = false;
    _tmpValue = res;
    _pinsValue.at(0) = _tmpValue;
     
    if (!this->isLink(1)) {
        return;
    }
    this->loadPinVal(1);
}

nts::Tristate nts::ClockComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return _pinsValue.at(0);
}

void nts::ClockComponent::setPinVal(__attribute__((unused)) std::size_t pin, nts::Tristate val)
{
    _first = true;
    _tmpValue = val;
}
