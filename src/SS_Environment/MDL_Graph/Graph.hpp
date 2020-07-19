#ifndef GRAPH_CLASS_H
#define GRAPH_CLASS_H

#include <algorithm>
#include <fstream>
#include <vector>

#include "../../Common/CommonDefines.hpp"
#include "../../Common/MDL_CommandQueue/CommandQueue.hpp"
#include "../MDL_Edge/Edge.hpp"

class Graph
{
    public:
        Graph();
        ~Graph();
        int init(std::string filePath);
        std::vector<Edge> getEdges();
        bool isValidMovement(int command);
        friend bool operator== (const Edge &e1, const Edge &e2);

    private:
        void addEdge(Edge e);
        bool isEdgeExist(Edge e);
        int getNextVertex(int command);

        int m_currentVertex;
        std::vector<Edge> m_edges; // List of all valid Edge objects
};

#endif
