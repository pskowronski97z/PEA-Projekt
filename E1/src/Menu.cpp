#include "pch.h"
#include "Menu.h"

void Menu::enable()
{
	Graph graph;
	
	while (true)
	{
		int select = 0;
		string pathName = "";
		bool check = false;
		
		cout << preview;
		cout << options;

		cin >> select;
		

		switch (select)
		{
		case 1:
		{					
			do
			{
				cout << "Plik> ";
				cin >> pathName;
				check = graph.readGraph(pathName);
				
				if (!check)
				{
					cout << "Blad odczytu\n";
				}

			} while (!check);

			
			preview = "Plik <" + pathName + ">\n\n";
			preview.append(graph.toString());
			graph.infDiag();
			
			break;
		}

		case 2:
		{
			if (!graph.getCount())
			{
				cout << "Brak danych\n";
				cin.ignore();
				cin.get();
			}
			else
			{
				TSP_BF bf(graph);
				bf.apply();
				cout << "------------Brute Force------------\n"+bf.toString();				
				cin.ignore();
				cin.get();
			}
			break;
		}

		case 3:
		{
			if (!graph.getCount())
			{
				cout << "Brak danych\n";
				cin.ignore();
				cin.get();
			}
			else
			{
				TSP_BB bb(graph);
				bb.apply();
				cout << "-----------Branch & Bound----------\n" + bb.toString();

				cin.ignore();
				cin.get();
			}
			break;
		}

		case 4:
		{
			if (!graph.getCount())
			{
				cout << "Brak danych\n";
				cin.ignore();
				cin.get();
			}
			else
			{
				TSP_DP dp(graph);
				dp.apply();
				cout << "---------Dynamic Programming-------\n" + dp.toString();

				cin.ignore();
				cin.get();
			}

			break;
		}

		case 5:
		{
			return;			
		}
		}				

		system("cls");
	}
}

Menu::Menu()
{
	preview = "";
	options = "";
	options.append("-----------------------------------\n");
	options.append("1. Wczytywanie grafu\n");
	options.append("2. Brute Force\n");
	options.append("3. Branch & Bound\n");
	options.append("4. Dynamic Programming\n");
	options.append("5. Koniec progamu\n");
	options.append("Wybor> ");
}


Menu::~Menu()
{
}
