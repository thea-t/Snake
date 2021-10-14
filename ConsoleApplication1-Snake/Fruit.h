#ifndef FRUIT_H
#define FRUIT_H

#include "Vector2.h"

class Fruit
{
private:
	Vector2 m_position;
	//void render();

public:
	Fruit();
	~Fruit();

//	void update() override;

	void setFRPosition(Vector2 position);
	Vector2 getFRPosition();

};

#endif