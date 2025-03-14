#include "4008Component.hpp"
#include "IComponent.hpp"
#include "OrComponent.hpp"
#include "XorComponent.hpp"
#include "AndComponent.hpp"


nts::Component4008::Component4008(const std::string &name)
{
    _name = name;
    _type = "4008";
    _pinsLinks.resize(16);
    _pinsLinksState.resize(16);
    _pinsValue.resize(16);
    for (std::size_t i = 0; i < 16; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

std::pair<nts::Tristate, nts::Tristate> 
    nts::Component4008::adder(nts::Tristate b1,
    nts::Tristate b2, nts::Tristate carry)
{
    nts::Tristate res =
        nts::XorComponent::xorOp(
                nts::XorComponent::xorOp(b1 ,b2),
                carry);

    nts::Tristate new_carry =
        nts::OrComponent::orOp(
            nts::OrComponent::orOp(
                nts::AndComponent::andOp(b1, b2),
                nts::AndComponent::andOp(b1, carry)),
                nts::AndComponent::andOp(b2, carry));

    std::pair<nts::Tristate, nts::Tristate> result;
    result.first = res;
    result.second = new_carry;
    return result;
}

void nts::Component4008::set_out_flase()
{
    for (std::size_t i = 0; i < 5; i++) {
        if (compute(i + 10) == nts::Tristate::Undefined) {
            setPinVal(i + 10, nts::Tristate::False);
            if (isLink(i + 10)) 
                loadPinVal(i + 10);
        }
    }
}

void nts::Component4008::simulate(__attribute__((unused))
        std::size_t thick)
{
    nts::Tristate carry_in = compute(9);
    std::pair<nts::Tristate, nts::Tristate> result =
        adder(
            compute(7),
            compute(6),   
            carry_in);
    setPinVal(10, result.first);
    if (isLink(10)) 
        loadPinVal(10);
    carry_in = result.second;

    result =
        adder(
            compute(5),
            compute(4),   
            carry_in);
    setPinVal(11, result.first);
    if (isLink(11)) 
        loadPinVal(11);
    carry_in = result.second;

    result =
        adder(
            compute(3),
            compute(2),   
            carry_in);
    setPinVal(12, result.first);
    if (isLink(12)) 
        loadPinVal(12);
    carry_in = result.second;

    result =
        adder(
            compute(1),
            compute(15),   
            carry_in);
    setPinVal(13, result.first);
    setPinVal(14, result.second);
    if (isLink(13)) 
        loadPinVal(13);
    if (isLink(14)) 
        loadPinVal(14);
    set_out_flase();
}
