#include "Snake.h"

//constructor
Snake::Snake()
{

}
//destructor
Snake::~Snake()
{
	
}

bool Snake::tryMove( int mapWidth, int mapHeight )
{
	bool moveSuccessful = true;
	Vector2 snakePos = getPosition();

	switch ( m_direction ) 
	{
	case Up:
		snakePos.y--;

		if (snakePos.y < 0 )
		{
			moveSuccessful = false;
			snakePos.y = 0;
		}
		break;

	case Down:
		snakePos.y++;
		if (snakePos.y == mapHeight )
		{
			moveSuccessful = false;
			snakePos.y = mapHeight - 1;
		}
		break; 

	case Left:
		snakePos.x--;
		if (snakePos.x < 0 )
		{
			moveSuccessful = false;
			snakePos.x = 0;
		}
		break;

	case Right:
		snakePos.x++;
		if (snakePos.x == mapWidth )
		{
			moveSuccessful = false;
			snakePos.x = mapWidth - 1;
		}
		break;
	}

	setPosition(snakePos);
	return moveSuccessful;
}

void Snake::setDirection(Direction dir)
{
	m_direction = dir;
}

void Snake::setPosition(Vector2 position)
{
	m_position = position;
}

Vector2 Snake::getPosition()
{
	return m_position;
}




