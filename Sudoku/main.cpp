#include <iostream>
#include <vector>
#include <Windows.h>

unsigned int** SudokuMap = new unsigned int*[9];

void CreateMap(unsigned int** map);
std::vector<unsigned int> GetImpNum(unsigned int** map, int i1, int j1);
std::vector<unsigned int> GetPosNumbers(std::vector<unsigned int> ImpNum);
void DrawMap(unsigned int** map);

int main()
{
	//filling map with 0s
	for (int i = 0; i < 9; i++)
	{
		SudokuMap[i] = new unsigned int[9]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	}
	CreateMap(SudokuMap);
	//DrawMap(SudokuMap);
}


void CreateMap(unsigned int** map)
{
	std::vector <unsigned int> ImpNum;
	std::vector<unsigned int> PosNum;
	/*for (int CurSquire = 0; CurSquire < 9; CurSquire++)
	{
		for (int CurBlock = 0; CurBlock < 9; CurBlock++)
		{
			int i = CurBlock / 3 + 3 * (CurSquire / 3), j = CurBlock % 3 + 3 * (CurSquire % 3);
			ImpNum = GetImpNum(map, i, j);
			PosNum = GetPosNumbers(ImpNum);
			time_t t;
			srand((unsigned)time(&t));
			if (PosNum.size() == 0)
			{
				map[i][j] = 0;
			}
			else 
			{
				map[i][j] = PosNum[rand()%PosNum.size()];
			}
			system("cls");
			DrawMap(map);
			ImpNum.clear();
			PosNum.clear();
			Sleep(1000);

			
		}
	}*/
	int move = 0;
	for (int k = 0; k < 3; k++)
	{
		for (int i = k; i < 9; i += 3)
		{
			for (int k1 = 0; k1 < 3; k1++)
			{
				for (int j = k1; j < 9; j += 3)
				{
					ImpNum = GetImpNum(map, i, j);
					PosNum = GetPosNumbers(ImpNum);
					time_t t;
					srand((unsigned)time(&t));
					if (PosNum.size() == 0)
					{
						map[i][j] = 0;
					}
					else
					{
						map[i][j] = PosNum[rand() % PosNum.size()];
					}
					system("cls");
					DrawMap(map);
					std::cout << std::endl << move++ << std::endl;
					ImpNum.clear();
					PosNum.clear();
					Sleep(500);
				}
			}
		}
	}
}

std::vector<unsigned int> GetImpNum(unsigned int** map, int i1, int j1)
{
	std::vector<unsigned int> ImpNum;
	//checking CurSquire
	for (int i = (i1 / 3) * 3; i < (i1 / 3) * 3 + 3; i++)
	{
		for (int j = (j1 / 3) * 3; j < (j1 / 3) * 3 + 3; j++)
		{
			if (map[i][j] != 0)
				ImpNum.push_back(map[i][j]);
		}
	}
	//checking horizontal line
	for (int j = 0; j < 9; j++)
	{
		if (map[i1][j] != 0)
			ImpNum.push_back(map[i1][j]);
	}
	//checking vertical line
	for (int i = 0; i < 9; i++)
	{
		if (map[i][j1] != 0)
			ImpNum.push_back(map[i][j1]);
	}

	return ImpNum;
}

std::vector<unsigned int> GetPosNumbers(std::vector<unsigned int> ImpNum)
{
	std::vector<unsigned int> PosNum = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (unsigned int i : ImpNum)
	{
		for (unsigned int j = 0; j < PosNum.size(); j++)
		{
			if (PosNum[j] == i)
			{
				PosNum.erase(PosNum.begin() + j);
			}
		}
	}

	return PosNum;
}

void DrawMap(unsigned int** map)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << map[i][j] << map[i][j + 1] << map[i][j + 2] << "   ";
		}
		std::cout << std::endl;
		if (i % 3 == 2)
			std::cout << std::endl;
	}
}