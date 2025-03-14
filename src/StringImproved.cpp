/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** StringImproved.cpp
*/

#include "StringImproved.hpp"

#include <sstream>

/*----- Manipulate String -----*/

// Split String with multiples delimiters
std::vector<std::string> StringImproved::splitStr(const std::string &str, const std::string &delimiters)
{
    std::string cpyStr = str;
    std::vector<std::string> splited;
    std::size_t i = 0;

    while (i < cpyStr.length()) {
        if (delimiters.find(cpyStr.at(i)) != std::string::npos) {
            std::string tmpStr = cpyStr.substr(0, i);
            cpyStr.erase(0, (i + 1));
            i = 0;
            if (tmpStr.empty()) {
                continue;
            }
            splited.push_back(tmpStr);
            continue;
        }
        i++;
    }
    if (!cpyStr.empty()) {
        splited.push_back(cpyStr);
    }
    return splited;
}

// Check if every char in the string are digits
bool StringImproved::isNumber(const std::string &str)
{
    for (std::size_t i = 0; i < str.length(); i++) {
        if (std::isdigit(str.at(i))) {
            continue;
        }
        return false;
    }
    return true;
}

// Erase all occurences in a string
void StringImproved::eraseOccurrences(std::string &str, const std::string &occurrences)
{
    std::size_t i = 0;

    while (i < str.length()) {
        if (occurrences.find(str.at(i)) != std::string::npos) {
            str.erase(i, 1);
            i = 0;
            continue;
        }
        i++;
    }
}

// Delete every characters after occurrence like '#' and preserve '\n'
bool StringImproved::deleteAfterOccurrence(std::string &str, char occurrence)
{
    std::size_t i = 0;
    std::size_t limit;
    std::size_t n;

    for (; i < str.length(); i++) {
        if (str.at(i) == occurrence) {
            break;
        }
    }
    if (i == str.length()) {
        return false;
    }
    limit = i + 1;
    for (; limit < str.length(); limit++) {
        if (str.at(limit) == '\n') {
            break;
        }
    }
    n = limit - i;
    str.erase(i, n);
    return true;
}

// Check if the string respect the pattern given as parameter and return true or false
bool StringImproved::isRespectPattern(const std::string &str, const std::string &pattern)
{
    std::string cpyPattern = pattern;
    std::vector<std::string> patternArray;

    std::string delimitersPattern;
    std::vector<std::string> patternMatchingOnStr;

    std::string tmpStr;
    for (; !cpyPattern.empty();) {
        if (cpyPattern.substr(0, 3) == "...") {
            if (!tmpStr.empty()) {
                patternArray.push_back(tmpStr);
                tmpStr.clear();
            }
            patternArray.push_back("...");
            cpyPattern.erase(0, 3);
            continue;
        }
        tmpStr.push_back(cpyPattern.at(0));
        cpyPattern.erase(0, 1);
    }
    if (!tmpStr.empty()) {
        patternArray.push_back(tmpStr);
    }
    for (auto it = patternArray.begin(); it != patternArray.end();) {
        if ((*it) != "...") {
            delimitersPattern.append((*it));
            patternArray.erase(it);
            it = patternArray.begin();
            continue;
        }
        it++;
    }
    patternMatchingOnStr = StringImproved::splitStr(str, delimitersPattern);
    if (patternMatchingOnStr.size() == patternArray.size()) {
        return true;
    }
    return false;
}

/*----- Convert To String -----*/

// Convert file content to string with ifstream
std::string StringImproved::convertFileToStr(const std::ifstream &file)
{
    std::string fileStr;

    if (!file.is_open()) {
        return fileStr;
    }
    std::ostringstream fileConvert;
    fileConvert << file.rdbuf();
    fileStr = fileConvert.str();
    return fileStr;
}

// Convert file content to string with ofstream
std::string StringImproved::convertFileToStr(const std::ofstream &file)
{
    std::string fileStr;

    if (!file.is_open()) {
        return fileStr;
    }
    std::ostringstream fileConvert;
    fileConvert << file.rdbuf();
    fileStr = fileConvert.str();
    return fileStr;
}

/*----- Manipulate String into arrays -----*/

// Check into the array of strings if the string exist
bool StringImproved::existInArray(const std::vector<std::string> &array, const std::string &str)
{
    for (auto it = array.begin(); it != array.end(); ++it) {
        if ((*it) == str) {
            return true;
        }
    }
    return false;
}

// Check into the array of pair of string if the pair of strings exist
bool StringImproved::existInArray(const std::vector<std::pair<std::string, std::string>> &array, const std::string &str)
{
    for (auto it = array.begin(); it != array.end(); ++it) {
        if ((*it).second == str) {
            return true;
        }
    }
    return false;
}
