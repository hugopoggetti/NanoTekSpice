/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** Prompt.cpp
*/

#include "Prompt.hpp"

// Constructor by default which set stdin
Prompt::Prompt() : _stream(std::cin) {}

// Constructor which set special stream pass in parameter
Prompt::Prompt(std::istream &stream) : _stream(stream) {}

// Constructor which set special stream pass in parameter and a prompt string
Prompt::Prompt(std::istream &stream, const std::string &prompt) : _stream(stream), _prompt(prompt) {}

Prompt::~Prompt() {}

// Read a line and display prompt before
bool Prompt::readLine()
{
    std::cout << _prompt;
    if (std::getline(_stream, _command)) {
        return true;
    }
    return false;
}

// Return the string / command who has been read
const std::string &Prompt::getCommand() const
{
    return _command;
}
