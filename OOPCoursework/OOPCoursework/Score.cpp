#include "Score.h"

Score::Score()
	:Printable("Score"), value(0)
{

}

Score& Score::operator+=(unsigned int value)
{
	this->value += value;
	return *this;
}

void Score::Print(const Target& target) const
{
	std::cout << name << ": " << value;
}