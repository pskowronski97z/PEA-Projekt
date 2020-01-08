#include <iostream>
#include "Graph.h"
#include "GeneticAlgorithm.h"
#include <ctime>
#include <string>
#include <cstdlib>
#include <cstring>

int main(int argc, char*argv[])
{
    if(!(argc-2)&&(!(argv[1][0]-'h')||!(argv[1][0]-'H')))
    {
        std::cout<< "Nazwa pliku   Czas[s]   Populacja   Wsp. krzyżowania   Wsp.mutacji   Typ krzyżowania" <<std::endl;
        return 0;
    }

    std::string file=argv[1];
    int seconds = std::stoi(argv[2]);
    int population = std::stoi(argv[3]);
    float crosses = std :: stof(argv[4]);
    float mutations = std:: stof(argv[5]);

    srand(time(NULL));
    Graph graph;
    graph.readGraph(file);
    GeneticAlgorithm alg(&graph,seconds,population,crosses,mutations);

    if(strncmp(argv[6],"OX",2) == 0)
        std::cout<<"Rozwiązanie: "<<alg.apply(true)<<std::endl;
    else if(strncmp(argv[6],"PMX",3) == 0)
        std::cout<<"Rozwiązanie: "<<alg.apply(false)<<std::endl;
    else
        std::cout<<"Brak określonego krzyżowania"<<std::endl;

    return 0;
}
