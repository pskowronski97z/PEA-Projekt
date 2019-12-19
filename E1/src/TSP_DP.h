#pragma once
#include "Graph.h"
#include "MyStack.h"
#define INF 9999

class TSP_DP
{
private:
	int **matrix;
	int count;
	int result;
	int temp;
	int **memory;
	int **getMemory;
	int lastVertex;
	
public:
	void apply();
	string toString();
	int getResult();
	TSP_DP(Graph graph);
	~TSP_DP();
};

