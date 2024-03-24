#ifndef GAME
#define GAME
#include "MoonManager.h"
#include "ItemManager.h"
#include "util.h"

class Game 
{
public:
	Game() {};
	~Game();


	//the initaliser function that calls all the other functions
	void initaliseNewGame();

	//defines the items and adds them to the hashmap
	void defineItems();

	//defines the moons and adds them to the hashmap
	void defineMoons();	

	//ends the game
	void endGame();

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
	
};


#endif