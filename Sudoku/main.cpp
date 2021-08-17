#include <iostream>
#include <vector>

unsigned int SudokuMap[9][9] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0},
};

unsigned int** CreateMap(unsigned int** map)
{
	std::vector <unsigned int> ImpNum;
	for (int CurBlock = 1; CurBlock <= 9; CurBlock++)
	{
		for (int CurBlock = 0; CurBlock < 9; CurBlock++)
		{

		}
	}
}

std::vector<unsigned int> GetImpNum(unsigned int** map, int i1, int j1)
{
	std::vector<unsigned int> ImpNum;
	//checking CurBlock
	for (int i = (i1 / 3) * 3; i < (i1 / 3) * 3 + 3; i++)
	{
		for (int j = (j1 / 3) * 3; j < (j1 / 3) * 3 + 3; j++)
		{
			if (map[i][j] != 0)
				ImpNum.push_back(map[i][j]);
		}
	}
}

