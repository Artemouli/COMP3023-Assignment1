#include <iostream>
#include <memory>

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

	std::cout << "in initalise" << std::endl;

	defineItems();

	std::cout << "after defining" << std::endl;

	itemManager.Store();
}

//defines the items and adds them to the hashmap
void Game::defineItems()
{
	//creates the flashlight object and then calls itemManager
	Flashlight* flashlight = new Flashlight();
	
	//inserts the new item at the end of the vector
	useableItems.push_back(flashlight);
	//gets the new item at registers it
	itemManager.RegisterItem(useableItems.back());
}

//defines the moon and adds them to the hashmap
void Game::defineMoons()
{

}

//ends the game
void Game::endGame()
{
	//for loop here to delete the items in useableItems
}