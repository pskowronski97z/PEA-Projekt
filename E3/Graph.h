//
// Created by pskowronski on 31.12.2019.
//

#ifndef E3_GRAPH_H
#define E3_GRAPH_H
#include <string>

class Graph {

private:

    int **matrix = nullptr;
    int vert_count = 0;
    std::string description = "";

public:

    std::string getDescription();
    std::string toString();
    bool readGraph(std::string file);
    bool readGraphSmall(std::string file);
    int getCount();
    int** getMatrix();
    Graph();
    ~Graph();
};

#endif //E3_GRAPH_H
