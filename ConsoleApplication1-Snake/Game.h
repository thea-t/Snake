#ifndef GAME_H
#define GAME_H

#include "Map.h"
#include "Snake.h"
#include "Vector2.h"
#include "GameObject.h"
#include "Fruit.h"
#include "SuperFruit.h"

class Game
{
private:
	bool m_gameOver;

public:
	Game();
	
	Map map;
	Snake snake;
	//SuperFruit superFruit;

	void draw();
	void readInput();
	void run();
};


#endif