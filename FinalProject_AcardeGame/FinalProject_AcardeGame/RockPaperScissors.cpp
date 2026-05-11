#include "RockPaperScissors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Initializes the score
RockPaperScissors::RockPaperScissors() {
	playerScore = 0;
	computerScore = 0;
}

// Resets the score back to 0 
void RockPaperScissors::reset() {
	playerScore = 0;
	computerScore = 0;
}

// Generates the computer's choice randomly
string RockPaperScissors::getComputerChoice() {
	int choice = rand() % 3; // 0, 1, or 2

	if (choice == 0) 
		return "rock";
	else if (choice == 1) 
		return "paper";
	else 
		return "scissors";
}

// Determines who wins, updates the score, and displays the result of the round
void RockPaperScissors::determineWinner(const string& playerChoice, const string& computerChoice) {
	cout << "Computer chose: " << computerChoice << endl;
	cout << endl;
	
	if (playerChoice == computerChoice) {
		cout << "It's a tie!" << endl;
	} else if ((playerChoice == "rock" && computerChoice == "scissors") ||
			   (playerChoice == "paper" && computerChoice == "rock") ||
			   (playerChoice == "scissors" && computerChoice == "paper")) {
		cout << "You win this round!" << endl;
		playerScore++;
	} else {
		cout << "Computer wins this round!" << endl;
		computerScore++;
	}
}

// Main part of game; handles user input, game flow, and displays scores
void RockPaperScissors::play() {
	string playerChoice;
	
	cout << "Welcome to Rock Paper Scissors!" << endl;
	cout << endl;
	cout << "Enter 'rock', 'paper', or 'scissors' to play (or 'exit' to quit): ";
	
	while (true) {
		cin >> playerChoice;
		if (playerChoice == "exit") {
			cout << "Thanks for playing! Final Score - You: " << playerScore << " Computer: " << computerScore << endl;
			break;
		}
		if (playerChoice != "rock" && playerChoice != "paper" && playerChoice != "scissors") {
			cout << "Invalid choice. Please enter 'rock', 'paper', or 'scissors': ";
			continue;
		}
		string computerChoice = getComputerChoice();
		determineWinner(playerChoice, computerChoice);
		cout << "Current Score - You: " << playerScore << " Computer: " << computerScore << endl;
		cout << endl;
		cout << "Enter 'rock', 'paper', or 'scissors' to play again (or 'exit' to quit): ";
	}
}

