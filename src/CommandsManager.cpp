/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** CommandsManager.cpp
*/

#include "StringImproved.hpp"
#include "Commands.hpp"

#include <iostream>

bool Commands::CommandsManager::stateLoop = false;

// Constructor by default the class which declare a prompt and set simulation speed to zero
Commands::CommandsManager::CommandsManager() : _simulationSpeed(0), _prompt(std::cin, "> ") {}

// Constructor which take parameter (set simulation speed) and set prompt
Commands::CommandsManager::CommandsManager(std::size_t simulationSpeed) : _simulationSpeed(simulationSpeed),
    _prompt(std::cin, "> ")
{
    if (_simulationSpeed > 100) {
        _simulationSpeed = 100;
    }
}

// Default destructor
Commands::CommandsManager::~CommandsManager() {}

// Set a new simulation speed
void Commands::CommandsManager::changeSimulationSpeed(std::size_t simulationSpeed)
{
    _simulationSpeed = simulationSpeed;
    if (_simulationSpeed > 100) {
        _simulationSpeed = 100;
    }
}

// Get simulation speed of the current program
std::size_t Commands::CommandsManager::getSimulationSpeed() const
{
    return _simulationSpeed;
}

// Run program / read command with the prompt / check if the commands exists and manage commands
void Commands::CommandsManager::run(nts::ComponentsGraph &componentsGraph)
{
    while (_prompt.readLine()) {
        std::string command = _prompt.getCommand();
        if (StringImproved::isRespectPattern(command, "...=...")) {
            try {
                std::pair<std::string, nts::Tristate> newValueToAssign = this->assignCommand(command);
                if (!StringImproved::existInArray(Commands::assignableComponents,
                    componentsGraph.getComponent(newValueToAssign.first).getType())) {
                    throw Commands::Error("-E- State not assignable to this component.");
                }
                componentsGraph.getComponent(newValueToAssign.first).
                    setPinVal(1, newValueToAssign.second);
            } catch (nts::Error &e) {
                std::cerr << e.what() << std::endl;
            } catch (Commands::Error &e) {
                std::cerr << e.what() << std::endl;
            }
            continue;
        }
        if ((*Commands::commands.find(command)).first.empty()) {
            std::cerr << "-E- Command not find." << std::endl;
            continue;
        }
        if (!(*Commands::commands.find(command)).second(_simulationSpeed, componentsGraph)) {
            return;
        }
    }
}

// Assign a value to a component name and check if the value given is correct
std::pair<std::string, nts::Tristate> Commands::CommandsManager::assignCommand(const std::string &command)
{
    std::pair<std::string, nts::Tristate> assign;
    std::vector<std::string> splitCommand = StringImproved::splitStr(command, "=");

    StringImproved::eraseOccurrences(splitCommand.at(0), " \t");
    StringImproved::eraseOccurrences(splitCommand.at(1), " \t");
    assign.first = splitCommand.at(0);
    if (!splitCommand.at(1).compare("U")) {
        assign.second = nts::Undefined;
        return assign;
    }
    if (!splitCommand.at(1).compare("1")) {
        assign.second = nts::True;
        return assign;
    }
    if (!splitCommand.at(1).compare("0")) {
        assign.second = nts::False;
        return assign;
    }
    throw Commands::Error("-E- Bad state passed in command.");
}
