/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** FalseComponent
*/

#include "FalseComponent.hpp"

nts::FalseComponent::FalseComponent(const std::string &name)
{
    _name = name;
    _type = "false";
    _pinsLinks.resize(1);
    _pinsLinksState.resize(1);
    _pinsValue.resize(1);
    for (std::size_t i = 0; i < 1; i++) {
        _pinsValue.at(i) = nts::False;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::FalseComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > this->getNbPins()) {
        throw nts::Error("-E- To many pins given.");
    }
    _pinsLinks.at((pin - 1)).second.push_back({otherPin, other});
    _pinsLinksState.at((pin - 1)).second.push_back({otherPin, false});
    other.setPinVal(otherPin, _pinsValue.at(0));
    if (other.getType() == "output") {
        other.simulate(0);
    }
}

void nts::FalseComponent::simulate(__attribute__((unused)) std::size_t tick)
{
    if (!this->isLink(1)) {
        return;
    }
    this->loadPinVal(1);
}

nts::Tristate nts::FalseComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return _pinsValue.at(0);
}

void nts::FalseComponent::setPinVal(__attribute__((unused)) std::size_t pin, __attribute__((unused)) nts::Tristate val)
{
    _pinsValue.at(0) = nts::False;
}
