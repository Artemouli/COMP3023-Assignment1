#include <iostream>
#include <memory>

#include "Game.h"
#include "ItemManager.h"

#include "Flashlight.h"
#include "Shovel.h"
#include "ProFlashlight.h"
#include "Teleporter.h"
#include "InverseTeleporter.h"
#include "Backpack.h"
#include "HydraulicsMK2.h"

#include "MoonManager.h"

#include "Prototyping.h"
#include "Corporation.h"
#include "Insurance.h"
#include "Pledge.h"
#include "Defence.h"
#include "April.h"
#include "Tore.h"
#include "Hyperion.h"

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

void Game::initaliseNewGame()
{
	//initalise the starting variables
	balance = 50;
	current_cargo_value = 0;
	quota = 150;
	current_alive_crew = 4;

	defineMoons();
	defineItems();
	
	//TODO: set current orbiting moon to corporation
	current_orbit_moon = moon_manager.getMoon("corporation");

	std::cout << \
		"    ___               _ _           ___                 \n" \
		"   /   \\___  __ _  __| | |_   _    / __\\___  _ __ _ __  \n" \
		"  / /\\ / _ \\/ _` |/ _` | | | | |  / /  / _ \\| '__| '_ \\ \n" \
		" / /_//  __/ (_| | (_| | | |_| | / /__| (_) | |  | |_) |\n" \
		"/___,' \\___|\\__,_|\\__,_|_|\\__, | \\____/\\___/|_|  | .__/ \n" \
		"                          |___/                  |_|    " << std::endl;

	std::cout << "Welcome!" << std::endl;
	std::cout << "We trust that you will be a great asset to the corporation!" << std::endl;
	std::cout << std::endl;

	newDay();

	//testing code
	/*std::cout << "after defining" << std::endl;

	item_manager.Store();

	item_manager.Buy("Flashlight");
	item_manager.Store();

	float temp = 0.5f;
	std::string s_temp = "explorer";
	std::cout << "temp: " << temp << std::endl;
	temp = item_manager.applyMulti(temp, s_temp);
	std::cout << "temp: " << temp << std::endl;

	moon_manager.viewMoons();
	
	current_orbit_moon = moon_manager.getMoon("Prototyping");

	current_orbit_moon->sendEmployees(*this, 3);

	std::cout << "money " << current_cargo_value << std::endl;

	current_orbit_moon->ChooseWeatherCondition(0.5f);

	moon_manager.viewMoons(); 

	current_orbit_moon = moon_manager.getMoon("Corporation");

	current_orbit_moon->sellCargo(*this, current_cargo_value); */
}

void Game::newDay()
{
	
	total_days += 1;
	current_alive_crew = 4;
	current_day -= 1;
	
	if (current_day < 0)
	{
		if (balance >= quota)
		{
			quota = static_cast<int>(quota * 1.5);
			std::cout << "-------------------------------------" << std::endl;
			std::cout << "CONGRATULATIONS ON MAKING QUOTA!" << std::endl;
			std::cout << "New quota: $" << quota << std::endl;
			std::cout << "-------------------------------------" << std::endl;
			current_day = 3;
		}
		else
		{
			std::cout << "-------------------------------------" << std::endl;
			std::cout << ">>>>>>>>>>>>> GAME OVER <<<<<<<<<<<<<" << std::endl;
			std::cout << "-------------------------------------" << std::endl;
			std::cout << std::endl;

			std::cout << "You did not meet quota in time, and your employees have been fired." << std::endl;
			std::cout << "You kept them alive for " << total_days << " days." << std::endl;
			std::cout << std::endl;
			endGame();
		}
	}
	//sets the moons weathers
	moon_manager.newDay(*this);

	std::cout << "============= " << "DAY " << total_days << " =============" << std::endl;
	std::cout << "Current cargo value: $" << current_cargo_value << std::endl;
	std::cout << "Current balance: $" << balance << std::endl;
	std::cout << "Current quota: $" << quota << " (" << current_day << " days left to meet quota)" << std::endl;
	std::cout << "Currently orbiting: " << current_orbit_moon->getName() << std::endl;

	//space
	std::cout << std::endl;
	std::cout << ">MOONS" << std::endl;
	std::cout << "To see the list of moons the autopilot can route to." << std::endl;

	std::cout << std::endl;
	std::cout << ">STORE" << std::endl;
	std::cout << "To see the company store's selection of useful items." << std::endl;

	std::cout << std::endl;
	std::cout << ">INVENTORY" << std::endl;
	std::cout << "To see the list of items you've already bought." << std::endl;

	inOrbit();
}

void Game::inOrbit()
{
	std::cout << std::endl;
	std::string user_input;
	std::cout << "> ";
	std::getline(std::cin, user_input);
	util::lower(user_input);
	std::vector<std::string> args;
	util::splitArguments(user_input, args);
	std::cout << std::endl;

	//handle moon input
	if (user_input == "moons" || user_input == "route")
	{
		if (user_input == "moons")
		{
			std::cout << "Welcome to the exomoons catalogue." << std::endl;
			std::cout << "To route the autopilot to a moon, use the word ROUTE." << std::endl;
			std::cout << "---------------------------------------" << std::endl;
			moon_manager.viewMoons();
		}
		else if (user_input == "route")
		{
			//check if there are more arguments 
			//e.g. "route corporation fun" wouldnt work because of the extra words after the moon name
			if (args.size() > 1)
			{
				std::cout << "Bad command; the syntax is : " << "\"route moonName\"" << std::endl;
			}
			else
			{
				//this string is used for checking if the currently orbiting moon is the same as the input
				std::string current_moon_name = current_orbit_moon->getName();
				util::lower(current_moon_name);
				//check if is currently orbiting moon
				if (current_moon_name == args.at(0))
				{
					std::cout << "Already orbiting " << current_orbit_moon->getName() << std::endl;
				}
				//if not and is not a nullptr
				else if (moon_manager.getMoon(args.at(0)) != nullptr)
				{
					//checks if the moons price is 0
					if (moon_manager.getMoon(args.at(0))->getPrice() == 0)
					{
						current_orbit_moon = moon_manager.getMoon(args.at(0));
						std::cout << "Now orbiting " << current_orbit_moon->getName() << ". Use the LAND command to land." << std::endl;
					}
					else
					{
						std::cout << "The cost of going to " << moon_manager.getMoon(args.at(0))->getName() << " is  $" << moon_manager.getMoon(args.at(0))->getPrice() << std::endl;
						std::cout << "You have $" << balance << ". Confirm destination? [Yes/No]" << std::endl;
						std::string confirmation;
						std::cout << "> ";
						std::getline(std::cin, confirmation);
						util::lower(confirmation);

						if (confirmation == "no")
						{
							std::cout << "Trip cancelled." << std::endl;
							std::cout << "Still orbiting " << current_orbit_moon->getName() << "." << std::endl;
						}
						else if (confirmation == "yes")
						{
							if (moon_manager.getMoon(args.at(0))->getPrice() > balance)
							{
								std::cout << "You don't have enough funds to route to this moon." << std::endl;
							}
							else
							{
								moon_manager.getMoon(args.at(0))->onNavigate(*this);
								current_orbit_moon = moon_manager.getMoon(args.at(0));
								std::cout << "Now orbiting " << current_orbit_moon->getName() << ". Use the LAND command to land." << std::endl;
							}
						}
						else
						{
							std::cout << "Bad command; the syntax is : " << "\"yes\"" << " or " << "\"no\"" << std::endl;
						}

					}
				}
				//if is a nullptr
				else
				{
					std::cout << "Unknown moon " << "\"" << args.at(0) << "\"." << std::endl;
				}
			}
		}
		inOrbit();

	}
	//handle store input
	else if (user_input == "store" || user_input == "buy")
	{
		if (user_input == "store")
		{
			item_manager.store();
			std::cout << "balance: $" << balance << std::endl;
		}
		else if (user_input == "buy")
		{
			if (args.size() > 1)
			{
				std::cout << "Bad command; the syntax is : " << "\"buy itemName\"" << std::endl;
			}
			else
			{
				if (balance >= item_manager.getItemPrice(args.at(0)))
				{
					item_manager.buy(args.at(0), *this);
				}
				else
				{
					std::cout << "You don't have enough funds to buy this item." << std::endl;
				}
			}
		}
		inOrbit();
	}
	else if (user_input == "inventory")
	{
		item_manager.inventory();
		std::cout << "Balance: $" << balance << " (quota is $" << quota << ")" << std::endl;
		std::cout << "Cargo value: $" << current_cargo_value << std::endl;
		inOrbit();
	}
	else if (user_input == "land")
	{
		landedMoon();
	}
	else if (user_input == "exit")
	{
		endGame();
	}
	else
	{
		std::cout << "Unknown command." << std::endl;
		inOrbit();
	}
}

void Game::landedMoon()
{
	//keeps while loop running until player enters leave command
	bool leave = false;

	std::cout << std::endl;
	std::cout << "WELCOME TO " << current_orbit_moon->getName() << "!" << std::endl;
	std::cout << std::endl;
	std::cout << "Current cargo value: $" << current_cargo_value << std::endl;
	std::cout << "Current balance: $" << balance << std::endl;
	std::cout << "Current quota: $" << quota << " (" << current_day << " days left to meet quota)" << std::endl;
	std::cout << "Number of employees: " << current_alive_crew << std::endl;

	//if not clear
	if (current_orbit_moon->getWeatherCondition() != "")
	{
		std::cout << "Proceed with caution as the moon is currently " << current_orbit_moon->getWeatherCondition() << std::endl;
	}
	
	//tutorial for corporation moon
	if (current_orbit_moon->getName() == "Corporation")
	{
		std::cout << "Type SELL to sell your cargo contents and increase your balance and achieve quota." << std::endl;
		std::cout << "Specify the amount to sell after the SELL word to only sell a portion of your cargo." << std::endl;
	}
	//tutorial for all other moons
	else
	{
		std::cout << "Type SEND followed by the number of employees you wish to send inside the facility. All the other employees will stay on the ship." << std::endl;
	}
	std::cout << "Type LEAVE to leave the planet." << std::endl;
	
	while (leave == false)
	{
		if (current_alive_crew == 0)
		{
			leave = true;
			newDay();
		}

		std::cout << std::endl;
		std::string user_input;
		std::cout << "> ";
		std::getline(std::cin, user_input);
		util::lower(user_input);
		std::vector<std::string> args;
		util::splitArguments(user_input, args);
		std::cout << std::endl;

		
		if (user_input == "send")
		{
			if (args.size() > 1)
			{
				std::cout << "Bad command; the syntax is : " << "\"send numberOfEmployees\"" << std::endl;
			}
			else
			{
				//check to ensure that the args is a valid integer
				try {
					//check to make sure atleast one employee is sent
					if (std::stoi(args.at(0)) < 1)
					{
						std::cout << "At least one employee must be sent." << std::endl;
					}
					else if (std::stoi(args.at(0)) > current_alive_crew)
					{
						std::cout << "Only " << current_alive_crew << " employees are left." << std::endl;
					}
					else
					{
						current_orbit_moon->sendEmployees(*this, std::stoi(args.at(0)));
					}
				}
				catch (const std::invalid_argument e)
				{
					std::cout << "Invalid employee count " << "\"" << args.at(0) << "\"" << std::endl;
				}
			}
		}
		else if (user_input == "sell")
		{
			if (args.size() > 1)
			{
				std::cout << "Bad command; the syntax is : " << "\"sell optionalAmount\"" << std::endl;
			}
			else
			{
				//check to ensure int is valid
				try
				{
					if (std::stoi(args.at(0)) < 1)
					{
						std::cout << "Nothing to sell." << std::endl;
					}
					else if (std::stoi(args.at(0)) > current_cargo_value)
					{
						std::cout << "Only $" << current_cargo_value << " available in cargo." << std::endl;
					}
					else
					{
						current_orbit_moon->sellCargo(*this, std::stoi(args.at(0)));
					}
				}
				catch (const std::invalid_argument e)
				{
					std::cout << "Invalid amount " << "\"" << args.at(0) << "\"" << std::endl;
				}
			}
		}

		else if (user_input == "leave")
		{
			leave = true;
		}
		else
		{
			std::cout << "Unknown command." << std::endl;
		}
	}
	std::cout << std::endl;

	newDay();
}

//defines the items and adds them to the hashmap
void Game::defineItems()
{
	//creates the flashlight object and then calls itemManager
	Flashlight* flashlight = new Flashlight();
	item_manager.registerItem(flashlight);

	Shovel* shovel = new Shovel();
	item_manager.registerItem(shovel);

	ProFlashlight* proFlashlight = new ProFlashlight();
	item_manager.registerItem(proFlashlight);

	Teleporter* teleporter = new Teleporter();
	item_manager.registerItem(teleporter);

	InverseTeleporter* inverseTeleporter = new InverseTeleporter();
	item_manager.registerItem(inverseTeleporter);

	Backpack* backpack = new Backpack();
	item_manager.registerItem(backpack);

	HydraulicsMK2* hydraulicsMK2 = new HydraulicsMK2();
	item_manager.registerItem(hydraulicsMK2);
}

//defines the moon and adds them to the hashmap
void Game::defineMoons()
{
	Corporation* corporation = new Corporation();
	moon_manager.registerMoon(corporation);

	Prototyping* prototyping = new Prototyping();
	moon_manager.registerMoon(prototyping);

	Insurance* insurance = new Insurance();
	moon_manager.registerMoon(insurance);

	Pledge* pledge = new Pledge();
	moon_manager.registerMoon(pledge);

	Defence* defence = new Defence();
	moon_manager.registerMoon(defence);

	April* april = new April();
	moon_manager.registerMoon(april);

	Tore* tore = new Tore();
	moon_manager.registerMoon(tore);

	Hyperion* hyperion = new Hyperion();
	moon_manager.registerMoon(hyperion);
}

float Game::applyItemManagerMulti(float parameter_chance, std::string parameter_name)
{
	return item_manager.applyMulti(parameter_chance, parameter_name);
}

//used for generating a number that AbstractMoon can use
//default values for calling to get typical percentage chance
float Game::generateNum(float min, float max)
{
	//instance of random num generator is instantiated
	std::mt19937 num_generator(std::random_device{}());
	//std::uniform_int_distribution<int> dist(min, max);
	std::uniform_real_distribution<float> dist(min, max);
	return dist(num_generator);
}

void Game::decreaseAliveCrew()
{
	current_alive_crew--;
}

int Game::currentAliveCrew()
{
	return current_alive_crew;
}

void Game::increaseCargoValue(int scrap)
{
	current_cargo_value = current_cargo_value + scrap;
}

void Game::increaseBalance(int value)
{
	std::cout << "Your service is invaluable to the corporation." << std::endl;
	balance = balance + value;
	std::cout << "New balance: $" << balance << " (quota is $" << quota << ")" << std::endl;
	current_cargo_value = current_cargo_value - value;
	std::cout << "New cargo value: $" << current_cargo_value << std::endl;
}

void Game::decreaseBalance(int value)
{
	balance = balance - value;
	std::cout << "Your balance is now $" << balance << std::endl;
}

void Game::allEmployeesDead()
{
	current_cargo_value = 0;
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	std::cout << "All the employees died and the scrap is lost.";
	std::cout << "Autopilot will now bring the ship back to orbit.";
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
}

//ends the game
void Game::endGame()
{
	//for loop here to delete the items and moons
	item_manager.deleteItems();
	moon_manager.deleteMoons();
	std::exit(EXIT_SUCCESS);
}

