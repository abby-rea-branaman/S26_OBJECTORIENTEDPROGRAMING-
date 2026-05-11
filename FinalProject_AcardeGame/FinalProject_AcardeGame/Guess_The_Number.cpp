#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Guess_The_Number.h"
using namespace std;

// Sets the max attempts, resets the attempts made, and generates a random number 
GuessTheNumber::GuessTheNumber(int maxAttempts) : maxAttempts(maxAttempts), attemptsMade(0)
{
	// Seed the random number generator and generate a random number between 1 and 100
	srand((time(0)));
	numberToGuess = rand() % 100 + 1;
}

// Main part of game; handles user input, game flow, and displays results
void GuessTheNumber::play()
{
	int guess;
	while (attemptsMade < maxAttempts)
	{
		cout << "Attempt " << attemptsMade + 1 << "/" << maxAttempts << ": Enter your guess (1-100): ";
		cin >> guess;
		attemptsMade++;
		if (guess < numberToGuess)
			cout << "Too low! Try again." << endl;
		else if (guess > numberToGuess)
			cout << "Too high! Try again." << endl;
		else
		{
			cout << "Congratulations! You've guessed the number!" << endl;
			cout << endl;
			return;
		}
	}
	cout << "Game Over! The number was: " << numberToGuess << endl;
	cout << endl;
}

void GuessTheNumber::reset()
{
	srand((time(0)));
	numberToGuess = rand() % 100 + 1;
	attemptsMade = 0;
}