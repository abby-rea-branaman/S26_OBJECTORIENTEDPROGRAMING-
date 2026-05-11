#include "Hangman.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

Hangman::Hangman() {
    maxAttempts = 6;
    attemptsMade = 0;
    // Correct way: call reset() as a member function, not as a static function
    reset();
}

void Hangman::loadWord() {
    string wordList[] = { "programming", "hangman", "challenge", "arcade", "game", "cat", "apple", "factor" };
    int size = 8;

    wordToGuess = wordList[rand() % size];
}

void Hangman::reset() {
    guessedLetters.clear();
    attemptsMade = 0;
    loadWord();
}

void Hangman::displayProgress() {
    cout << "\nWord: ";

    for (char c : wordToGuess) {
        if (find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
            cout << c << " ";
        }
        else {
            cout << "_ ";
        }
    }

    cout << "\nAttempts left: " << (maxAttempts - attemptsMade);

    cout << "\nGuessed letters: ";
    for (char c : guessedLetters) {
        cout << c << " ";
    }

    cout << endl;
}

bool Hangman::checkLetter(char letter) {
    // already guessed
    if (find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()) {
        cout << "You already guessed that letter!\n";
        return true; // don't penalize
    }

    guessedLetters.push_back(letter);

    if (wordToGuess.find(letter) == string::npos) {
        attemptsMade++;
        return false;
    }

    return true;
}

void Hangman::play() {
    char guess;

    while (attemptsMade < maxAttempts) {
        displayProgress();

        cout << "\nEnter a letter: ";
        cin >> guess;

        if (checkLetter(guess)) {
            cout << "Correct!\n";
        }
        else {
            cout << "Wrong!\n";
        }

        // check win condition
        bool allGuessed = true;
        for (char c : wordToGuess) {
            if (find(guessedLetters.begin(), guessedLetters.end(), c) == guessedLetters.end()) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "\n🎉 You win! The word was: " << wordToGuess << endl;
            return;
        }
    }

    cout << "\n💀 Game Over! The word was: " << wordToGuess << endl;
}

