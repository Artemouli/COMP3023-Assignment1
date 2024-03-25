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

	//instance of random num generator is instantiated
	std::mt19937 numGenerator(std::random_device{}());

	//TODO: set current orbiting moon to corporation



	defineItems();
	

	std::cout << "after defining" << std::endl;

	itemManager.Store();
}

//defines the items and adds them to the hashmap
void Game::defineItems()
{
	//creates the flashlight object and then calls itemManager
	Flashlight* flashlight = new Flashlight();
	itemManager.RegisterItem(flashlight);
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