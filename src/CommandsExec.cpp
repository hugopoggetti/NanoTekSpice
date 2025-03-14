/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** CommandsExec.cpp
*/

#include "Commands.hpp"

#include <iostream>
#include <unistd.h>
#include <algorithm>

bool Commands::CommandsExec::exit(__attribute__((unused)) std::size_t unused,
    __attribute__((unused)) nts::ComponentsGraph &componentsGraph)
{
    return false;
}

bool Commands::CommandsExec::display(__attribute__((unused)) std::size_t unused,
    nts::ComponentsGraph &componentsGraph)
{
    std::vector<std::pair<std::string, std::string>> allInputs;
    std::vector<std::pair<std::string, std::string>> allOutputs;

    std::cout << "tick: " << componentsGraph.getThicks() << std::endl;
    allInputs = Commands::CommandsExec::getAllInputs(componentsGraph);
    std::sort(allInputs.begin(), allInputs.end());
    std::cout << "input(s):" << std::endl;
    for (auto it = allInputs.begin(); it != allInputs.end(); ++it) {
        std::cout << "  " << (*it).first << ": " << (*it).second << std::endl;
    }
    allOutputs = Commands::CommandsExec::getAllOutputs(componentsGraph);
    std::sort(allOutputs.begin(), allOutputs.end());
    std::cout << "output(s):" << std::endl;
    for (auto it = allOutputs.begin(); it != allOutputs.end(); ++it) {
        std::cout << "  " << (*it).first << ": " << (*it).second << std::endl;
    }
    return true;
}

bool Commands::CommandsExec::simulate(__attribute__((unused)) std::size_t unused,
    nts::ComponentsGraph &componentsGraph)
{
    bool isEndGraph = false;

    nts::IComponent *component = componentsGraph.getGraphComponent(isEndGraph);
    while (!isEndGraph) {
        if (component->getType() == "output" || component->getType() == "logger") {
            CommandsExec::simulateOrderedComponents(*component, componentsGraph.getThicks());
        }
        component = componentsGraph.getGraphComponent(isEndGraph);
    }
    componentsGraph.resetLinksState();
    componentsGraph.resetGraphComponentGetter();
    componentsGraph.incrementThicks();
    return true;
}

bool Commands::CommandsExec::loop(std::size_t simulationSpeed,
    __attribute__((unused)) nts::ComponentsGraph &componentsGraph)
{
    Commands::CommandsManager::stateLoop = true;

    while (Commands::CommandsManager::stateLoop) {
        Commands::CommandsExec::simulate(simulationSpeed, componentsGraph);
        Commands::CommandsExec::display(simulationSpeed, componentsGraph);
        if (simulationSpeed != 0) {
            std::size_t defaultSpeed = 1000;
            defaultSpeed -= (10 * simulationSpeed);
            usleep(defaultSpeed * 1000);
        }
    }
    return true;
}

std::vector<std::pair<std::string, std::string>> Commands::CommandsExec::getAllInputs
    (nts::ComponentsGraph &componentsGraph)
{
    std::vector<std::pair<std::string, std::string>> allInputs;
    bool isEndGraph = false;

    nts::IComponent *component = componentsGraph.getGraphComponent(isEndGraph);
    while (!isEndGraph) {
        if (component->getType() != "input" && component->getType() != "clock") {
            component = componentsGraph.getGraphComponent(isEndGraph);
            continue;
        }
        std::pair<std::string, std::string> tmpInput;
        tmpInput.first = component->getName();
        if (component->compute(1) == nts::Undefined) {
            tmpInput.second = "U";
        } else if (component->compute(1) == nts::True) {
            tmpInput.second = "1";
        } else {
            tmpInput.second = "0";
        }
        allInputs.push_back(tmpInput);
        component = componentsGraph.getGraphComponent(isEndGraph);
    }
    componentsGraph.resetGraphComponentGetter();
    return allInputs;
}

std::vector<std::pair<std::string, std::string>> Commands::CommandsExec::getAllOutputs
    (nts::ComponentsGraph &componentsGraph)
{
    std::vector<std::pair<std::string, std::string>> allOutputs;
    bool isEndGraph = false;

    nts::IComponent *component = componentsGraph.getGraphComponent(isEndGraph);
    while (!isEndGraph) {
        if (component->getType() != "output") {
            component = componentsGraph.getGraphComponent(isEndGraph);
            continue;
        }
        std::pair<std::string, std::string> tmpOutput;
        tmpOutput.first = component->getName();
        if (component->compute(1) == nts::Undefined) {
            tmpOutput.second = "U";
        } else if (component->compute(1) == nts::True) {
            tmpOutput.second = "1";
        } else {
            tmpOutput.second = "0";
        }
        allOutputs.push_back(tmpOutput);
        component = componentsGraph.getGraphComponent(isEndGraph);
    }
    componentsGraph.resetGraphComponentGetter();
    return allOutputs;
}

void Commands::CommandsExec::simulateOrderedComponents(nts::IComponent &component, std::size_t tick)
{
    if (component.getType() == "input") {
        component.simulate(tick);
        return;
    }
    for (std::size_t i = 0; i < component.getNbPins(); i++) {
        if (!component.isLink((i + 1))) {
            continue;
        }
        for (std::size_t j = 0; j < component.getNbLinks((i + 1)); j++) {
            if (component.getLinkState((i + 1), (j + 1))) {
                continue;
            }
            if (component.getLinkComponent((i + 1), (j + 1)).getType() == "output") {
                continue;
            }
            component.setLinkState((i + 1), (j + 1), true);
            simulateOrderedComponents(component.getLinkComponent((i + 1), (j + 1)), tick);
        }
    }
    component.simulate(tick);
}
