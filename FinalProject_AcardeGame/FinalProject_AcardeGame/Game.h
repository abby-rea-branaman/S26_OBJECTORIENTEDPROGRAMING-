#pragma once

// Main class for all the games
class Game
{
public:
	virtual void play() = 0;
	virtual void reset() = 0;
	virtual ~Game() {}
};
	