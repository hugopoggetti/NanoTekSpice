#include "4094Component.hpp"
#include "IComponent.hpp"

nts::Component4094::Component4094(const std::string &name)
{
    _name = name;
    _type = "4094";
    _prev_cl = nts::Tristate::Undefined;
    _pinsLinks.resize(16);
    _pinsLinksState.resize(16);
    _pinsValue.resize(16);
    for (std::size_t i = 0; i < 16; i++) {
        _pinsValue.at(i) = nts::Tristate::Undefined;
        _pinsLinks.at(i).first = i + 1;
        _pinsLinksState.at(i).first = i + 1;
    }
    _prev_strobe = nts::Tristate::Undefined;
    _prev_qs = nts::Tristate::Undefined;
    _shitf_tmp.resize(8, nts::Tristate::False);
    _latch.resize(8, nts::Tristate::False);
}

void nts::Component4094::simulate(__attribute__((unused))
        std::size_t thick)
{
    nts::Tristate data = compute(2);
    nts::Tristate strobe = compute(1); 
    nts::Tristate clock = compute(3); 
    nts::Tristate enable = compute(15);

    const std::vector<std::size_t> _idx = 
    {
        4,
        5,
        6,
        7,
        14,
        13,
        12,
        11,
    };
    if (clock == nts::Tristate::True 
            && _prev_cl == nts::Tristate::False)
    {
        for (int i = 7; i > 0; --i)
            _shitf_tmp[i] = _shitf_tmp[i - 1];
        _shitf_tmp[0] = data;
        setPinVal(9, _shitf_tmp[7]);
        setPinVal(10, _prev_qs);
        if (isLink(9)) loadPinVal(9);
        if (isLink(10)) loadPinVal(10);

    }
    _prev_qs = _shitf_tmp[7];
    
    if (strobe == nts::Tristate::False
        && _prev_strobe == nts::Tristate::True) {
        for (int i = 0; i < 8; ++i)
            _latch[i] = _shitf_tmp[i];
    }
    for (int i = 0; i < 8; ++i) {
        if (enable == nts::Tristate::False)
            setPinVal(_idx[i], nts::Tristate::Undefined);
        else
            setPinVal(_idx[i], _latch[i]);
        if (isLink(_idx[i]))
            loadPinVal(_idx[i]);
    }
    _prev_cl = clock;
    _prev_strobe = strobe;
}
