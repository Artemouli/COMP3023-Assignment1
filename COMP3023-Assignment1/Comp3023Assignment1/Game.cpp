#include <iostream>
#include <memory>

#include "Game.h"
#include "ItemManager.h"

#include "Flashlight.h"

#include "MoonManager.h"

#include "Prototyping.h"
#include "Corporation.h"

#include "util.h"
#include "AbstractMoon.h"

//the initaliser function that calls all the other functions

//multipliers
//scrap value multi = scrap
//explorer survival chance = explorer
//operator survival chance = operator
//explorer save chance = save
//loot recovery multi = loot

Game::~Game() {};

void Game::InitaliseNewGame()
{
	//initalise the starting variables
	balance = 50;
	current_cargo_value = 0;
	quota = 150;
	current_alive_crew = 4;

	DefineMoons();
	DefineItems();
	
	//TODO: set current orbiting moon to corporation
	current_orbit_moon = moon_manager.GetMoon("Corporation");

	//InOrbit();

	//testing code
	std::cout << "after defining" << std::endl;

	item_manager.Store();

	item_manager.Buy("Flashlight");
	item_manager.Store();

	float temp = 0.5f;
	std::string s_temp = "explorer";
	std::cout << "temp: " << temp << std::endl;
	temp = item_manager.ApplyMulti(temp, s_temp);
	std::cout << "temp: " << temp << std::endl;

	moon_manager.ViewMoons();
	
	current_orbit_moon = moon_manager.GetMoon("Prototyping");

	current_orbit_moon->SendEmployees(*this, 3);

	std::cout << "money " << current_cargo_value << std::endl;

	current_orbit_moon->ChooseWeatherCondition(0.5f);

	moon_manager.ViewMoons(); 

}

void Game::InOrbit()
{
	std::cout << "empty" << std::endl;
}

void Game::LandedMoon()
{
	std::cout << "empty" << std::endl;
}

//defines the items and adds them to the hashmap
void Game::DefineItems()
{
	//creates the flashlight object and then calls itemManager
	Flashlight* flashlight = new Flashlight();
	item_manager.RegisterItem(flashlight);
}

//defines the moon and adds them to the hashmap
void Game::DefineMoons()
{
	Corporation* corporation = new Corporation();
	moon_manager.RegisterMoon(corporation);
	Prototyping* prototyping = new Prototyping();
	moon_manager.RegisterMoon(prototyping);
}

float Game::ApplyItemManagerMulti(float parameter_chance, std::string parameter_name)
{
	return item_manager.ApplyMulti(parameter_chance, parameter_name);
}

//used for generating a number that AbstractMoon can use
//default values for calling to get typical percentage chance
float Game::GenerateNum(float min, float max)
{
	//instance of random num generator is instantiated
	std::mt19937 num_generator(std::random_device{}());
	//std::uniform_int_distribution<int> dist(min, max);
	std::uniform_real_distribution<float> dist(min, max);
	return dist(num_generator);
}

void Game::DecreaseAliveCrew()
{
	current_alive_crew--;
}

int Game::CurrentAliveCrew()
{
	return current_alive_crew;
}

void Game::IncreaseCargoValue(int scrap)
{
	current_cargo_value = current_cargo_value + scrap;
}

void Game::AllEmployeesDead()
{
	current_cargo_value = 0;
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	std::cout << "All the employees died and the scrap is lost.";
	std::cout << "Autopilot will now bring the ship back to orbit.";
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
}

//ends the game
void Game::EndGame()
{
	//for loop here to delete the items and moons
	item_manager.DeleteItems();
	moon_manager.DeleteMoons();
}

