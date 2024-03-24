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

private:
	int balance;
	int total_days;
	int current_day;
	int current_cargo_value;
	
	//landed moon variable

	//simulation parameters
	//instance of item manager
	// instance of moon manager
	
};


#endif