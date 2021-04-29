#pragma once
#include "../Cell.h"

class Target : public Cell
{
protected:
	unsigned int value; //The value, which should be added to the score

public:
	Target(unsigned int value);

	unsigned int GetValue() const;
};