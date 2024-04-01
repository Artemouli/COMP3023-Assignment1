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

	//exclusively used by abstract moon so it can apply the multi
	float ApplyItemManagerMulti(float parameter_chance, std::string parameter_name);

	//used to generate a number
	int GenerateNum(int min = 0, int max = 100);

private:
	int balance;
	int total_days;
	int current_day;
	int current_cargo_value;
	int quota;
	int current_alive_crew;

	
	//landed moon variable

	//simulation parameters
	//instance of item manager
	ItemManager itemManager;
	// instance of moon manager
	MoonManager moonManager;
	//instance of num generator
	std::mt19937 numGenerator;
};


#endif