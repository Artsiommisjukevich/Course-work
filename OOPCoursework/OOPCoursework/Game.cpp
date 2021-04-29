#include "Game.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cells/targets/Target20.h"
#include "cells/targets/Target30.h"
#include "cells/targets/Target50.h"
#include <exception>

Game::Game()
{
	screen = new Screen;
	board = new Board(10, 6); //Setting up the start size of the board
}

Game::~Game()
{
	delete board;
	delete screen;
}

void Game::Play()
{
	srand(time(NULL)); //Generating a random seed
	unsigned int difficulty = 1; //First difficulty
	while (true)
	{
		for (unsigned int i = 0; i < separator; ++i)  //Making a new page
		{											  //Making a new page
			std::cout << std::endl; 				  //Making a new page
		}											  //Making a new page
		screen->Clear();
		board->Draw(screen); //Placing the board to the drawing buffer

		int targetType = rand() % 3 + 1; //From 1 to 3
		//Generating coordinates of the target
		int cellX = rand() % board->GetSizeX() + 1; //From 1 to the appropriate size of the board
		int cellY = rand() % board->GetSizeY() + 1;	//From 1 to the appropriate size of the board
		
		Target* target = nullptr; //Creating a current target

		switch (targetType)
		{
		case 1: target = new Target20(); break;  //Checking what type of target should be generated
		case 2: target = new Target30(); break;	 //Checking what type of target should be generated
		case 3: target = new Target50(); break;	 //Checking what type of target should be generated
		}

		target->SetX(cellX); //Setting up the target's coordinates
		target->SetY(cellY); //Setting up the target's coordinates

		target->Draw(screen); //Placing the target to the drawing buffer

		screen->DrawAll(); //Draw everything, that has been placed in the buffer

		std::cout << std::endl << std::endl;
		
		score.Print(*target); //Show the player's score
		std::cout << std::endl;
		targetInfo.Print(*target); //Show the inforamation about the current target to the player
		std::cout << std::endl << std::endl;
		

		//Input data
		int inputX = 0, inputY = 0;

		std::string line;
		
		//Inputting data, if the data input was incorrect, we are skipping the current round
		try
		{
			std::cout << "x coordinate: ";
			std::getline(std::cin, line);
			inputX = std::stoi(line);
			std::cout << "y coordinate: ";
			std::getline(std::cin, line);
			inputY = std::stoi(line);
		}
		catch (std::exception ex)
		{
			inputX = 0;
			inputY = 0;
		}

		//Checking if the player's input was right, if yes - increasing the score by the appropriate value
		if (target->GetX() == inputX && target->GetY() == inputY)
			score += target->GetValue();

		//Increasing difficulty
		if (score.GetValue() >= 200 && difficulty == 1)
		{
			*board *= difficulty_increasing_factor;
			++difficulty;
		}
		else if (score.GetValue() >= 500 && difficulty == 2)
		{
			*board *= difficulty_increasing_factor;
			++difficulty;
		}
		else if (score.GetValue() >= 1000 && difficulty == 3)
		{
			*board *= difficulty_increasing_factor;
			++difficulty;
		}
	}
}