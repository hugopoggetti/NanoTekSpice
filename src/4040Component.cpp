#include "4040Component.hpp"
#include "IComponent.hpp"

nts::Component4040::Component4040(const std::string &name)
{
    _name = name;
    _type = "4040";
    _pinsLinks.resize(16);
    _pinsLinksState.resize(16);
    _pinsValue.resize(16);
    _prev_clock = nts::Tristate::Undefined;
    for (std::size_t i = 0; i < 16; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
      // index of 10 Q pin
    _index.resize(12);
    _index[0] = 9;
    _index[1] = 7;
    _index[2] = 6;
    _index[3] = 5;
    _index[4] = 3;
    _index[5] = 2;
    _index[6] = 4;
    _index[7] = 13;
    _index[8] = 12;
    _index[9] = 14;
    _index[10] = 15;
    _index[11] = 1;
}

void nts::Component4040::binary_12_bits_reset()
{
    for (std::size_t i = 0; i < 12; i++) {
        setPinVal(_index[i], nts::Tristate::False);
        if (isLink(_index[i]))
            loadPinVal(_index[i]);
    }
}

void nts::Component4040::binary_12_bits_add()
{
    bool carry = true;

    for (int i = 0 ; i < 12 && carry; i++) {
        if (compute(_index[i]) 
                == nts::Tristate::False) {
            setPinVal(_index[i], nts::Tristate::True);
            if (isLink(_index[i]))
                loadPinVal(_index[i]);
            carry = false;
        } else {
            setPinVal(_index[i], nts::Tristate::False);
            if (isLink(_index[i]))
                loadPinVal(_index[i]);
        }
    } 
}

void nts::Component4040::simulate(__attribute__((unused))
        std::size_t thick)
{
    nts::Tristate cur_clock = compute(10);
    nts::Tristate reset = compute(11);

    if (reset == nts::Tristate::True) {
        binary_12_bits_reset();
    } else if (cur_clock == FALSE 
            && _prev_clock == TRUE 
            && reset == FALSE) {
        // add if clock is 
        binary_12_bits_add();
    }
    _prev_clock = cur_clock;
}
