#pragma once
#ifndef GUESSNUMBER_H
#define GUESSNUMBER_H

#include "Game.h"

// Created a class that inherits from the Game class
class GuessTheNumber : public Game
{
	// Private members to store the number to guess, maximum attempts allowed, and attempts made	
	private:
		int numberToGuess;
		int maxAttempts;
		int attemptsMade;
		// Public members to initialize the game, play the game, and reset the game
	public:
		GuessTheNumber(int maxAttempts = 10);
		void play() override;
		void reset() override;
};
#endif 

