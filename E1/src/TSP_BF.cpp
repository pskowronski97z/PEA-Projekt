#include "pch.h"
#include "TSP_BF.h"
#include <iostream>

using namespace std;

bool TSP_BF::recursion(int node)
{
	helper_path.push(node);

	if (helper_path.getSize() != count)
	{
		visited[node] = true;

		for (int u = 0; u < count; u++)
		{		
			if (visited[u])
				continue;

			helper_weight_sum += matrix[node][u];

			recursion(u);

			helper_weight_sum -= matrix[node][u];
		}

		visited[node] = false;
		helper_path.pop();
	}
	else if (matrix[node][0] <= 0)
	{
		helper_path.pop();
	}
	else
	{
		helper_weight_sum += matrix[node][0];

		if (helper_weight_sum >= weight_sum)
		{
			helper_weight_sum -= matrix[node][0];			
		}
		else
		{
			weight_sum = helper_weight_sum;
			helper_path.copy(&path);
			helper_weight_sum -= matrix[node][0];
		}

		helper_path.pop();
	}

	if (path.getSize())
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

void TSP_BF::apply()
{
	recursion(0);
}

string TSP_BF::toString()
{
	string result="";

	result = "Droga: " + path.toString() + "0\n" + "Koszt: " + to_string(weight_sum);
	
	return result;
}

TSP_BF::TSP_BF(Graph graph)
{

	count = graph.getCount();
	matrix = graph.getMatrix();
	visited = new bool[count];
	weight_sum = INF;
	helper_weight_sum = 0;

	for (int i = 0; i < count; i++)
	{
		visited[i] = false;
	}
}

TSP_BF::~TSP_BF()
{

}
