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
	float GenerateNum(float min = 0.0f, float max = 0.0f);

	//used to decrease amount of alive crew
	void DecreaseAliveCrew();
	//used to get current amount of alive crew
	int CurrentAliveCrew();

	//used to increase amount of current cargo value
	void IncreaseCargoValue(int scrap);
	//used when all of the employees have died
	void AllEmployeesDead();

private:
	int balance = 50;
	int total_days = 0;
	int current_day = 0;
	int current_cargo_value = 0;
	int quota = 150;
	int current_alive_crew = 4;

	
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