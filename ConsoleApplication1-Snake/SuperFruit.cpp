#include "SuperFruit.h"

//constructor
SuperFruit::SuperFruit()
{

}
//destructor
SuperFruit::~SuperFruit()
{

}

void SuperFruit::setPosition0(Vector2 position)
{
	m_pos = position;
}

Vector2 SuperFruit::getPosition0()
{
	return m_pos;
}