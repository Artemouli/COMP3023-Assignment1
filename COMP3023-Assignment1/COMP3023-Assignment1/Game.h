#ifndef GAME
#define GAME
#include "MoonManager.h"
#include "ItemManager.h"
#include "util.h"

class Game 
{
public:
	Game() {};
	virtual ~Game();

	//the initaliser function that calls all the other functions
	virtual void initaliseNewGame();

	//defines the items and adds them to the hashmap
	virtual void defineItems();

	//defines the moons and adds them to the hashmap
	virtual void defineMoons();	

private:
	int balance;
	int total_days;
	int current_day;
	int current_cargo_value;
	
	//landed moon variable

	//simulation parameters
	//instance of item manager
	// instance of moon manager
	util utilities;
};


#endif