#pragma once
#include <string>
#define INF 9999

using namespace std;

class Graph
{
private:

	int **matrix = nullptr;
	int vert_count = 0;
	string description = "";

public:

	string getDescription();
	string toString();
	bool infDiag();
	bool readGraph(string file);
	bool readGraphSmall(string file);
	int getCount();
	int** getMatrix();
	void generateRandom(int size);
	Graph();
	~Graph();
};

