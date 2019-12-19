#pragma once
#include <string>
#define INF 9999

using namespace std;

class Graph
{
private:

	int **matrix = nullptr;
	int vert_count = 0;

public:

	string toString();
	bool infDiag();
	bool readGraph(string file);
	int getCount();
	int** getMatrix();
	void generateRandom(int size);
	Graph();
	~Graph();
};

