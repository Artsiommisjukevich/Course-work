#include "BorderCell.h"

BorderCell::BorderCell(int x, int y)
	:Cell(x, y) //Setting up the cell's coordinates
{
	SetSymbol("#", 2); //Same as SetSymbol("##"); This is what a border cell should look like
}