#ifndef MAP_H
#define MAP_H

#include "Vector2.h"

class Map
{
private:
	int m_height;
	int m_width;

public:
	// Constructor
	Map();
	~Map();

	int getHeight();
	int getWidth();

	Vector2 getRandomPos();

	void setSize(int, int);
};


#endif