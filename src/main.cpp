/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** main.cpp
*/

#include "FileParser.hpp"
#include "Commands.hpp"
#include "ComponentsGraph.hpp"

#include <signal.h>

static void handler(__attribute__((unused)) int code)
{
    if (Commands::CommandsManager::stateLoop) {
        Commands::CommandsManager::stateLoop = false;
        return;
    }
    std::exit(130);
}

int main(int argc, const char **argv)
{
     if (argc != 2) {
        std::cerr << "-E- Wrong number arguments of program." << std::endl;
        return 84;
    }
    File::FileParser ntsFile;
    try {
        ntsFile.openFile(argv[1]);
    } catch (File::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    nts::ComponentsGraph componentsGraph(ntsFile);
    signal(SIGINT, &handler);
    Commands::CommandsManager sim;
    try {
        sim.run(componentsGraph);
    } catch (Commands::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
