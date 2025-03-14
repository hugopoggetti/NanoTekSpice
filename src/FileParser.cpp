/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** FileParser.cpp
*/

#include "FileParser.hpp"
#include "StringImproved.hpp"
#include "DataComponents.hpp"

#include <fstream>
#include <filesystem>

/*----- Handling File Parser -----*/

// Constructor by default for File Parser
File::FileParser::FileParser() {}

// Constructor with open and parse file
File::FileParser::FileParser(const std::string &filePath) : _filePath(filePath)
{
    std::ifstream file;
    std::size_t posChipsets;
    std::size_t posLinks;

    _filePath = filePath;
    file.open(_filePath.c_str());
    if (!file.is_open()) {
        throw File::Error("-E- Cannot open .nts file.");
    }
    _fileContent = StringImproved::convertFileToStr(file);
    while (StringImproved::deleteAfterOccurrence(_fileContent, '#'));
    posChipsets = _fileContent.find(".chipsets:");
    if (posChipsets == std::string::npos) {
        throw File::Error("-E- Not .chipsets in this file.");
    }
    posLinks = _fileContent.find(".links:");
    if (posLinks == std::string::npos) {
        throw File::Error("-E- Not .links find in file.");
    }
    if (posChipsets > posLinks) {
        throw File::Error("-E- Invalid order declaration (Links before Chipsets).");
    }
    this->chipsetsParser(_fileContent, posChipsets, posLinks);
    this->linksParser(_fileContent, posLinks);
    this->checkValidComponents();
}

// Destructor for File Parser
File::FileParser::~FileParser() {}

// Method with re-open and parse file
void File::FileParser::openFile(const std::string &filePath)
{
    std::ifstream file;
    std::size_t posChipsets;
    std::size_t posLinks;

    _filePath = filePath;
    if (!std::filesystem::path(_filePath).has_extension() ||
        std::filesystem::path(_filePath).extension() != ".nts") {
        throw File::Error("-E- No file extension .nts.");
    }
    file.open(_filePath.c_str());
    if (!file.is_open()) {
        throw File::Error("-E- Cannot open .nts file.");
    }
    _fileContent = StringImproved::convertFileToStr(file);
    while (StringImproved::deleteAfterOccurrence(_fileContent, '#'));
    posChipsets = _fileContent.find(".chipsets:");
    if (posChipsets == std::string::npos) {
        throw File::Error("-E- Not .chipsets in this file.");
    }
    posLinks = _fileContent.find(".links:");
    if (posLinks == std::string::npos) {
        throw File::Error("-E- Not .links find in file.");
    }
    if (posChipsets > posLinks) {
        throw File::Error("-E- Invalid order declaration (Links before Chipsets).");
    }
    this->chipsetsParser(_fileContent, posChipsets, posLinks);
    this->linksParser(_fileContent, posLinks);
    this->checkValidComponents();
}

// Check if every components used in links are valids (declared, existing, pins number)
void File::FileParser::checkValidComponents()
{
    std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>> linkComponents;

    while(!(linkComponents = this->getLinkComponents()).first.first.empty()) {
        if (!this->componentNameExists(linkComponents.first.first) ||
            !this->componentNameExists(linkComponents.second.first)) {
            throw File::Error("-E- Component used but not declared.");
        }
        if ((*nts::dataComponents.find(this->getComponentTypeByName
            (linkComponents.first.first))).first.empty() ||
            (*nts::dataComponents.find(this->getComponentTypeByName
            (linkComponents.second.first))).first.empty()) {
            throw File::Error("-E- Component isn't exists.");
        }
        if ((linkComponents.first.second > (*nts::dataComponents.find(this->getComponentTypeByName
            (linkComponents.first.first))).second || linkComponents.first.second == 0) ||
            (linkComponents.second.second > (*nts::dataComponents.find(this->getComponentTypeByName
            (linkComponents.second.first))).second || linkComponents.second.second == 0)) {
            throw File::Error("-E- Component have too many pins.");
        }
    }
    this->resetLinksComponentsGetter();
}

// Method which return file path
const std::string &File::FileParser::getFilePath() const
{
    return _filePath;
}

// Method which return file content
const std::string &File::FileParser::getFileContent() const
{
    return _fileContent;
}
