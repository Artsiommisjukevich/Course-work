#pragma once
#include <vector>

#include "Shape2D.h"
#include "Cell.h"
#include "Screen.h"

class Board : public Shape2D
{
private:
	int sizeX, sizeY; //Number of empty cells, where a target can be placed
	std::vector<Cell*> cells;

	Cell* GetCellByCoordinates(int x, int y);

	void Build(); //Assign correct types to all the cells of the board

public:
	Board(int sizeX, int sizeY);

	int GetSizeX() const { return sizeX; }
	int GetSizeY() const { return sizeY; }

	void Draw(Screen* screen) override;

	Board& operator*=(float factor); //To increase the area of the board
};