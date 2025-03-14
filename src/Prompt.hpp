/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** Prompt.hpp
*/

#ifndef _PROMPT_
    #define _PROMPT_

#include <iostream>
#include <string>

class Prompt {
    public:
        Prompt();
        Prompt(std::istream &stream);
        Prompt(std::istream &stream, const std::string &prompt);
        ~Prompt();
        bool readLine();
        const std::string &getCommand() const;
    private:
        std::istream &_stream;
        std::string _command;
        std::string _prompt;
};

#endif
