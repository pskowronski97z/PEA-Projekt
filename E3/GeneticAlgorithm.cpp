//
// Created by pskowronski on 31.12.2019.
//

#include "GeneticAlgorithm.h"
#include <iostream>
#include <ctime>


GeneticAlgorithm::GeneticAlgorithm(Graph *graph, int stop, int population, float crossRate, float mutationRate) {

    matrix = graph->getMatrix();
    size = graph->getCount();
    this->stop = stop;
    populationSize = population;
    this->crossRate = crossRate;
    this->mutationRate = mutationRate;
}

int GeneticAlgorithm::calculatePath(std::vector<int> &path) {

    int result = 0;

    for (int i = 0; i < size - 1; i++) {
        result += matrix[path[i]][path[i + 1]];
    }

    result += matrix[path[size - 1]][path[0]];

    return result;
}

void GeneticAlgorithm::orderedCrossover(std::vector<int> &parent1, std::vector<int> &parent2) {

    std::vector<int> desc1;
    std::vector<int> desc2;
    std::vector<int>::iterator itr1;
    std::vector<int>::iterator itr2;
    int begin;
    int end;

    desc1.resize(size);
    desc2.resize(size);

    do {
        begin = rand() % size;
        end = rand() % size;
    } while (begin == end || begin == 0 || end == size - 1);

    if (end < begin) {
        std::swap(begin, end);
    }

    for (int i = begin; i <= end; i++) {
        desc1[i] = parent1[i];
        desc2[i] = parent2[i];
    }

    if (end == size - 1) {
        itr1 = desc1.begin();
        itr2 = parent2.begin();
    } else {
        itr1 = desc1.begin() + end + 1;
        itr2 = parent2.begin() + end + 1;
    }


    while (itr1 != desc1.begin() + begin) {
        if (!(isInPath(*itr2, begin, end, desc1))) {
            *itr1 = *itr2;

            if (itr1 == desc1.end() - 1) {
                itr1 = desc1.begin();
            } else {
                itr1++;
            }

            if (itr2 == parent2.end() - 1) {
                itr2 = parent2.begin();
            } else {
                itr2++;
            }

        } else {
            if (itr2 == parent2.end() - 1) {
                itr2 = parent2.begin();
            } else {
                itr2++;
            }
        }
    }


    if (end == size - 1) {
        itr1 = desc2.begin();
        itr2 = parent1.begin();
    } else {
        itr1 = desc2.begin() + end + 1;
        itr2 = parent1.begin() + end + 1;
    }


    while (itr1 != desc2.begin() + begin) {
        if (!(isInPath(*itr2, begin, end, desc2))) {
            *itr1 = *itr2;

            if (itr1 == desc2.end() - 1) {
                itr1 = desc2.begin();
            } else {
                itr1++;
            }

            if (itr2 == parent1.end() - 1) {
                itr2 = parent1.begin();
            } else {
                itr2++;
            }

        } else {
            if (itr2 == parent1.end() - 1) {
                itr2 = parent1.begin();
            } else {
                itr2++;
            }
        }
    }

    parent1.clear();
    parent2.clear();

    parent1 = desc1;
    parent2 = desc2;

}

bool GeneticAlgorithm::isInPath(int element, int begin, int end, std::vector<int> &path) {

    for (int i = begin; i <= end; i++) {
        if (element == path[i])
            return true;
    }

    return false;
}

void GeneticAlgorithm::apply() {

    std::vector<std::vector<int>> population;
    std::vector<std::vector<int>> nextGeneration;
    std::vector<int> fitness;
    std::vector<int> nextFitness;
    std::vector<int> permutation;
    int tournamentSize = 100;
    int index;
    int result;
    int p1;
    int p2;

    std::clock_t start;

    for (int i = 0; i < size; i++) {
        permutation.push_back(i);
    }

    for (int i = 0; i < populationSize; i++) {
        std::random_shuffle(permutation.begin(), permutation.end());
        population.push_back(permutation);
        fitness.push_back(calculatePath(permutation));
    }

    permutation.clear();

    start = std::clock();

    //Kolejne iteracje algorytmu
    while ((((std::clock() - start) / (double) CLOCKS_PER_SEC)) < stop) {

        // Tworzenie nowej populacji na drodze selekcji
        for (int j = 0; j < populationSize; j++) {

            result = INT32_MAX;

            // Wybór najlepszego osobnika z turnieju
            for (int k = 0; k < tournamentSize; k++) {

                index = rand() % populationSize;

                if (fitness[index] < result) {

                    result = fitness[index];
                    permutation.clear();
                    permutation = population[index];
                }
            }
            nextGeneration.push_back(permutation);
        }

        // Wymiana pokoleń
        for (auto &itr : population) {
            itr.clear();
        }
        population.clear();
        population = nextGeneration;

        for (auto &itr : nextGeneration) {
            itr.clear();
        }
        nextGeneration.clear();

        // Krzyżowanie osobników
        for (int j = 0; j < (int) crossRate * populationSize; j+=2) {
            do {
                p1 = rand() % populationSize;
                p2 = rand() % populationSize;
            } while (p1 == p2);

            orderedCrossover(population.at(j), population.at(j+1));
        }

        // Mutowanie
        for (int j = 0; j < (int) mutationRate * populationSize; j++) {
            do {
                p1 = rand() % size;
                p2 = rand() % size;
            } while (p1 == p2);

            std::swap(population.at(j)[p1], population.at(j)[p2]);
        }

        for(auto &itr : population)
        {
            nextFitness.push_back(calculatePath(itr));
        }

        fitness.clear();
        fitness = nextFitness;
        nextFitness.clear();

    }

    result = *(std::min_element(fitness.begin(),fitness.end()));

    std::cout << result;
}
