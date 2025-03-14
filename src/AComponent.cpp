/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** Acomponent
*/

#include "AComponent.hpp"

const std::string &nts::AComponent::getName() const
{
    return _name;
}

const std::string &nts::AComponent::getType() const
{
    return _type;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin > this->getNbPins()) {
        throw nts::Error("-E- To many pins given.");
    }
    _pinsLinks.at((pin - 1)).second.push_back({otherPin, other});
    _pinsLinksState.at((pin - 1)).second.push_back({otherPin, false});
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    if (pin > this->getNbPins()) {
        throw nts::Error("-E- To many pins given.");
    }
    return _pinsValue.at((pin - 1));
}

void nts::AComponent::setPinVal(std::size_t pin, nts::Tristate val)
{
    if (pin > this->getNbPins()) {
        throw nts::Error("-E- To many pins given.");
    }
    _pinsValue.at((pin - 1)) = val;
}

void nts::AComponent::loadPinVal(std::size_t pin)
{
    if (pin > this->getNbPins()) {
        throw nts::Error("-E- To many pins given.");
    }
    if (!this->isLink(pin)) {
        return;
    }
    for (std::size_t i = 0; i < _pinsLinks.at(pin - 1).second.size(); i++) {
        std::size_t otherPin = _pinsLinks.at(pin - 1).second.at(i).first;
        _pinsLinks.at(pin - 1).second.at(i).second.setPinVal(otherPin, _pinsValue.at(pin - 1));
    }
}

std::size_t nts::AComponent::getNbPins() const
{
    return _pinsLinks.size();
}

bool nts::AComponent::isLink(std::size_t pin) const
{
    if (pin > this->getNbPins()) {
        throw nts::Error("-E- To many pins given.");
    }
    if (_pinsLinks.at((pin - 1)).second.empty()) {
        return false;
    }
    return true;
}

std::size_t nts::AComponent::getNbLinks(std::size_t pin) const
{
    if (pin > this->getNbPins()) {
        throw nts::Error("-E- To many pins given.");
    }
    if (!this->isLink(pin)) {
        return 0;
    }
    return _pinsLinks.at(pin - 1).second.size();
}

bool nts::AComponent::getLinkState(std::size_t pin, std::size_t otherPin) const
{
    if (pin > this->getNbPins() || otherPin > this->getNbLinks(pin)) {
        throw nts::Error("-E- To many pins given.");
    }
    return _pinsLinksState.at(pin - 1).second.at(otherPin - 1).second;
}

void nts::AComponent::setLinkState(std::size_t pin, std::size_t otherPin, bool state)
{
    if (pin > this->getNbPins() || otherPin > this->getNbLinks(pin)) {
        throw nts::Error("-E- To many pins given.");
    }
    if (_pinsLinksState.at(pin - 1).second.at(otherPin - 1).second == state) {
        return;
    }
    _pinsLinksState.at(pin - 1).second.at(otherPin - 1).second = state;
    std::size_t otherPinConnected = _pinsLinksState.at(pin - 1).second.at(otherPin - 1).first;
    _pinsLinks.at(pin - 1).second.at(otherPin - 1).second.setBidirectionalLinkState(otherPinConnected,
        this->getName(), state);
}

void nts::AComponent::setBidirectionalLinkState(std::size_t pin, const std::string &componentName, bool state)
{
    if (pin > this->getNbPins()) {
        throw nts::Error("-E- To many pins given.");
    }
    std::size_t posPin = 0;
    for (; posPin < _pinsLinks.at(pin - 1).second.size(); posPin++) {
        if (_pinsLinks.at(pin - 1).second.at(posPin).second.getName() == componentName) {
            break;
        }
    }
    if (posPin == _pinsLinksState.at(pin - 1).second.size()) {
        throw nts::Error("-E- Pin not found.");
    }
    if (_pinsLinksState.at(pin - 1).second.at(posPin).second == state) {
        return;
    }
    _pinsLinksState.at(pin - 1).second.at(posPin).second = state;
}

void nts::AComponent::resetLinkState()
{
    for (std::size_t i = 0; i < _pinsLinksState.size(); i++) {
        for (std::size_t j = 0; j < _pinsLinksState.at(i).second.size(); j++) {
            _pinsLinksState.at(i).second.at(j).second = false;
        }
    }
}

nts::IComponent &nts::AComponent::getLinkComponent(std::size_t pin, std::size_t otherPin)
{
    if (pin > this->getNbPins() || otherPin > this->getNbLinks(pin)) {
        throw nts::Error("-E- To many pins given.");
    }
    return _pinsLinks.at(pin - 1).second.at(otherPin - 1).second;
}
