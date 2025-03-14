#include "4801Component.hpp"
#include "IComponent.hpp"
#include <cstddef>

nts::Component4801::Component4801(const std::string &name)
{
    _name = name;
    _type = "4801";
    _pinsLinks.resize(24);
    _pinsLinksState.resize(24);
     _ram.resize(1024, 0);
    _pinsValue.resize(24);
    for (std::size_t i = 0; i < 24; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}


void nts::Component4801::set_in_or_out
    (std::size_t pin, nts::Tristate val)
{
    for (std::size_t i = 0; i < _pinsLinks.size(); i++) {
        if (pin == _pinsLinks[i].first) {
            for (size_t j = 0; j < _pinsLinks[i].second.size(); j++) {
               if (_pinsLinks[i].second[j].second.getType()
                    == "output") {
                    _pinsLinks[i].second[j].second.setPinVal
                        (1, val);
                    _pinsLinks[i].second[j].second.loadPinVal(1);
                }
            }
        }
    }

}

nts::Tristate nts::Component4801::get_in_or_out
    (std::size_t pin)
{
    for (std::size_t i = 0; i < _pinsLinks.size(); i++) {
        if (pin == _pinsLinks[i].first) {
            for (size_t j = 0; j < _pinsLinks[i].second.size(); j++) {
               if (_pinsLinks[i].second[j].second.getType()
                    == "input") {
                    return _pinsLinks[i].second[j].second.compute(1);
                }
            }
        }
    }
    return nts::Tristate::Undefined;
}

void nts::Component4801::simulate(__attribute__((unused))
        std::size_t thick)
{
    nts::Tristate enable = compute(18);
    nts::Tristate write = compute(21);
    nts::Tristate read = compute(20);

    if (enable != nts::Tristate::False) 
        return;

    const int address_pins[10] = {8, 7, 6, 5, 4, 3, 2, 1, 23, 22};
    const int data_pins[8] = {9, 10, 11, 13, 14, 15, 16, 17};
    uint16_t address = 0;

    // read address into 16 bytes
    for (int i = 0; i < 10; i++) 
        if (compute(address_pins[i]) == nts::Tristate::True) 
            address += (1 << i);

    // write a new value in ram or overwrite
    if (write == nts::Tristate::False) {
        uint8_t data = 0;
        for (int i = 0; i < 8; i++) {
            if (get_in_or_out(data_pins[i])
                    == nts::Tristate::True) {
                data += (1 << i);
            }
        }
        _ram[address] = data;
    }
    if (read == nts::Tristate::False) {
        // read val in ram
        uint8_t data = _ram[address];
        for (int i = 0; i < 8; i++) {
            nts::Tristate val = (data & (1 << i)) ?
                nts::Tristate::True : nts::Tristate::False;
            set_in_or_out(data_pins[i], val);
        }
    }
}
