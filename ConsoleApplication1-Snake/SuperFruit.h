#ifndef SUPERFRUIT_H
#define SUPERFRUIT_H

#include "Vector2.h"

class SuperFruit
{
private:

	Vector2 m_pos;

public:
	SuperFruit();
	~SuperFruit();

	void setPosition0(Vector2 position);
	Vector2 getPosition0();

};

#endif