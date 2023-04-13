#pragma once
#include "location.h"


class Graph {
private:
    int** adjMat;
    static const int INF = 999999;
    int numberofVertices;
    int size;
public:
    Location** vertices;

    Graph(int size){
        this->size = size;
        numberofVertices = 0;

        vertices = new Location*[size]

    }


}

