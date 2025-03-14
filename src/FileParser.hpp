/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** FileParser.hpp
*/

#ifndef _FILEPARSER_
    #define _FILEPARSER_

#include <exception>
#include <string>
#include <vector>
#include <map>

namespace File
{
    class Chipsets {
        public:
            Chipsets();
            ~Chipsets();
            void chipsetsParser(const std::string &fileContent, std::size_t posChipsets, std::size_t posLinks);
            std::string getComponentName();
            std::string getComponentTypeByName(const std::string &name);
            void resetComponentsGetter();
            bool componentNameExists(const std::string &name) const;
        private:
            void componentsParser(std::vector<std::string> &splitChipsetsData);

            std::vector<std::pair<std::string, std::string>> _components;
            std::size_t _iComponentsNames;
    };

    class Links {
        public:
            Links();
            ~Links();
            void linksParser(const std::string &fileContent, std::size_t posLinks);
            std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>> getLinkComponents();
            void resetLinksComponentsGetter();
        private:
            void linksComponentParser(std::vector<std::string> &splitLinksData);
            void checkLinkArguments(const std::vector<std::string> &linkArguments);

            std::vector<std::pair<std::pair<std::string, std::size_t>,
                std::pair<std::string, std::size_t>>> _linksComponents;
            std::size_t _iLinksComponents;
    };

    class FileParser : public Chipsets, public Links {
        public:
            FileParser();
            FileParser(const std::string &filePath);
            ~FileParser();
            void openFile(const std::string &filePath);
            const std::string &getFilePath() const;
            const std::string &getFileContent() const;
        private:
            void checkValidComponents();

            std::string _filePath;
            std::string _fileContent;
    };

    class Error : public std::exception {
        public:
            Error(const std::string &error) : _error(error) {}
            ~Error() = default;
            const char *what() const noexcept {return _error.c_str();}
        private:
            std::string _error;
    };
}

#endif
