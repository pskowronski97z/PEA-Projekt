#pragma once
#include <string>
#include "Graph.h"

class Menu
{
private:

	std::string menu="";
	std::string file = "";
	Graph graph;
	int time=0;
	double temperatureFactor=0;

public:

	void enable();
	Menu();
	~Menu();
};

