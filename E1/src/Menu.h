#pragma once
#include <string>
#include "Graph.h"
#include "TSP_BF.h"
#include "TSP_BB.h"
#include "TSP_DP.h"
#include <iostream>

using namespace std;

class Menu
{
	string options;
	string preview;
	


public:
	void enable();
	Menu();
	~Menu();
};

