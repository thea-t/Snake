#ifndef GAME_H
#define GAME_H

#include <list>

#include "Fruit.h"
#include "Map.h"
#include "Snake.h"

//#######################################################
//    Function    :    setDifficulty
//    Purpose        :    Determines the difficulty of the game based on the user input.
//    Parameters    :    setDifficulty, sleepTime
//    Returns        :    void
//    Notes        :     Parameter setDifficulty is a boolean that checks if the given input is valid. Parameter sleepTime is how fast the game updates, so the higher it is, the easier the difficulty gets.
//    See also    :    Game::update()
//#######################################################
//#######################################################
//    Function    :    update
//    Purpose        :    Game loop
//    Parameters    :    None
//    Returns        :    void
//    Notes        :     It is called every time the game loop iterates.
//    See also    :    Game::run()
//#######################################################
//#######################################################
//    Function    :    render
//    Purpose        :    Displays all elements on the screen including the map, the snake, the fruit and the score.
//    Parameters    :    None
//    Returns        :    void
//    Notes        :     There is only one render function in the game because the map is rendered in a 2d grid while the fruit and the snake can not be printed over the map. Instead, they should be printed sequentially.
//    See also    :    Game::run()
//#######################################################
//#######################################################
//    Function    :    onFruitCollected
//    Purpose        :    Grows the snakes tail, increases the score and randomizes the fruits position.
//    Parameters    :    None
//    Returns        :    void
//    Notes        :     Is called when the snake collects a fruit.
//    See also    :    Game::render()
//#######################################################
//#######################################################
//    Function    :    addScore
//    Purpose        :    Increments the score. 
//    Parameters    :    None
//    Returns        :    void
//    Notes        :     Is called when the snake collects a fruit.
//    See also    :    Game::onFruitCollected()
//#######################################################
//#######################################################
//    Function    :    run
//    Purpose        :    Starts the game and the update loop, instantiates the map, the sanke and the fruit.
//    Parameters    :    None
//    Returns        :    void
//    Notes        :     It is called by the main function when the game starts.
//    See also    :    Main::main()
//#######################################################
class Game
{
private:
	bool m_gameOver;
	int m_score = 0;
	Map m_map;
	Snake m_snake;
	Fruit m_fruit;


	void setDifficulty( bool& setDifficulty, int& sleepTime );
	void update();
	void render();
	void onFruitCollected();
	void addScore();

public:
	Game();

	void run();
};

#endif