#pragma once
#include "Printable.h"
#include <iostream>

class Score : public Printable
{
private:
	unsigned int value;

public:
	Score();

	unsigned int GetValue() const { return value; }
	Score& operator+=(unsigned int value); //To increase the score

	void Print(const Target& target) const override;
};