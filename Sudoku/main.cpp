#include <SFML/Graphics.hpp>
#include <Windows.h>

#include "Game.h"
#include "DataBase.h"

#if DEBUG
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

#endif
int main()
{	
	//LevelMenu lm;
	//int fieldNumber = lm.ChooseLevel();
	Game game("map.png");
	DataBase dt("fields.txt");
	SudokuField sf(dt.GetField(1));

	while (game.isOpen())
	{
		game.DealWinthInput(sf);
		game.Draw(sf);
		
	}
	return 0;
}