#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Game.h"
#include "Map.h"
#include "Snake.h"

Game::Game()
{
}

void Game::run()
{
	m_gameOver = false;

	int mapWidth = 16;
	int mapHeight = 16;

	map.setSize( mapWidth, mapHeight );

	struct Vector2 snakePos;

	snakePos = map.getRandomPos();

	//snakePos.x = mapWidth / 2;
	//snakePos.y = mapHeight / 2;

	snake.setPosition(snakePos);

	// Game loop
	while ( !m_gameOver )
	{
		readInput();
		m_gameOver = !snake.tryMove( mapWidth, mapHeight );
		draw();

		//wait for seconds
		Sleep(300);
	}
}

void Game::readInput() 
{

	if ( !_kbhit() )
	{
	    return;
	}

	char c = _getch();

	//gets the pressed key
	switch (c) 
	{
	case 'w': //up
		snake.setDirection( Up );
	    break;

	case 's': //down
		snake.setDirection( Down );
	    break;

	case 'a': //left
		snake.setDirection( Left );
	    break;

	case 'd': //right
		snake.setDirection( Right );
	    break;
	}

}

void Game::draw() {
	//clear the screen
	system("cls");
	
	struct Vector2 snakePos = snake.getPosition();


	for ( int y = 0; y < map.getHeight(); y++ )
	{
		for ( int x = 0; x < map.getWidth(); x++ )
		{
			if ( x == snakePos.x && y == snakePos.y ) {
				std::cout << "C";
			}
			else 
			{
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}
}