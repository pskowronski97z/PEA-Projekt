#include <iostream>
#include "Graph.h"
#include "GeneticAlgorithm.h"
#include <vector>
#include <time.h>

int main()
{
    srand(time(NULL));
    Graph graph;
    graph.readGraph("ftv47.atsp");
    GeneticAlgorithm alg(&graph,120,10000,0.8,0.01);
    alg.apply();

    return 0;
}
