#pragma once
#include "Graph.h"
#include "MyStack.h"

class TSP_BF
{
private:
	
	int **matrix;
	int count;
	int weight_sum;
	int helper_weight_sum;
	MyStack path;
	MyStack helper_path;
	bool *visited;

public:
	
	bool recursion(int node);
	void apply();
	string toString();
	TSP_BF(Graph graph);
	~TSP_BF();

};

