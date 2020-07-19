#include "Edge.hpp"

Edge::Edge()
{
}

Edge::Edge(int a, int b) : v1(a), v2(b)
{
}

Edge::~Edge()
{
}

bool Edge::isValidEdge()
{
    bool retVal = false;

    // Check if vertices are within the defined environment boundaries
    if (v1 != v2 && v1 >= 0 && v2 >= 0 && v1 <= HIGHEST_GRAPH_VERTEX && v2 <= HIGHEST_GRAPH_VERTEX) {
        // Check if vertices are connected only horizontally or vertically
        if (v1 == v2 - 1 || v1 == v2 + 1 || v1 == v2 - 10 || v1 == v2 + 10) {
            retVal = true;
            // Confirm vertices in X9 line are not connected to vertices in X0 line
            if (v1 % 10 == 9) {
                if (v1 + 1 == v2) {
                    retVal = false;
                }
            }
            // Confirm vertices in X0 line are not connected to vertices in X9 line
            else if (v1 % 10 == 0) {
                if (v1 - 1 == v2) {
                    retVal = false;
                }
            }
        }
    }

    return retVal;
}

int Edge::getV1() const
{
    return v1;
}

int Edge::getV2() const
{
    return v2;
}

void Edge::setV1(int v)
{
    if (v >= 0 && v <= 99) {
        v1 = v;
    }
}

void Edge::setV2(int v)
{
    if (v >= 0 && v <= 99) {
        v2 = v;
    }
}