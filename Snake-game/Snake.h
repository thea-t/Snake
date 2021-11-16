#ifndef SNAKE_H
#define SNAKE_H

#include <vector>

#include "Direction.h"
#include "GameObject.h"
#include "Tail.h"

//#######################################################
//    Function    :    setDirection
//    Purpose        :    Sets the direction of the snake based on the pressed key.
//    Parameters    :    direction
//    Returns        :    None
//    Notes        :     None
//    See also    :    Snake::readInput()
//#######################################################
//#######################################################
//    Function    :    tryMove
//    Purpose        :    Checks if the snake can move towards a direction successfully. Returns true if it moves without hitting a wall or its tail, and returns false if it does.
//    Parameters    :    width, height
//    Returns        :    bool
//    Notes        :     None
//    See also    :    Game::update()
//#######################################################
//#######################################################
//    Function    :    getHead
//    Purpose        :    Returns the head char of the snake.
//    Parameters    :    None
//    Returns        :    char
//    Notes        :     Snake's head char changes based on which direction it moves towards.
//    See also    :    Game::render()
//#######################################################
//#######################################################
//    Function    :    growTail
//    Purpose        :    Creates a tail object in the previous position of the snake's head and adds this tail to the tails array so that all of them are rendered sequentially.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::onFruitCollected() 
//#######################################################
//#######################################################
//    Function    :    readInput
//    Purpose        :    Checks which key was pressed and sets the snake's direction accordingly.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::update()
//#######################################################
//#######################################################
//    Function    :    updateTails
//    Purpose        :    Updates the tail positions based on the previous element in the tails array or the snake's head. It also determines which direction the tail should be looking towards and sets its character accordingly.
//    Parameters    :    None
//    Returns        :    None
//    Notes        :     None
//    See also    :    Game::update()
//#######################################################

class Snake : public GameObject
{
private:
	char m_head;
	Direction m_direction;
	Vector2 m_lastPosition;

	void setDirection(Direction direction);
	
public:
	Snake();

	std::vector<Tail> tails;

	bool tryMove(int width, int height); 
	char getHead();
	void growTail();
	void readInput();
	void updateTails();
};

#endif