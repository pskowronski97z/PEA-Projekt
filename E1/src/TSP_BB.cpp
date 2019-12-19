#include "pch.h"
#include "TSP_BB.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool operator > (const Node &arg1, const Node &arg2)
{
	if (arg1.l_bound > arg2.l_bound)
		return true;
	else
		return false;
}

bool operator < (const Node &arg1, const Node &arg2)
{
	if (arg1.l_bound < arg2.l_bound)
		return true;
	else
		return false;
}

bool operator == (const Node &arg1, const Node &arg2)
{
	if (arg1.l_bound == arg2.l_bound)
		return true;
	else
		return false;
}

string TSP_BB::toString()
{
	string result = "";

	result = "Droga: " + path.toString() + "0"+ "\n" + "Koszt: " + to_string(u_bound);

	return result;
}

int TSP_BB::lower_bound(Node arg,int next)
{
	int result = arg.l_bound;
	result -= outgoing_edges[arg.vertex];
	result += matrix[arg.vertex][next];
	
	return result;
}

void TSP_BB::apply()
{
	Node start;
	start.vertex = 0;
	start.l_bound = n0_lb;
	
	recursion(start);
}

void TSP_BB::recursion(Node node)
{
	helper_path.push(node.vertex);
	visited[node.vertex] = true;
	Node temp;
	priority_queue <Node, std::vector<Node>, std::greater<Node>> bounds;
	
	for (int i = 0; i < count; i++)
	{
		if (!visited[i])
		{
			temp.vertex = i;
			temp.l_bound = lower_bound(node, i);			
			bounds.push(temp);
		}
	}

	if (bounds.empty())
	{
		if (lower_bound(node, 0) < u_bound)
		{
			u_bound = lower_bound(node, 0);
			helper_path.copy(&path);
		}		
	}
	else
	{
		while (!bounds.empty())
		{
			temp = bounds.top();
			bounds.pop();

			if (temp.l_bound < u_bound)
			{			
				recursion(temp);				
			}
			else
				break;		
		}		
	}
	helper_path.pop();
	visited[node.vertex] = false;	
}

TSP_BB::TSP_BB(Graph graph)
{
	count = graph.getCount();
	matrix = graph.getMatrix();
	u_bound = INF;
	temp_cost = 0;
	outgoing_edges = new int[count];
	visited = new bool[count];
	n0_lb = 0;
	int min = INF;
	
	for (int r = 0; r < count; r++)
	{
		for (int c = 0; c < count; c++)
		{
			if (matrix[r][c] < min)
				min = matrix[r][c];
		}
		outgoing_edges[r] = min;
		n0_lb += min;
		min = INF;
	}

	for (int r = 0; r < count; r++)
	{
		visited[r] = false;
	}
}

TSP_BB::~TSP_BB()
{
	
}
