#ifndef EDGE_CLASS_H
#define EDGE_CLASS_H

#include "../EnvironmentConstants.hpp"

class Edge
{
    public:
        Edge();
        Edge(int a, int b);
        ~Edge();
        bool isValidEdge();
        int getV1() const;
        int getV2() const;
        void setV1(int v);
        void setV2(int v);

    private:
        int v1; // Format: 2-digit XY vertex
        int v2; // Format: 2-digit XY vertex
};

#endif