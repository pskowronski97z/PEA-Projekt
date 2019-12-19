#include "pch.h"
#include "SimulatedAnnealing.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <iostream>
#include <ctime>

void SimualtedAnnealing::apply()
{
	vector<int> best;
	vector<int> permutation = random_permutation(size);
	vector<int> next(permutation);
	std::clock_t start;
	int firstToSwap;
	int secondToSwap;
	double temperature = temperatureBuffer;
	int result = 1 << 30;
	double time = 0;
	double foundTime = 0;
	start = std::clock();

	while(true)
	{
		while (temperature >= 0.1)
		{
			int steps =  3*size;

			next = permutation;
	
			int nextCost = calculatePath(next);


			for (int i = steps; i > 0; i--)
			{				
				do
				{
					firstToSwap = rand() % size;
					secondToSwap = rand() % size;
				} while (firstToSwap == secondToSwap);

				std::swap(next[firstToSwap],next[secondToSwap]);
				
				nextCost = calculatePath(next);

				int difference = result - nextCost;

				if (difference > 0)
				{
					result = nextCost;
					best = next;
					foundTime = (std::clock() - start) / (double)CLOCKS_PER_SEC;
				}

				if (difference > 0 || (difference < 0 && getProbability(difference,temperature) > ((double)rand() / RAND_MAX) + 1))
				{
					permutation = next;
					break;
				}
				else
				{
					std::swap(next[firstToSwap], next[secondToSwap]);
				}

				time = (std::clock() - start) / (double)CLOCKS_PER_SEC;

				if (time >= timeBound)
				{
					cout << "Droga: ";
					for (int d = 0; d < size; d++)
					{
						cout << best[d] << " ";
					}

					cout << "\nKoszt: " << result << endl;
					cout << "Znaleziono po: " << foundTime << " s " << endl;
					cout << "Temperatura koncowa: "<< temperature << endl;
					cout << endl;
					return;
				}
			}
			temperature *= coolingRate;			
		}

		temperature = temperatureBuffer;
		permutation = random_permutation(size);

	}

}


vector<int> SimualtedAnnealing::random_permutation(int _size)
{
	std::vector<int> temp;
	temp.reserve(_size);

	for (int i = 0; i < _size; i++)
	{
		temp.push_back(i);
	}
	
	random_shuffle(temp.begin(), temp.end());
	
	return temp;
}

double SimualtedAnnealing::calculateTemperature()
{
	vector<int> origin; 

	int firstToSwap;
	int secondToSwap;
	int originCost = 0;
	int neighbourCost = 0;
	int delta = 0;
	int buffer = 0;

	for (int i = 0; i < 10000; i++)
	{
		do
		{
			firstToSwap = rand() % size;
			secondToSwap = rand() % size;
		} while (firstToSwap == secondToSwap);

		origin = random_permutation(size);
		vector<int> neighbour(origin);

		std::swap(neighbour[firstToSwap], neighbour[secondToSwap]);

		delta = fabs(calculatePath(origin) - calculatePath(neighbour));
		buffer += delta;
		
	}
	
	buffer /= 10000;

	return (-1*buffer)/log(0.99);
}

int SimualtedAnnealing::calculatePath(vector<int> path)
{
	int cost = 0;

	for (int i = 0; i < path.size() - 1; ++i)
	{
		cost += matrix[path[i]][path[i + 1]];
	}
	cost += matrix[path[size - 1]][path[0]];

	return cost;
}

double SimualtedAnnealing::getProbability(int diff, double temperature)
{
	
	return exp(diff / temperature);
}

SimualtedAnnealing::SimualtedAnnealing(Graph graph, int time, double rate)
{
	matrix = graph.getMatrix();
	size = graph.getCount();
	timeBound = time;
	coolingRate = rate;
	temperatureBuffer = calculateTemperature();
}


SimualtedAnnealing::~SimualtedAnnealing()
{
}
