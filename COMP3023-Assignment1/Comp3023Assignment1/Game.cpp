#include <iostream>

#include "Game.h"
#include "ItemManager.h"
#include "MoonManager.h"
#include "Flashlight.h"
#include "util.h"

//the initaliser function that calls all the other functions


Game::~Game() {};

void Game::initaliseNewGame()
{
	//initalise the starting variables
	balance = 50;
	current_cargo_value = 0;
	quota = 150;
	//TODO: set current orbiting moon to corporation

	defineItems();
}

//defines the items and adds them to the hashmap
void Game::defineItems()
{
	
}

//defines the moon and adds them to the hashmap
void Game::defineMoons()
{

}

//ends the game
void Game::endGame()
{

}