/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** Chipsets.cpp
*/

#include "StringImproved.hpp"
#include "FileParser.hpp"

/*----- Parser Chipsets -----*/

// Constructor for chipsets
File::Chipsets::Chipsets() : _iComponentsNames(0) {}

//Destructor for chipsets
File::Chipsets::~Chipsets() {}

// Method which parse chipsets part with error handling if nothing find
void File::Chipsets::chipsetsParser(const std::string &fileContent, std::size_t posChipsets, std::size_t posLinks)
{
    std::size_t n;

    posChipsets += 10;
    n = posLinks - posChipsets;
    std::string chipsetsData = fileContent.substr(posChipsets, n);
    std::vector<std::string> splitChipsetsData = StringImproved::splitStr(chipsetsData, "\n");
    this->componentsParser(splitChipsetsData);
}

// Protected method which parser id and type chipsets component with error handling in case of invalid syntax
void File::Chipsets::componentsParser(std::vector<std::string> &splitChipsetsData)
{
    auto it = splitChipsetsData.begin();

    while (!splitChipsetsData.empty()) {
        std::vector<std::string> splitLine = StringImproved::splitStr(splitChipsetsData.at(0), " \t");
        if (splitLine.empty()) {
            splitChipsetsData.erase(it);
            it = splitChipsetsData.begin();
            continue;
        }
        if (splitLine.size() != 2) {
            throw File::Error("-E- Invalid Syntax (bad arguments on chipsets data).");
        }
        if (StringImproved::existInArray(_components, splitLine.at(1))) {
            throw File::Error("-E- Multiple definition (component already declared).");
        }
        _components.push_back(std::pair<std::string, std::string>(splitLine.at(0), splitLine.at(1)));
        splitChipsetsData.erase(it);
        it = splitChipsetsData.begin();
    }
    if (_components.empty()) {
        throw File::Error("-E- No components in chipsets.");
    }
}

// Method for get each component Id. He's auto increment himself
std::string File::Chipsets::getComponentName()
{
    if (_iComponentsNames == _components.size()) {
        return std::string("");
    }
    std::size_t i = _iComponentsNames;
    _iComponentsNames++;
    return _components.at(i).second;
}

// Get the component type by a name (return empty string if nothing was find)
std::string File::Chipsets::getComponentTypeByName(const std::string &name)
{
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        if ((*it).second == name) {
            return (*it).first;
        }
    }
    return std::string("");
}

// Check if the component exists
bool File::Chipsets::componentNameExists(const std::string &name) const
{
    for (auto it = _components.begin(); it != _components.end(); ++it) {
        if ((*it).second == name) {
            return true;
        }
    }
    return false;
}

// Method which reset iterators getter components
void File::Chipsets::resetComponentsGetter()
{
    _iComponentsNames = 0;
}
