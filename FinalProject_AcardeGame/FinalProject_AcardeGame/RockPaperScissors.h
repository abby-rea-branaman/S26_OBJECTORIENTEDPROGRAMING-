#ifndef ROCKPAPERSCISSORS_H
#define ROCKPAPERSCISSORS_H

#include <string>
#include "Game.h"
using namespace std;

// Created a class that inherits from the Game class
class RockPaperScissors : public Game {

private: 
	int playerScore;
	int computerScore;

	string getComputerChoice();
	void determineWinner(const string& playerChoice, const string& computerChoice);

public:
	RockPaperScissors();
	void play() override;
	void reset() override;
};

#endif
