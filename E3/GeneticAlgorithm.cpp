//
// Created by pskowronski on 31.12.2019.
//

#include "GeneticAlgorithm.h"
#include <iostream>

GeneticAlgorithm::GeneticAlgorithm(Graph *graph, int stop, int population, float crossRate, float mutationRate) {
    matrix = graph->getMatrix();
    size = graph->getCount();
    this->stop = stop;
    this->population = population;
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

    desc1.resize(size);
    desc2.resize(size);

    std::vector<int>::iterator itr1;
    std::vector<int>::iterator itr2;

    int begin;
    int end;

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
