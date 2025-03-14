/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4069Component
*/

#include "4069Component.hpp"
#include "NotComponent.hpp"

nts::Component4069::Component4069(const std::string &name)
{
    _name = name;
    _type = "4069";
    _pinsLinks.resize(14);
    _pinsLinksState.resize(14);
    _pinsValue.resize(14);
    for (std::size_t i = 0; i < 14; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::Component4069::simulate(__attribute__((unused)) std::size_t thick)
{
    nts::Tristate in1 = this->compute(1);
    nts::Tristate result = nts::NotComponent::notOp(in1);

    this->setPinVal(2, result);
    if (this->isLink(2)) {
        this->loadPinVal(2);
    }
    in1 = this->compute(3);
    result = nts::NotComponent::notOp(in1);
    this->setPinVal(4, result);
    if (this->isLink(4)) {
        this->loadPinVal(4);
    }
    in1 = this->compute(5);
    result = nts::NotComponent::notOp(in1);
    this->setPinVal(6, result);
    if (this->isLink(6)) {
        this->loadPinVal(6);
    }
    in1 = this->compute(9);
    result = nts::NotComponent::notOp(in1);
    this->setPinVal(8, result);
    if (this->isLink(8)) {
        this->loadPinVal(8);
    }
    in1 = this->compute(11);
    result = nts::NotComponent::notOp(in1);
    this->setPinVal(10, result);
    if (this->isLink(10)) {
        this->loadPinVal(10);
    }
    in1 = this->compute(13);
    result = nts::NotComponent::notOp(in1);
    this->setPinVal(12, result);
    if (this->isLink(12)) {
        this->loadPinVal(12);
    }
}
