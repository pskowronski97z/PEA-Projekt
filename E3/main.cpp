#include <iostream>
#include "Graph.h"
#include "GeneticAlgorithm.h"
#include <vector>
#include <time.h>

int main()
{
    srand(time(NULL));
    Graph graph;
    graph.readGraphSmall("tsp_10.txt");
    GeneticAlgorithm alg(&graph,2,1000000,0.8,0.01);
    alg.apply();

    return 0;
}
