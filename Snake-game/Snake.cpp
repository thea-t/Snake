#include <conio.h>
#include <iostream>
#include <vector>

#include "Direction.h"
#include "Snake.h"
#include "Tail.h"

Snake::Snake()
	: GameObject()
{
	m_head = '>';
	setDirection( Direction::None );
}

void Snake::readInput()
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
		setDirection( Direction::Up );
		m_head = '^';
		break;

	case 's': //down
		setDirection( Direction::Down );
		m_head = 'v';
		break;

	case 'a': //left
		setDirection( Direction::Left );
		m_head = '<';
		break;

	case 'd': //right
		setDirection( Direction::Right );
		m_head = '>';
		break;
	}

}

bool Snake::tryMove( int mapWidth, int mapHeight )
{
	bool moveSuccessful = true;
	Vector2 snakePos = getPosition();
	m_lastPosition = snakePos;

	// move the snake and check if collided with borders
	switch( m_direction )
	{
	case Direction::Up:
		snakePos.y -= 1;

		if( snakePos.y < 1 )
		{
			moveSuccessful = false;
		}
		break;

	case Direction::Down:
		snakePos.y+= 1;
		if( snakePos.y == mapHeight + 1 )
		{
			moveSuccessful = false;
			snakePos.y = mapHeight;
		}
		break;

	case Direction::Left:
		snakePos.x-= 1;
		if( snakePos.x < 1)
		{
			moveSuccessful = false;
		}
		break;

	case Direction::Right:
		snakePos.x+= 1;
		if( snakePos.x == mapWidth + 1 )
		{
			moveSuccessful = false;
			snakePos.x = mapWidth;
		}
		break;
	}

	setPosition(snakePos);

	// check if collided with tail
	for ( size_t i = 0; i < tails.size(); i++ )
	{
		Vector2 tailPos = tails[i].getPosition();
		if ( tailPos.x == getPosition().x && tailPos.y == getPosition().y )
		{
			moveSuccessful = false;
			break;
		}
		
	}

	return moveSuccessful;
}

void Snake::setDirection( Direction dir )
{
	m_direction = dir;
}
char Snake::getHead()
{
	return m_head;
}

void Snake::growTail()
{
	// update tail char
	//https://stackoverflow.com/questions/755835/how-to-add-element-to-c-array
	Tail tail( m_lastPosition );
	if ( getPosition().x != m_lastPosition.x )
	{
		tail.setTailChar( '-' );
	}
	else if( getPosition().y != m_lastPosition.y )
	{
		tail.setTailChar( '|' );
	}
	tails.push_back( tail );
}

void Snake::updateTails()
{
	if( tails.size() > 0 )
	{
		for ( size_t i = 0; i < tails.size(); i++ )
		{
			// update tail position
			Vector2 lastPosition = tails[i].getPosition();
			Vector2 newPosition;

			if ( i == 0 )
			{
				newPosition = m_lastPosition;
			}
			else
			{
				newPosition = tails[i - 1].getLastPosition();
			}

			tails[i].setLastPosition( lastPosition );
			tails[i].setPosition( newPosition );

			// update tail char
			if ( lastPosition.x != newPosition.x )
			{
				tails[i].setTailChar('-');
			}
			else if ( lastPosition.y != newPosition.y )
			{
				tails[i].setTailChar('|');
			}
		}
	}
}
