#include <iostream>
#include <string> 
#include <windows.h>

#include "Game.h"
#include "GameObject.h"
#include "Map.h"
#include "Snake.h"
#include "Tail.h"
#include "Timer.h"
#include "Vector2.h"

Game::Game() 
{
	m_gameOver = false;
}

void Game::run()
{
	m_gameOver = false;

	int mapWidth = 32;
	int mapHeight = 16;

	m_map.setSize( mapWidth, mapHeight );

	Vector2 snakePos;
	Vector2 fruitPos;

	snakePos.x = mapWidth / 2;
	snakePos.y = mapHeight / 2;

	fruitPos = m_map.getRandomPos();

	m_snake.setPosition( snakePos );
	m_fruit.setPosition( fruitPos );

	update();
}

void Game::update()
{
	int endGameLoops = 0;
	int sleepTime = 300;
	bool difficultySet = false;

	while( true )
	{
		setDifficulty( difficultySet, sleepTime );


		if( !m_gameOver )
		{
			m_gameOver = !m_snake.tryMove( m_map.getWidth(), m_map.getHeight() );
			m_snake.readInput();
			m_snake.updateTails();
			render();
		}
		else
		{
			HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
			
			system( "cls" );
			for( int i = 0; i < endGameLoops; i++ )
			{
				std::cout << std::endl;
			}
			endGameLoops++;

			if( endGameLoops == 15 )
			{
				endGameLoops = 0;
			}

			SetConsoleTextAttribute( hConsole, endGameLoops );
			std::cout << " GAME OVER!";
			std::cout << std::endl;
			std::string s = std::to_string( m_score );
			std::cout << " Score: " + s;
		}
		Sleep( sleepTime );
	}
}

void Game::setDifficulty( bool& difficultySet, int& sleepTime ) 
{
	int difficulty = 0;
	while( !difficultySet )
	{
		if( difficulty !=0 ) 
		{
			std::cout << "Difficulty not valid!";
			std::cout << std::endl;
		}
		std::cout << "Select difficulty(1:Easy, 2:Medium, 3:Hard): ";
		std::cin >> difficulty;
		difficultySet = true;

		if( difficulty == 1 )
		{
			sleepTime = 300;
		}
		else if( difficulty == 2 )
		{
			sleepTime = 150;
		}
		else if( difficulty == 3 )
		{
			sleepTime = 50;
		}
		else
		{
			difficultySet = false;
		}
	}

}

void Game::render() 
{
	//clear the screen
	system( "cls" );

	Vector2 snakePos = m_snake.getPosition();
	Vector2 fruitPos = m_fruit.getPosition();

	// compare the fruit position and snake position
	if( snakePos.x == fruitPos.x && snakePos.y == fruitPos.y )
	{
		onFruitCollected();
	}

	// https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	int wallColorCode = 8;
	int snakeColorCode = 13;
	int fruitColorCode = 14;
	int scoreColorCode = 3;

	for( int y = 0; y < m_map.getHeight()+2; y++ )
	{
		for( int x = 0; x < m_map.getWidth()+2; x++ )
		{

			if( y == 0 || y == m_map.getHeight()+1 )
			{
				SetConsoleTextAttribute( hConsole, wallColorCode );
				std::cout << "#";
			}

			else if( x == 0 || x == m_map.getWidth() + 1 )
			{
				SetConsoleTextAttribute( hConsole, wallColorCode );
				std::cout << "#";
			}
			// render the head
			else if( x == snakePos.x && y == snakePos.y ) 
			{
				SetConsoleTextAttribute( hConsole, snakeColorCode );
				std::cout << m_snake.getHead();
			}
			// render the fruit
			else if( x == fruitPos.x && y == fruitPos.y )
			{
				SetConsoleTextAttribute( hConsole, fruitColorCode );
				std::cout << "O";
			}
			// render empty
			else
			{
				bool hasTail = false;
				char tailChar;

				// https://stackoverflow.com/questions/7443222/how-do-i-deal-with-signed-unsigned-mismatch-warnings-c4018
				for( size_t  i = 0; i < m_snake.tails.size(); i++ )
				{
					Vector2 tailPos = m_snake.tails[i].getPosition();

					if( x == tailPos.x && y == tailPos.y ) 
					{
						hasTail = true;
						tailChar = m_snake.tails[i].getTailChar();
						break;
					}
				}

				if( hasTail ) 
				{
					SetConsoleTextAttribute(hConsole, snakeColorCode);
					std::cout << tailChar;
				}
				else 
				{
					std::cout << " ";
				}
			}
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::string s = std::to_string( m_score );

	SetConsoleTextAttribute( hConsole, scoreColorCode );
	std::cout << "Score: " + s;
}

void Game::onFruitCollected() 
{
	Vector2 fruitPos;
	fruitPos = m_map.getRandomPos();
	m_fruit.setPosition( fruitPos );

	m_snake.growTail();
	addScore();

}
void Game::addScore() 
{
	m_score++;
}



	

