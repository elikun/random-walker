#include "Graph.hpp"

Graph::Graph() : m_currentVertex(0)
{
}

Graph::~Graph()
{
}

void Graph::addEdge(Edge e)
{
    if (e.isValidEdge() && !isEdgeExist(e)) {
        m_edges.push_back(e);
    }
}

bool Graph::isEdgeExist(Edge e)
{
    Edge eSwap(e.getV2(), e.getV1());
    if(std::find(m_edges.begin(), m_edges.end(), e) != m_edges.end() ||
       std::find(m_edges.begin(), m_edges.end(), eSwap) != m_edges.end()) {
        return true;
    }
    else {
        return false;
    }
}

std::vector<Edge> Graph::getEdges()
{
    return m_edges;
}

int Graph::init(std::string filePath)
{
    int retVal = -1;
    std::ifstream configFile(filePath);
    if (configFile.is_open()) {
        Edge e;
        std::string line;
        std::getline(configFile, line);
        while (std::getline(configFile, line)) {
            if (line.length() != 0) {
                e.setV1(std::stoi(line.substr(0, 2)));
                e.setV2(std::stoi(line.substr(3, 2)));
                addEdge(e);
            }
        }
        configFile.close();
        retVal = 0;
    }
    else {
        retVal = -1;
    }
    return retVal;
}

int Graph::getNextVertex(int cmd)
{
    int nextVertex = m_currentVertex;
    switch (cmd) {
        case 0: nextVertex -= 1;  break; // UP
        case 1: nextVertex += 1;  break; // DOWN
        case 2: nextVertex -= 10; break; // LEFT
        case 3: nextVertex += 10; break; // RIGHT
        default: break;
    }
    return nextVertex;
}

bool Graph::isValidMovement(int cmd)
{
    bool isValid = false;
    int nextVertex = getNextVertex(cmd);
    Edge e(m_currentVertex, nextVertex);
    if(isEdgeExist(e)) {
        m_currentVertex = nextVertex;
        isValid = true;
    }
    else {
        isValid = false;
    }
    return isValid;
}

bool operator== (const Edge &e1, const Edge &e2)
{
    return e1.getV1() == e2.getV1() && e1.getV2() == e2.getV2();
}
