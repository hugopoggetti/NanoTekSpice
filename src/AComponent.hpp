/*
** EPITECH PROJECT, 2025
** Nano
** File description:
** Acomponent
*/

#ifndef _ACOMPONENT_
    #define _ACOMPONENT_

#include "IComponent.hpp"

#include <vector>
#include <map>
#include <exception>

namespace nts
{
    class AComponent : public IComponent {
        public:
            AComponent() = default;
            ~AComponent() = default;
            const std::string &getName() const;
            const std::string &getType() const;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
            nts::Tristate compute(std::size_t pin);
            void setPinVal(std::size_t pin, nts::Tristate val);
            void loadPinVal(std::size_t pin);
            std::size_t getNbPins() const;
            bool isLink(std::size_t pin) const;
            std::size_t getNbLinks(std::size_t pin) const;
            bool getLinkState(std::size_t pin, std::size_t otherPin) const;
            void setLinkState(std::size_t pin, std::size_t otherPin, bool state);
            void setBidirectionalLinkState(std::size_t pin, const std::string &componentName, bool state);
            void resetLinkState();
            nts::IComponent &getLinkComponent(std::size_t pin, std::size_t otherPin);
        protected:
            std::string _name;
            std::string _type;
            std::vector<std::pair<std::size_t,
                std::vector<std::pair<std::size_t
                    , nts::IComponent &>>>> _pinsLinks;
            std::vector<std::pair<std::size_t,
                std::vector<std::pair<std::size_t,
                bool>>>> _pinsLinksState;
            std::vector<nts::Tristate> _pinsValue;
    };

    class Error : std::exception {
        public:
            Error(const std::string &error) : _error(error) {}
            ~Error() = default;
            const char *what() const noexcept {return _error.c_str();}
        private:
            std::string _error;
    };
}

#endif
