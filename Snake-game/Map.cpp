#include <stdlib.h> 

#include "Map.h"

Map::Map()
{
    m_width = 4;
    m_height = 4;
}

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
// https://stackoverflow.com/questions/12580820/random-number-between-1-to-10-using-c
Vector2 Map::getRandomPos()
{
    Vector2 position;

    position.x = 1 + rand() % m_width;
    position.y = 1 + rand() % m_height;

    return position;
}