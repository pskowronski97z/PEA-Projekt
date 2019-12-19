#pragma once
#include "Graph.h"
#include "MyStack.h"
#define INF 9999

struct Node
{
	int l_bound;
	int vertex;
};

class TSP_BB
{
private:
	int **matrix;
	int count;
	int u_bound;
	int temp_cost;
	bool *visited;
	int *outgoing_edges;
	int n0_lb;
	MyStack path;
	MyStack helper_path;
	
public:
	string toString();
	int lower_bound(Node arg,int next);
	void apply();
	void recursion(Node node);
	TSP_BB(Graph graph);
	~TSP_BB();


};

