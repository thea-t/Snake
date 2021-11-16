#ifndef FRUIT_H
#define FRUIT_H

#include "GameObject.h"

//#######################################################
//    Class 		  :    Fruit
//    Purpose         :    A game object that is an objective that the snake should collect.
//    Parameters      :    None
//    Returns         :    None
//    Notes           :    None
//    See also		  :    Game::onFruitCollected(), Game::render(), Game::run()
//#######################################################

class Fruit : public GameObject
{
private:

public:
	Fruit();

};

#endif