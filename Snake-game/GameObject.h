#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vector2.h"

//#######################################################
//    Function    :    setPosition
//    Purpose        :    Sets the position of the game object
//    Parameters    :    Vector2 position
//    Returns        :    None
//    Notes        :     None
//    See also    :    Snake::tryMove, Snake::updateTails, Game::run(), Game::onFruitCollected() 
//#######################################################
//#######################################################
//    Function    :    getPosition
//    Purpose        :    Returns the position of the game object
//    Parameters    :    None
//    Returns        :    Vector2
//    Notes        :     None
//    See also    :    Game::render(), Snake::tryMove, Snake::updateTails, Snake::growTail
//#######################################################

class GameObject
{
private:
	Vector2 m_position;

public:
	GameObject();
	~GameObject();

	void setPosition( Vector2 position );
	Vector2 getPosition() const;

};


#endif#pragma once
