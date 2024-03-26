#ifndef GAME
#define GAME
#include "MoonManager.h"
#include "ItemManager.h"
#include "util.h"

#include <vector>
#include <random>

class Game 
{
public:
	Game() {};
	~Game();


	//the initaliser function that calls all the other functions
	void InitaliseNewGame();

	//defines the items and adds them to the hashmap
	void DefineItems();

	//defines the moons and adds them to the hashmap
	void DefineMoons();	

	//ends the game
	void EndGame();

private:
	int balance;
	int total_days;
	int current_day;
	int current_cargo_value;
	int quota;
	
	//landed moon variable

	//simulation parameters
	//instance of item manager
	ItemManager itemManager;
	// instance of moon manager
	
	//instance of num generator
	std::mt19937 numGenerator;
};


#endif