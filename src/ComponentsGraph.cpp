/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** ComponentGraph.cpp
*/

#include "ComponentManager.hpp"
#include "ComponentsGraph.hpp"
#include "DataComponents.hpp"

// Default constructor for component Graph
nts::ComponentsGraph::ComponentsGraph() : _ticks(0), _iGraph(0) {}

// Constructor which init a graph with the data given as parameter
nts::ComponentsGraph::ComponentsGraph(File::FileParser &ntsFile) : _ticks(0), _iGraph(0)
{
    std::string tmpComponent;
    std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>> tmpLinks;

    while (!(tmpComponent = ntsFile.getComponentName()).empty()) {
        nts::ComponentManager tmpManager(tmpComponent);
        _graph.push_back(tmpManager.createComponent(ntsFile.getComponentTypeByName(tmpComponent)));
    }
    ntsFile.resetComponentsGetter();
    while (!(tmpLinks = ntsFile.getLinkComponents()).first.first.empty()) {
        this->getComponent(tmpLinks.first.first).setLink(tmpLinks.first.second,
            this->getComponent(tmpLinks.second.first), tmpLinks.second.second);
        this->getComponent(tmpLinks.second.first).setLink(tmpLinks.second.second,
            this->getComponent(tmpLinks.first.first), tmpLinks.first.second);
    }
    ntsFile.resetComponentsGetter();
}

nts::ComponentsGraph::~ComponentsGraph() {}

// Create the graph with the data given as parameter
void nts::ComponentsGraph::fillGraph(File::FileParser &ntsFile)
{
    std::string tmpComponent;
    std::pair<std::pair<std::string, std::size_t>, std::pair<std::string, std::size_t>> tmpLinks;

    while (!(tmpComponent = ntsFile.getComponentName()).empty()) {
        nts::ComponentManager tmpManager(tmpComponent);
        _graph.push_back(tmpManager.createComponent(ntsFile.getComponentTypeByName(tmpComponent)));
    }
    ntsFile.resetComponentsGetter();
    while (!(tmpLinks = ntsFile.getLinkComponents()).first.first.empty()) {
        this->getComponent(tmpLinks.first.first).setLink(tmpLinks.first.second,
            this->getComponent(tmpLinks.second.first), tmpLinks.second.second);
        this->getComponent(tmpLinks.second.first).setLink(tmpLinks.second.second,
            this->getComponent(tmpLinks.first.first), tmpLinks.first.second);
    }
    ntsFile.resetLinksComponentsGetter();
}

// Get component with her name
nts::IComponent &nts::ComponentsGraph::getComponent(const std::string &componentName) const
{
    for (auto it = _graph.begin(); it != _graph.end(); ++it) {
        if ((*it)->getName() == componentName) {
            return *(*it);
        }
    }
    throw nts::Error("-E- Component not found.");
}

// Increment thick by one in the simulation of the graph
void nts::ComponentsGraph::incrementThicks()
{
    _ticks++;
}

// Get the number of thicks in the simulation
std::size_t nts::ComponentsGraph::getThicks() const
{
    return _ticks;
}

// Get each component in the graph
nts::IComponent *nts::ComponentsGraph::getGraphComponent(bool &end)
{
    if (_iGraph == _graph.size()) {
        end = true;
        return _graph.at(_iGraph - 1).get();
    }
    std::size_t i = _iGraph;
    _iGraph++;
    return _graph.at(i).get();
}

// Reset the getter of each components on the graph
void nts::ComponentsGraph::resetGraphComponentGetter()
{
    _iGraph = 0;
}

void nts::ComponentsGraph::resetLinksState()
{
    for (auto it = _graph.begin(); it != _graph.end(); ++it) {
        (*it).get()->resetLinkState();
    }
}
