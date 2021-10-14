#include "Game.h"
#include <stdlib.h> 
#include <time.h> 

int main()
{
    srand(time(NULL));

    Game game;
    game.run();


    return 1;
}
