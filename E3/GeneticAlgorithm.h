//
// Created by pskowronski on 31.12.2019.
//

#ifndef E3_GENETICALGORITHM_H
#define E3_GENETICALGORITHM_H
#include "Graph.h"
#include <vector>

class GeneticAlgorithm
{
private:

    int stop;
    int population;
    float crossRate;
    float mutationRate;
    int **matrix;
    int size;

public:

    GeneticAlgorithm(Graph *graph, int stop, int population, float crossRate, float mutationRate);
    int calculatePath(std::vector<int> &path);
    void orderedCrossover(std::vector<int> &parent1, std::vector<int> &parent2);
    bool isInPath(int element, int begin, int end, std::vector<int> &path);
};


#endif //E3_GENETICALGORITHM_H
