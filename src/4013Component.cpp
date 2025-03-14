#include "4013Component.hpp"
#include "NotComponent.hpp"

nts::Component4013::Component4013(const std::string &name)
{
    _name = name;
    _type = "4013";
    _prev_cl1 = nts::Tristate::Undefined;
    _prev_cl2 = nts::Tristate::Undefined;
    _pinsLinks.resize(14);
    _pinsLinksState.resize(14);
    _pinsValue.resize(14);
    for (std::size_t i = 0; i < 14; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

nts::Tristate nts::Component4013::flip_flop(nts::Tristate set,
        nts::Tristate reset,
        nts::Tristate data, 
        nts::Tristate clock,
        nts::Tristate prev)
{
    if (reset == nts::Tristate::True) 
        return nts::Tristate::False;
    else if (set == nts::Tristate::True) 
        return nts::Tristate::True;
    else if (clock == nts::Tristate::True
        && prev == nts::Tristate::False)
        return data;
    return prev;
}

void nts::Component4013::simulate(__attribute__((unused))
        std::size_t thick)
{
    nts::Tristate cl1 = compute(3);
    nts::Tristate cl2 = compute(11);

    // LATCH 1
    nts::Tristate set = compute(6);
    nts::Tristate reset = compute(4);
    nts::Tristate data = compute(5);    
    nts::Tristate Q = flip_flop(set, reset,
            data, cl1, _prev_cl1);

    // Q
    setPinVal(1, Q);
    // invert Q
    setPinVal(2, nts::NotComponent::notOp(Q));
    if (isLink(1))
        loadPinVal(1);
    if (isLink(2))
        loadPinVal(2);

    // LATCH 2   
    set = compute(8);
    reset = compute(10);
    data = compute(9);    
    Q = flip_flop(set, reset, data, cl2, _prev_cl2);
    setPinVal(13, Q);
    setPinVal(12, nts::NotComponent::notOp(Q));
    if (isLink(13))
        loadPinVal(13);
    if (isLink(12))
        loadPinVal(12);
    _prev_cl1 = cl1;
    _prev_cl2 = cl2;
}
