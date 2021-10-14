#ifndef MAP_H
#define MAP_H

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

	struct Vector2 getRandomPos();

	void setSize(int, int);
};


#endif