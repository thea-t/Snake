#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Snake.h"

class Game
{
private:
	bool m_gameOver;

public:
	Game();
	
	Map map;
	Snake snake;

	void draw();
	void readInput();
	void run();
};


#endif