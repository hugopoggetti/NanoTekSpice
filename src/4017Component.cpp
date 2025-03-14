#include "4017Component.hpp"
#include "4017Component.hpp"
#include "IComponent.hpp"

nts::Component4017::Component4017(const std::string &name)
{
    _name = name;
    _type = "4017";
    cur_idx = 0;
    prev_cp0 = nts::Tristate::Undefined;
    prev_cp1 = nts::Tristate::Undefined;
    _pinsLinks.resize(16);
    _pinsLinksState.resize(16);
    _pinsValue.resize(16);
    for (std::size_t i = 0; i < 16; i++) {
        _pinsValue.at(i) = nts::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
    // index of 10 Q pin
    _index.resize(10);
    _index[0] = 3;
    _index[1] = 2;
    _index[2] = 4;
    _index[3] = 7;
    _index[4] = 10;
    _index[5] = 1;
    _index[6] = 5;
    _index[7] = 6;
    _index[8] = 9;
    _index[9] = 11;
}

void nts::Component4017::all_out_false()
{
    for (std::size_t i = 0; i < 10; i++) {
        setPinVal(_index[i], nts::Tristate::False);
        if (isLink(_index[i]))
            loadPinVal(_index[i]);
    }
        
}

void nts::Component4017::simulate(__attribute__((unused))
        std::size_t thick)
{
    nts::Tristate cp_1 = compute(13);
    nts::Tristate cp_0 = compute(14);
    nts::Tristate mr = compute(15);

    if (mr == nts::Tristate::True) {
        all_out_false(); 
        setPinVal(_index[0], nts::Tristate::True);
        if (isLink(_index[0]))
            loadPinVal(_index[0]);
        cur_idx = 1;
    } else if ((cp_0 == nts::Tristate::True 
            && prev_cp0 == nts::Tristate::False 
            && cp_1 == nts::Tristate::False)
            || (cp_0 == nts::Tristate::True
            && cp_1 == nts::Tristate::False
            && prev_cp1 == nts::Tristate::True))
    {
        if (cur_idx > 9)
            cur_idx = 0;
        all_out_false();
        setPinVal(_index[cur_idx], nts::Tristate::True);
        if (isLink(_index[cur_idx]))
            loadPinVal(_index[cur_idx]);
        cur_idx++;
    }
    (cur_idx < 6) ? setPinVal(12, TRUE) : setPinVal(12, FALSE);
    if (isLink(12))
        loadPinVal(12);
    prev_cp0 = cp_0;
    prev_cp1 = cp_1;
}


