#include "pch.h"
#include "Menu.h"
#include <iostream>
#include <Windows.h>
#include "TabuSearch.h"
#include "SimulatedAnnealing.h"

void Menu::enable()
{
	int select = 0;

	while (true)
	{
		std::cout << "Czas : " << time << " s\n";
		std::cout << "Wspolczynnik dT: " << temperatureFactor << "\n";
		std::cout << graph.getDescription();
		std::cout << menu;

		cin >> select;

		switch (select)
		{
		case 1:		
			do
			{
				std::cout << "Czas [s]> ";
				cin >> time;
			} while (!time);			
				break;
		
		case 2:
			do
			{
				std::cout << "Wspolczynnik dT> ";
				cin >> temperatureFactor;
			} while (temperatureFactor==0.0);
			break;
		
		case 3:			
				do
				{
					std::cout << "Nazwa pliku> ";
					cin >> file;
				} while (file == "");
				graph.readGraph(file);			
			
			break;

		case 4:
			if (!time)
			{
				std::cout << "Nie podano czasu wykonywania ";
				cin.get();
			}
			else
			{
				TabuSearch ts(graph, time);
				ts.apply();
				cin.get();
			}
			break;

		case 5:
			if (!time||!temperatureFactor)
			{
				std::cout << "Nie podano czasu lub wspó³czynnika dT ";
				cin.get();
			}
			else
			{
				SimualtedAnnealing sa(graph, time, temperatureFactor);
				sa.apply();
				cin.get();
			}
			break;

		case 6:
			return;
		}

		cin.ignore();
		system("cls");
	}



}

Menu::Menu()
{
	menu.append("------------------------------\n");
	menu.append("1. Wprowadz czas\n");
	menu.append("2. Wprowadz wspolczynnik dT\n");
	menu.append("3. Wczytaj graf\n");
	menu.append("4. Tabu Search\n");
	menu.append("5. Simulated Annealing\n");
	menu.append("6. Koniec programu\n");
	menu.append("------------------------------\n");
	menu.append("> ");

}


Menu::~Menu()
{
}
