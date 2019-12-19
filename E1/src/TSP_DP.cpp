#include "pch.h"
#include "TSP_DP.h"

void TSP_DP::apply()
{
	for (int i = 0; i < count; i++)
	{
		memory[(1 << i) | 1][i] = matrix[0][i];
		getMemory[(1 << i) | 1][i] = 0;
	}

	for (int bitMask = 0; bitMask < 1 << count; bitMask++)
	{
		for (int v = 0; v < count; v++)
		{
			if (!(bitMask & (1 << v)))
				continue;

			for (int j = 0; j < count; j++)
			{
				if (!(bitMask & (1 << j)))
				{
					if (memory[bitMask][v] + matrix[v][j] < memory[bitMask | (1 << j)][j])
					{
						getMemory[bitMask | (1 << j)][j] = v;
						memory[bitMask | (1 << j)][j] = memory[bitMask][v] + matrix[v][j];
					}
				}
			}
		}
	}

	result = INF;
	temp = 0;

	for (int i = 0; i < count; i++)
	{
		temp = memory[(1 << count) - 1][i] + matrix[i][0];
		if (temp < result)
		{
			result = temp;
			lastVertex = i;
		}
	}
}

string TSP_DP::toString()
{
	string message = "";
	int min = 1 << 30;
	int bitMask = (1 << count) - 1;
	int prev;
	MyStack path;
	path.push(lastVertex);

	for (int i = count - 2; i > 0; i--)
	{
		prev = getMemory[bitMask][lastVertex];
		path.push(prev);
		bitMask = bitMask ^ (1 << lastVertex);
		lastVertex = prev;
	}

	message = "Droga: 0 " + path.toString() + "0\n" + "Koszt: " + to_string(result);

	return message;
}

int TSP_DP::getResult()
{
	return result;
}

TSP_DP::TSP_DP(Graph graph)
{
	matrix = graph.getMatrix();
	count = graph.getCount();
	memory = new int*[1 << count];
	getMemory = new int*[1 << count];
	temp, result, lastVertex = 0;

	for (int i = 0; i < (1 << count); i++)
	{
		memory[i] = new int[count];
		getMemory[i] = new int[count];
	}

	for (int i = 0; i < (1 << count); i++) 
	{
		for (int j = 0; j < count; j++)
		{
			memory[i][j] = INF;
			getMemory[i][j] = INF;
		}
	}
}

TSP_DP::~TSP_DP()
{
	for (int i = 0; i < (1 << count); i++) 
	{
		delete[] memory[i];
		delete[] getMemory[i];
	}
	delete[] memory;
	delete[] getMemory;
}

