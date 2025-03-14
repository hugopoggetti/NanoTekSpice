/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** CommandsManager.hpp
*/

#ifndef _COMMANDSMANAGER_
    #define _COMMANDSMANAGER_

#include "Prompt.hpp"
#include "AComponent.hpp"
#include "ComponentsGraph.hpp"

#include <exception>
#include <string>
#include <map>
#include <functional>

namespace Commands
{
    class CommandsManager {
        public:
            CommandsManager();
            CommandsManager(std::size_t simulationSpeed);
            ~CommandsManager();
            void changeSimulationSpeed(std::size_t simulationSpeed);
            std::size_t getSimulationSpeed() const;
            void run(nts::ComponentsGraph &componentsGraph);

            static bool stateLoop;
        private:
            std::pair<std::string, nts::Tristate> assignCommand(const std::string &command);

            std::size_t _simulationSpeed;
            Prompt _prompt;
    };

    const std::vector<std::string> assignableComponents {"input", "output", "true", "false", "clock"};

    class CommandsExec {
        public:
            static bool exit(std::size_t unused, nts::ComponentsGraph &componentsGraph);
            static bool display(std::size_t unused, nts::ComponentsGraph &componentsGraph);
            static bool simulate(std::size_t unused, nts::ComponentsGraph &componentsGraph);
            static bool loop(std::size_t simulationSpeed, nts::ComponentsGraph &componentsGraph);
        private:
            static std::vector<std::pair<std::string, std::string>> getAllInputs(nts::ComponentsGraph &componentsGraph);
            static std::vector<std::pair<std::string, std::string>> getAllOutputs(nts::ComponentsGraph &componentsGraph);
            static void simulateOrderedComponents(nts::IComponent &component, std::size_t tick);
    };

    const std::map<std::string, std::function<bool(std::size_t, nts::ComponentsGraph &)>> commands {
        {"exit", [](std::size_t unused, nts::ComponentsGraph &componentsGraph)
            {return CommandsExec::exit(unused, componentsGraph);}},
        {"display", [](std::size_t unused, nts::ComponentsGraph &componentsGraph)
            {return CommandsExec::display(unused, componentsGraph);}},
        {"simulate", [](std::size_t unused, nts::ComponentsGraph &componentsGraph)
            {return CommandsExec::simulate(unused, componentsGraph);}},
        {"loop", [](std::size_t simulationSpeed, nts::ComponentsGraph &componentsGraph)
            {return CommandsExec::loop(simulationSpeed, componentsGraph);}}
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
