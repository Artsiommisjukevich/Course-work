#include "Shape2D.h"

Shape2D::Shape2D(unsigned int lengthX, unsigned int lengthY)
	:lengthX(lengthX), lengthY(lengthY)
{

}

unsigned int Shape2D::GetLengthX()
{
	return lengthX;
}

unsigned int Shape2D::GetLengthY()
{
	return lengthY;
}