#include "Map.h"
#include "Snake.h"
#include <stdlib.h> 

Map::Map()
{
    m_width = 4;
    m_height = 4;
}

//destructor
Map::~Map()
{

}

int Map::getHeight() 
{
    return m_height;
}

int Map::getWidth() 
{
    return m_width;
}

void Map::setSize( int width, int height )
{
    m_width = width;
    m_height = height;
}

struct Vector2 Map::getRandomPos() 
{
    struct Vector2 position;

    position.x = rand() % m_width;
    position.y = rand() % m_height;

    return position;
}