#include "Screen.h"

std::vector<std::vector<std::string>>* Screen::GetAllCellSymbols()
{
	return &all_cell_symbols;
}

void Screen::DrawAll()
{
	for (int i = 0; i < all_cell_symbols.size(); ++i)
	{
		for (int j = 0; j < all_cell_symbols[i].size(); ++j)
		{
			std::cout << all_cell_symbols[i][j];
		}
	}
}

void Screen::Clear()
{
	all_cell_symbols.clear();
}