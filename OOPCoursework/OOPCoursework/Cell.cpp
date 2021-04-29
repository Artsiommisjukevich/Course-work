#include "Cell.h"

Cell::Cell()
	: Shape2D(1, 1)
{

}

Cell::Cell(int x, int y)
	: Shape2D(1, 1), x(x), y(y)
{
	symbol = "  ";
}

Cell::Cell(int x, int y, const std::string& symbol)
	: Shape2D(1, 1), x(x), y(y), symbol(symbol)
{

}
Cell::Cell(int x, int y, char symbol)
	: Shape2D(1, 1), x(x), y(y)
{
	this->symbol = std::to_string(symbol);
}

void Cell::SetSymbol(const std::string& new_symbol)
{
	symbol = new_symbol;
}

void Cell::SetSymbol(char new_symbol)
{
	symbol = std::to_string(new_symbol);
}

void Cell::SetSymbol(const std::string& new_symbol, unsigned int number_of_repetitions)
{
	symbol = "";

	for (int i = 0; i < number_of_repetitions; ++i)
	{
		symbol += new_symbol;
	}
}

std::string Cell::GetSymbol() const
{
	return symbol;
}

void Cell::SetX(int x)
{
	this->x = x;
}

void Cell::SetY(int y)
{
	this->y = y;
}

int Cell::GetX() const
{
	return x;
}

int Cell::GetY() const
{
	return y;
}

void Cell::Draw(Screen* screen)
{
	std::vector<std::vector<std::string>>* all_cell_symbols = screen->GetAllCellSymbols();
	(*all_cell_symbols)[y + 1][x + 1] = symbol + " ";
}