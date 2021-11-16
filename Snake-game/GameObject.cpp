#include <iostream>

#include "GameObject.h"

GameObject::GameObject()
{
}
GameObject::~GameObject()
{
}

 void GameObject::setPosition( Vector2 position )
{
	m_position = position;
}

Vector2 GameObject::getPosition() const
{
	return m_position;
}
