#include "pch.h"
#include "Graph.h"
#include <fstream>
#include <time.h>

string Graph::toString()
{
	string graph = "";

	
	if (vert_count)
	{
		for (int r = 0; r < vert_count; r++)
		{
			for (int c = 0; c < vert_count; c++)
			{
				if ((matrix[r][c] < 10)&&(matrix[r][c] >=0))
					graph += to_string(matrix[r][c]) + "    ";

				else if(((matrix[r][c]<100)&&(matrix[r][c] >9))||(matrix[r][c] < 0))
					graph += to_string(matrix[r][c]) + "   ";

				else
					graph += to_string(matrix[r][c]) + "  ";
			}
			graph += "\n";
		}
	}
	else
	{
		graph = "Graf pusty\n";
	}
	return graph;
}

bool Graph::infDiag()
{
	if(!vert_count)
		return false;
	else
	{
		for (int i = 0; i < vert_count; i++)
		{
			matrix[i][i] = INF;
		}
		return true;
	}
}

bool Graph::readGraph(string file)
{
	
	int **temp;

	ifstream fin;
	fin.open(file);

	if (fin.fail() || fin.eof())
	{
		return false;
	}

	if (vert_count)
	{
		for (int i = 0; i < vert_count; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;
	}

	fin >> vert_count;

	temp = new int *[vert_count];

	for (int i = 0; i < vert_count; i++)
	{
		temp[i] = new int[vert_count];
	}

	for (int r = 0; r < vert_count; r++)
	{
		for (int c = 0; c < vert_count; c++)
		{
			fin>>temp[r][c];
		}
	}

	fin.close();

	matrix = temp;
	return true;
}

int Graph::getCount()
{
	return vert_count;
}

Graph::Graph()
{
	
}

Graph::~Graph()
{
	
}

int** Graph::getMatrix()
{
	return matrix;
}

void Graph::generateRandom(int size)
{
	vert_count = size;
	int **buffer = nullptr;
	buffer = new int*[vert_count];

	srand(time(NULL));

	for (int i = 0; i < vert_count; i++)
	{
		buffer[i] = new int[vert_count];

		for (int j = 0; j < vert_count; j++)
		{
			buffer[i][j] = rand() % 100 + 1;
		}
	}

	matrix = buffer;

	infDiag();
}
