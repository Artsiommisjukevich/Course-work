#include "Board.h"
#include <iostream>
#include <iomanip>

#include "cells/board/EmptyCell.h"
#include "cells/board/BorderCell.h"

void Board::Build()
{
	cells.clear();
	for (int i = -1; i <= sizeY + 1; ++i)
	{
		for (int j = -1; j <= sizeX + 1; ++j)
		{
			if (i == -1 && j == -1 || i == 0 && j == -1 || i == -1 && j == 0)
			{
				cells.push_back(new Cell(i, j));
				continue;
			}

			if (i == -1 && j == sizeX + 1)
			{
				cells.push_back(new Cell(i, j));
				continue;
			}

			if (j == -1 && i == sizeY + 1)
			{
				cells.push_back(new Cell(i, j));
				continue;
			}

			if (i == -1)
			{
				cells.push_back(new Cell(i, j, (j >= 10 ? std::to_string(j) : (" " + std::to_string(j)))));
				continue;
			}

			if (j == -1)
			{
				cells.push_back(new Cell(i, j, (i >= 10 ? std::to_string(i) : (" " + std::to_string(i)))));
				continue;
			}

			if (i == 0 || i == sizeY + 1)
			{
				cells.push_back(new BorderCell(i, j));
				continue;
			}

			if (j == 0 || j == sizeX + 1)
			{
				cells.push_back(new BorderCell(i, j));
				continue;
			}

			cells.push_back((new EmptyCell(i, j)));
		}
	}
}

Board::Board(int sizeX, int sizeY)
	:Shape2D(sizeX + 3, sizeY + 3), sizeX(sizeX), sizeY(sizeY)
{
	Build();
}

Cell* Board::GetCellByCoordinates(int x, int y)
{
	for (Cell* cell : cells)
	{
		if (cell->GetX() == x && cell->GetY() == y)
			return cell;
	}

	return nullptr;
}

void Board::Draw(Screen* screen)
{
	std::vector<std::vector<std::string>>* all_cell_symbols = screen->GetAllCellSymbols();

	for (int i = -1; i <= sizeY + 1; ++i)
	{
		all_cell_symbols->push_back(std::vector<std::string>());
		for (int j = -1; j <= sizeX + 1; ++j)
		{
			Cell* current_cell = GetCellByCoordinates(i, j);
			if (current_cell)
			{
				(*all_cell_symbols)[i + 1].push_back(current_cell->GetSymbol());
				(*all_cell_symbols)[i + 1][j + 1] += " ";
			}
		}

		(*all_cell_symbols)[i + 1].push_back("\n");
	}
}

Board& Board::operator*=(float factor)
{
	this->sizeX = (int)(this->sizeX * factor);
	this->sizeY = (int)(this->sizeY * factor);
	Build();
	return *this;
}