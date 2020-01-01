//
// Created by pskowronski on 31.12.2019.
//

#include "Graph.h"
#include <fstream>
#include <string>
#include <iostream>

std::string Graph::getDescription()
{
    if (!vert_count)
    {
        return "Brak danych\n";
    }
    else
    {
        return description;
    }
}

std::string Graph::toString()
{
    std::string graph = "";
    graph.append(description);

    if (vert_count)
    {
        for (int r = 0; r < vert_count; r++)
        {
            for (int c = 0; c < vert_count; c++)
            {
                if ((matrix[r][c] < 10) && (matrix[r][c] >= 0))
                    graph += std::to_string(matrix[r][c]) + "    ";

                else if (((matrix[r][c] < 100) && (matrix[r][c] > 9)) || (matrix[r][c] < 0))
                    graph += std::to_string(matrix[r][c]) + "   ";
                else if (matrix[r][c] == 100000000)
                    graph += "N    ";
                else
                    graph += std::to_string(matrix[r][c]) + "  ";
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

bool Graph::readGraph(std::string file)
{

    int **temp;
    description = "";
    std::string tempDesc="";

    std::ifstream fin;
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

    getline(fin,tempDesc);

    description.append(tempDesc + "\n");

    getline(fin, tempDesc);

    description.append(tempDesc + "\n");

    getline(fin, tempDesc);

    description.append(tempDesc + "\n");

    fin >> tempDesc;

    description.append(tempDesc);

    fin >> vert_count;



    description.append(std::to_string(vert_count) + "\n");



    getline(fin, tempDesc);
    getline(fin, tempDesc);
    getline(fin, tempDesc);
    getline(fin, tempDesc);

    temp = new int *[vert_count];

    for (int i = 0; i < vert_count; i++)
    {
        temp[i] = new int[vert_count];
    }

    for (int c = 0; c < vert_count; c++)
    {
        for (int r = 0; r < vert_count; r++)
        {
            fin>>temp[r][c];
        }
    }

    fin.close();

    matrix = temp;
    return true;
}

bool Graph::readGraphSmall(std::string file)
{

    int **temp;

    std::ifstream fin;
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
            fin >> temp[r][c];
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
