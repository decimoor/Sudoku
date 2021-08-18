#pragma once
const int FIELD_WIDTH_HEIGHT = 9;

struct SudokuBlock
{
	int front = 0;
	int back = 0;
};

class SudokuField
{
	private:
		SudokuBlock field[FIELD_WIDTH_HEIGHT][FIELD_WIDTH_HEIGHT];

	public:
		SudokuField(SudokuBlock f[FIELD_WIDTH_HEIGHT][FIELD_WIDTH_HEIGHT])
		{
			for (int i = 0; i < FIELD_WIDTH_HEIGHT; i++)
			{
				for (int j = 0; j < FIELD_WIDTH_HEIGHT; j++)
				{
					field[i][j] = f[i][j];
				}
			}
		}
		
		bool PutNumber(int i, int j)
		{
			if (field[i][j].front == field[i][j].back)
			{
				field[i][j].front = field[i][j].back;
				return true;
			}
			
			return false;
		}

		void UnputNumber(int i, int j)
		{
			field[i][j].front = 0;
		}
		
};


