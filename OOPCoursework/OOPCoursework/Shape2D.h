#pragma once
#include "ToBeDrawnInterface.h"

class Shape2D : public ToBeDrawnInterface
{
protected:
	unsigned int lengthX, lengthY; //The number of cells in each direction

public:
	Shape2D(unsigned int lengthX, unsigned int lengthY);

	unsigned int GetLengthX();
	unsigned int GetLengthY();

	virtual void Draw(Screen* screen) override = 0; //Place the shape to the drawing buffer
};