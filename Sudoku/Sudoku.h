#pragma once
#include <string>
const int FIELD_WIDTH_HEIGHT = 9;

struct SudokuBlock
{
	char front = '0';
	char back = '0';
};

class SudokuField
{
	private:
		SudokuBlock field[FIELD_WIDTH_HEIGHT][FIELD_WIDTH_HEIGHT];

	public:
		SudokuField(SudokuBlock** f)
		{
			for (int i = 0; i < FIELD_WIDTH_HEIGHT; i++)
			{
				for (int j = 0; j < FIELD_WIDTH_HEIGHT; j++)
				{
					field[i][j] = f[i][j];
				}
			}
		}

		void SetField(SudokuBlock f[FIELD_WIDTH_HEIGHT][FIELD_WIDTH_HEIGHT])
		{
			for (int i = 0; i < FIELD_WIDTH_HEIGHT; i++)
			{
				for (int j = 0; j < FIELD_WIDTH_HEIGHT; j++)
				{
					field[i][j] = f[i][j];
				}
			}
		}
		
		bool PutNumber(int number, int i, int j)
		{
			if (number > 9)
				return false;
			if (number < 0)
				return false;
			field[i][j].front = number + 48;
			if (field[i][j].front == field[i][j].back)
			{
				field[i][j].front = field[i][j].back;
				return true;
			}
			UnputNumber(i, j);
			
			return false;
		}

		void UnputNumber(int i, int j)
		{
			field[i][j].front = '0';
		}

		bool Win()
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (field[i][j].front == '0')
						return false;
				}
			}

			return true;
		}

		friend class Game;
		
};


