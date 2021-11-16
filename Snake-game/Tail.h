#ifndef TAIL_H
#define TAIL_H

#include "GameObject.h"

//#######################################################
   //    Function    :    getTailChar
   //    Purpose        :    Returns the char of the snakes tail.
   //    Parameters    :    None
   //    Returns        :    char
   //    Notes        :     None
   //    See also    :    Game::render()
   //#######################################################
//#######################################################
   //    Function    :    setTailChar
   //    Purpose        :    Sets the char of the snakes tail.
   //    Parameters    :    char
   //    Returns        :    None
   //    Notes        :     None
   //    See also    :    Snake::growTail(), Snake::updateTails()
   //#######################################################
//#######################################################
   //    Function    :    getLastPosition
   //    Purpose        :    Returns the last position that the tail had in the previous update.
   //    Parameters    :    None
   //    Returns        :    Vector2
   //    Notes        :     None
   //    See also    :    Snake::updateTails()
   //#######################################################
//#######################################################
   //    Function    :    setLastPosition
   //    Purpose        :    Sets the last position that the tail had in the previous update.
   //    Parameters    :    None
   //    Returns        :    None
   //    Notes        :     None
   //    See also    :    Snake::updateTails()
   //#######################################################

class Tail : public GameObject
{
private:
	char m_tailChar;
	Vector2 m_lastPosition;


public:
	Tail();
	Tail(Vector2& pos);

	char getTailChar() const;
	void setTailChar( char tailChar );
	Vector2 getLastPosition() const;
	void setLastPosition( Vector2 lastPosition );
};

#endif