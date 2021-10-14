#ifndef SNAKE_H
#define SNAKE_H


#include "Vector2.h"
#include "Direction.h"
#include "GameObject.h"

class Snake
{
private:

	Vector2 m_position;
	Direction m_direction;

public:
	Snake();
	~Snake();

	void setPosition(Vector2 position);
	Vector2 getPosition();

	bool tryMove( int, int );
	void setDirection(Direction);

};

#endif