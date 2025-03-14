/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** StringImproved.hpp
*/

#ifndef _STRINGIMPROVED_
    #define _STRINGIMPROVED_

#include <string>
#include <vector>
#include <fstream>
#include <map>

class StringImproved {
    public:
        static std::vector<std::string> splitStr(const std::string &str, const std::string &delimiters);
        static void eraseOccurrences(std::string &str, const std::string &occurrences);
        static bool deleteAfterOccurrence(std::string &str, char occurrence);
        static bool isNumber(const std::string &str);
        static bool isRespectPattern(const std::string &str, const std::string &pattern);
        static std::string convertFileToStr(const std::ifstream &file);
        static std::string convertFileToStr(const std::ofstream &file);
        static bool existInArray(const std::vector<std::string> &array, const std::string &str);
        static bool existInArray(const std::vector<std::pair<std::string, std::string>> &array, const std::string &str);
};

#endif
