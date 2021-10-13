#ifndef SNAKE_H
#define SNAKE_H

enum Direction { Left, Right, Up, Down };

struct Vector2
{
	int x;
	int y;
};

class Snake
{
private:
	Direction m_direction;
	Vector2 m_position;

public:
	Snake();
	~Snake();


	bool tryMove( int, int );
	void setDirection(Direction);

	void setPosition(Vector2 pos);
	Vector2 getPosition();
};

#endif