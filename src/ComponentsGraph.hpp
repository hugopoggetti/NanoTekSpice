/*
** EPITECH PROJECT, 2025
** B-OOP-400-TLS-4-1-tekspice-guillaume1.blondel
** File description:
** ComponentGraph.hpp
*/

#ifndef _COMPONENTGRAPH_
    #define _COMPONENTGRAPH_

#include "FileParser.hpp"
#include "AComponent.hpp"

#include <vector>
#include <memory>
#include <exception>

namespace nts
{
    class ComponentsGraph {
        public:
            ComponentsGraph();
            ComponentsGraph(File::FileParser &ntsFile);
            ~ComponentsGraph();
            void fillGraph(File::FileParser &ntsFile);
            nts::IComponent &getComponent(const std::string &componentName) const;
            void incrementThicks();
            std::size_t getThicks() const;
            nts::IComponent *getGraphComponent(bool &end);
            void resetGraphComponentGetter();
            void resetLinksState();
        private:
            std::vector<std::unique_ptr<nts::IComponent>> _graph;
            std::size_t _ticks;
            std::size_t _iGraph;
    };
}

#endif
