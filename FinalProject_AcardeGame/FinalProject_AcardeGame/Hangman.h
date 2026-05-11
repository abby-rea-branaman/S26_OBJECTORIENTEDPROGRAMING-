#ifndef HANGMAN_H
#define HANGMAN_H

#include "Game.h"
#include <string>
#include <vector>

class Hangman : public Game {
private:
    std::string wordToGuess;
    std::vector<char> guessedLetters;
    int maxAttempts;
    int attemptsMade;

    void displayProgress();
    bool checkLetter(char letter);
    void loadWord();

public:
    Hangman();
    void play() override;
    void reset() override;
};

#endif
