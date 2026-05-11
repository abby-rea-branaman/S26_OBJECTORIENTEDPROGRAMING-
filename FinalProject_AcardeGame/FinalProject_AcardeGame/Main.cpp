#include <iostream>
#include "Guess_The_Number.h"
#include "RockPaperScissors.h"
using namespace std;

int main() {

    // Main menu for Game 
    int choice;
    cout << "Welcome to the Arcade Game!" << endl;
    // Choices for the user to pick from
    while (true) {
        cout << "Please select a game to play:" << endl;
        cout << "1. Guess The Number" << endl;
        cout << "2. Rock Paper Scissors" << endl;
        cout << "3. Tic Tac Toe" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << endl;
            GuessTheNumber game;
            game.play();
        }
        else if (choice == 2) {
            cout << endl;
            RockPaperScissors game;
            game.play();
        }
        else if (choice == 3) {
            cout << "Tic Tac Toe is not implemented yet." << endl;
        }
        else if (choice == 4) {
            cout << "Thank you for playing! Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}