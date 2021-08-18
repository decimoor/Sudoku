#pragma once
#include <fstream>
#include "Sudoku.h"
const int LINE_SIZE = 36;
const int FIELD_SIZE = 324;

class DataBase
{
	private:
		std::ifstream file;
	public:
		DataBase(std::string& path)
		{
			
			file.open(path);
		}

		//the first field has index 0
		SudokuBlock** GetField(int NumberOfField)
		{
			SudokuBlock** field = new SudokuBlock*[9];
			for (int i = 0; i < 9; i++)
			{
				field[i] = new SudokuBlock[9];
			}
			//we add 10 because every line has '\n' symbol and we divide every field by '\n' symbol 
			file.seekg((FIELD_SIZE + 10) * NumberOfField * 2, std::ios::beg);
			
			//loading front part of field
			for (int i = 0; i < FIELD_WIDTH_HEIGHT; i++)
			{
				for (int j = 0; j < FIELD_WIDTH_HEIGHT; j++)
				{
					file >> field[i][j].front;
				}
			}

			//loading back part of field
			for (int i = 0; i < FIELD_WIDTH_HEIGHT; i++)
			{
				for (int j = 0; j < FIELD_WIDTH_HEIGHT; j++)
				{
					file >> field[i][j].back;
				}
			}

			return field;
		}

};