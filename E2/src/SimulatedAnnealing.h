#pragma once
#include <vector>
#include "Graph.h"

class SimualtedAnnealing
{
	std::vector<int> solution;
	double temperatureBuffer = 0;
	double coolingRate = 0;
	double timeBound = 0;
	int **matrix;
	int size;

public:

	void apply();
	vector<int> random_permutation(int size);
	double calculateTemperature();
	int calculatePath(vector <int> path);
	double getProbability(int diff, double temperature);
	SimualtedAnnealing(Graph graph, int time, double rate);
	~SimualtedAnnealing();
};

