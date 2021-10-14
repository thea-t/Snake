#include "Fruit.h"
#include "Vector2.h"

//constructor
Fruit::Fruit ()
{

}

//destructor
Fruit::~Fruit ()
{

}

void Fruit::setFRPosition(Vector2 position)
{
	m_position = position;
}

Vector2 Fruit::getFRPosition()
{
	return m_position;
}