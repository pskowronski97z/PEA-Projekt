#include <iostream>
#include "Graph.h"
#include "GeneticAlgorithm.h"
#include <vector>
#include <time.h>
#include <string>

int main(int argc, char*argv[])
{
    std::string file=argv[1];
    srand(time(NULL));
    Graph graph;
    graph.readGraph(file);
    GeneticAlgorithm alg(&graph,60,2000,0.8,0.01);
    std::cout<<"Rozwiązanie: "<<alg.apply()<<std::endl;

    return 0;
}
