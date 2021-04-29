#include "EmptyCell.h"

EmptyCell::EmptyCell(int x, int y)
	:Cell(x, y) //Setting up the cell's coordinates
{
	SetSymbol("-", 2); //Same as SetSymbol("--"); This is what an empty cell should look like
}