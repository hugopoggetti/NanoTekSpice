/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** Links.cpp
*/

#include "StringImproved.hpp"
#include "FileParser.hpp"

/*----- Handling Parser Links -----*/

// Construct class and init iterator
File::Links::Links() : _iLinksComponents(0) {}

// Default destructor class
File::Links::~Links() {}

// Parse the links data
void File::Links::linksParser(const std::string &fileContent, std::size_t posLinks)
{
    std::size_t n;

    posLinks += 7;
    std::size_t limit = posLinks;
    for (; limit < fileContent.length(); limit++);
    n = limit - posLinks;
    std::string linksData = fileContent.substr(posLinks, n);
    std::vector<std::string> splitLinksData = StringImproved::splitStr(linksData, "\n");
    this->linksComponentParser(splitLinksData);
}

// Check if each arguments of link in a line is correctly formated
void File::Links::checkLinkArguments(const std::vector<std::string> &linkArguments)
{
    if (linkArguments.size() != 2) {
        throw File::Error("-E- Invalid Syntax (links arguments bad format).");
    }
    if (!StringImproved::isNumber(linkArguments.at(1))) {
        throw File::Error("-E- Invalid Syntax (pin indicated is not a number).");
    }
}

// Parse each line and push into a pair array the links
void File::Links::linksComponentParser(std::vector<std::string> &splitLinksData)
{
    auto it = splitLinksData.begin();

    while (!splitLinksData.empty()) {
        std::vector<std::string> splitLine = StringImproved::splitStr((*it), " \t");
        if (splitLine.empty()) {
            splitLinksData.erase(it);
            it = splitLinksData.begin();
            continue;
        }
        if (splitLine.size() != 2) {
            throw File::Error("-E- Invalid Syntax (bad arguments on links data).");
        }
        std::vector<std::string> firstLinkArguments = StringImproved::splitStr(splitLine.at(0), ":");
        this->checkLinkArguments(firstLinkArguments);
        std::vector<std::string> secondLinkArguments = StringImproved::splitStr(splitLine.at(1), ":");
        this->checkLinkArguments(secondLinkArguments);
        std::size_t firstPin = std::atoi(firstLinkArguments.at(1).c_str());
        std::size_t secondPin = std::atoi(secondLinkArguments.at(1).c_str());
        std::pair<std::string, std::size_t> firstComponent(firstLinkArguments.at(0), firstPin);
        std::pair<std::string, std::size_t> secondComponent(secondLinkArguments.at(0), secondPin);
        _linksComponents.push_back(std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>
            (firstComponent, secondComponent));
        splitLinksData.erase(it);
        it = splitLinksData.begin();
    }
}

// Allow to access each links components
std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>> File::Links::getLinkComponents()
{
    if (_iLinksComponents == _linksComponents.size()) {
        return std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>>();
    }
    std::size_t i = _iLinksComponents;
    _iLinksComponents++;
    return _linksComponents.at(i);
}

// Reset iterator
void File::Links::resetLinksComponentsGetter()
{
    _iLinksComponents = 0;
}
