#include "2716Component.hpp"
#include "IComponent.hpp"
#include <cstddef>
#include <cstdio>
#include <filesystem>
#include <fstream>

nts::Component2716::Component2716(const std::string& name)
{ 
    _name = name;
    _type = "2716";
    _ram.resize(2048, 0);
    _pinsLinks.resize(24);
    _pinsLinksState.resize(24);
    _pinsValue.resize(24);
    for (std::size_t i = 0; i < 24; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
}

void nts::Component2716::init_ram_by_file()
{ 
    std::ifstream content("./rom.bin");
    std::stringstream line;
        
    if (!content.fail()) {
        line << content.rdbuf();
        std::string data = line.str();
        for (std::size_t i = 0; i < data.size(); i++) {
            if (i > 2048)
                break;
            _ram[i] = data[i];
        }
    } 
}

void nts::Component2716::simulate(std::size_t tick)
{
    tick++;
    nts::Tristate enable = compute(18);
    nts::Tristate read = compute(20);
    
    // init ram wih ./rom.bin
    init_ram_by_file();

    if (enable != nts::Tristate::False) 
        return;

    const int address_pins[11] = 
        {8, 7, 6, 5, 4, 3, 2, 1, 23, 22, 19};
    const int data_pins[8] =
        {9, 10, 11, 13, 14, 15, 16, 17};
    uint16_t address = 0;

    // read address into 16 bytes
    for (int i = 0; i < 11; i++) {
        if (compute(address_pins[i]) 
            == nts::Tristate::True) 
            address |= (1 << i);
    }
    
    if (address >= 2048)
        return;

    if (read == nts::Tristate::False) {
        // read val in ram
        uint8_t data = _ram[address];
        for (int i = 0; i < 8; i++) {
            nts::Tristate val = (data & (1 << i)) ? 
                                nts::Tristate::True : 
                                nts::Tristate::False;
            setPinVal(data_pins[i], val);
            if (isLink(data_pins[i]))  
                loadPinVal(data_pins[i]);
        }
    } else {
        for (int i = 0; i < 8; i++) {
            setPinVal(data_pins[i], nts::Tristate::Undefined);
            if (isLink(data_pins[i]))
                loadPinVal(data_pins[i]);
        }
    }
}
