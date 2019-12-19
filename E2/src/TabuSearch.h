#pragma once
#include "Graph.h"
#include <vector>


class TabuSearch
{

private:

	int **matrix = nullptr;
	int size = 0;
	int searchTime = 0;

	vector<int> randomPermutation(int _size);
	int calculatePath(vector <int> path);

public:

	void apply();
	TabuSearch(Graph graph,int time);
	~TabuSearch();
};

