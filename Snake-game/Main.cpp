#include <stdlib.h> 
#include <time.h> 

#include "Game.h"

int main()
{
    srand( ( unsigned int )time( NULL ) );

    Game game;
    game.run();
    return 1;
}