#include <iostream>
#include <vector>
#include <Windows.h>
#include "DataBase.h"

void Show(SudokuBlock** s)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j+=3)
		{
			std::cout << s[i][j].front << s[i][j + 1].front << s[i][j + 2].front << " ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j += 3)
		{
			std::cout << s[i][j].back << s[i][j + 1].back << s[i][j + 2].back << " ";
		}

		std::cout << std::endl;
	}

}

int main()
{
	//std::vector<sf::Event> events;
	//DataBase dt(path);
	//SudokuField sf(dt.GetField(int NumberOfField));
	//Game game;
	//while(game.window.isOpen())
	//{
		//game.Draw(sf);
		//game.GetInput();
		//game.DealWithInput();
	//}
	std::string file = "fields.txt";
	DataBase dt(file);
	Show(dt.GetField(0));
	std::cout << std::endl << std::endl;
	Show(dt.GetField(1));

}