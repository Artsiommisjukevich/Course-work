#pragma once

#include <string>
#include <vector>
#include <iostream>

class Screen
{
private:
	std::vector<std::vector<std::string>> all_cell_symbols; //Buffer for drawing
	
public:
	std::vector<std::vector<std::string>>* GetAllCellSymbols();

	void DrawAll(); //Draw all from the buffer
	void Clear(); //Clear the buffer
};