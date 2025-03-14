/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** 4001Component
*/

#include "4001Component.hpp"
#include "OrComponent.hpp"

nts::Component4001::Component4001(const std::string &name)
{
    _name = name;
    _type = "4001";
    _pinsLinks.resize(14);
    _pinsLinksState.resize(14);
    _pinsValue.resize(14);
    for (std::size_t i = 0; i < 14; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::Component4001::simulate(__attribute__((unused)) std::size_t thick)
{
    nts::Tristate in1 = this->compute(1);
    nts::Tristate in2 = this->compute(2);
    nts::Tristate result = norOp(in1, in2);

    this->setPinVal(3, result);
    if (this->isLink(3)) {
        this->loadPinVal(3);
    }
    in1 = this->compute(5);
    in2 = this->compute(6);
    result = norOp(in1, in2);
    this->setPinVal(4, result);
    if (this->isLink(4)) {
        this->loadPinVal(4);
    }
    in1 = this->compute(8);
    in2 = this->compute(9);
    result = norOp(in1, in2);
    this->setPinVal(10, result);
    if (this->isLink(10)) {
        this->loadPinVal(10);
    }
    in1 = this->compute(12);
    in2 = this->compute(13);
    result = norOp(in1, in2);
    this->setPinVal(11, result);
    if (this->isLink(11)) {
        this->loadPinVal(11);
    }
}

nts::Tristate nts::Component4001::norOp(nts::Tristate a, nts::Tristate b)
{
    nts::Tristate res = nts::OrComponent::orOp(a, b);
    if (res != nts::Tristate::Undefined) {
        return nts::Tristate(!res);
    }
    return res;
}
