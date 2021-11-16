#ifndef MAP_H
#define MAP_H

#include "Vector2.h"


//#######################################################
//    Function    :    getHeight
//    Purpose        :   Returns the height of the map.
//    Parameters    :    None
//    Returns        :    int
//    Notes        :     None
//    See also    :    Game::update(), Game::render()
//#######################################################
//#######################################################
//    Function    :    getWidth
//    Purpose        :    Returns the width of the map.
//    Parameters    :    None
//    Returns        :    int
//    Notes        :     None
//    See also    :    Game::update(), Game::render()
//#######################################################
//#######################################################
//    Function    :    getRandomPos
//    Purpose        :    Randomly picks a position on the map and returns it.
//    Parameters    :    None
//    Returns        :    Vector2
//    Notes        :     When the fruit is collected by the snake, it picks a random position instead of getting destroyed and reconstructed.
//    See also    :    Game::run(), Game::onFruitCollected()
//#######################################################
//#######################################################
//    Function    :    setSize
//    Purpose        :    Sets the width and the height of the map.
//    Parameters    :    int width, int height
//    Returns        :    None
//    Notes        :     Jt is called when the game starts.
//    See also    :    Game::run()
//#######################################################

class Map
{
private:
	int m_height;
	int m_width;

public:
	Map();
	~Map();

	int getHeight();
	int getWidth();
	Vector2 getRandomPos();
	void setSize( int width, int height );
};


#endif