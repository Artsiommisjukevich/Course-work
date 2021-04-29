#pragma once
#include <string>
#include "Shape2D.h"
#include "Screen.h"

class Cell : public Shape2D
{
private:
	std::string symbol;
	int x, y; //Coordinates

public:
	Cell();
	Cell(int x, int y);
	Cell(int x, int y, const std::string& symbol);
	Cell(int x, int y, char symbol);

	//Different possibilities for setting the symbol
	void SetSymbol(const std::string& new_symbol);
	void SetSymbol(const std::string& new_symbol, unsigned int number_of_repetitions);
	void SetSymbol(char new_symbol);
	std::string GetSymbol() const;

	void SetX(int x);
	void SetY(int y);

	int GetX() const;
	int GetY() const;

	void Draw(Screen* screen) override;
};