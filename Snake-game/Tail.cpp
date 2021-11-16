#include <iostream>

#include "Direction.h"
#include "Tail.h"


Tail::Tail()
	: GameObject()
	, m_tailChar( '-' )
{
}
Tail::Tail( Vector2& pos )
	: GameObject()
	,m_tailChar( '-' )
{
	setPosition( pos );
}

char Tail::getTailChar() const
{
	return m_tailChar;
}
void Tail::setTailChar( char tailChar ) 
{
	m_tailChar = tailChar;
}

Vector2 Tail::getLastPosition() const
{
	return m_lastPosition;
}

void Tail::setLastPosition( Vector2 lastPos )
{
	m_lastPosition = lastPos;
}