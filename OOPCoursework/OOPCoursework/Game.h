#pragma once
#include "Board.h"
#include "Cell.h"
#include "Screen.h"
#include "Score.h"
#include "TargetInfo.h"

class Game
{
private:
	std::vector<Cell*> screen_cells; //All cells in the "buffer" that can be drawn
	Screen* screen;
	Board* board;
	Score score;
	TargetInfo targetInfo;
	unsigned int separator = 100; //For the board to seem to be on the same place all the time
	float difficulty_increasing_factor = 1.5f; //The value, which the board is multiplied by after the difficulty is increased

public:
	Game();
	~Game();

	void Play();
};