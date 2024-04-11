#include "MoonManager.h"
#include "AbstractMoon.h"
#include "util.h"
#include "Game.h"

#include <iostream>

void MoonManager::registerMoon(AbstractMoon* newMoon)
{
	//temp name is used so that the key is an all lowercase version of the moon name
	std::string temp_name = newMoon->getName();
	//std::cout << temp_name << std::endl;
	util::lower(temp_name);
	moons.insert({ temp_name, newMoon});
	insertion_order.push_back(temp_name);
}

void MoonManager::viewMoons()
{
	for (int i = 0; i < insertion_order.size(); i++)
	{
		std::cout << "* ";
		std::cout << moons.at(insertion_order.at(i))->getName();
		std::cout << moons.at(insertion_order.at(i))->getWeatherCondition();
		if (moons.at(insertion_order.at(i))->getPrice() > 0)
		{
			std::cout << ": " << "$" << moons.at(insertion_order.at(i))->getPrice();
		}
		std::cout << std::endl;
	}
	/*for (const auto& pair : moons)
	{
		std::cout << "* ";
		std::cout << pair.second->getName();
		std::cout << pair.second->getWeatherCondition();
		if (pair.second->getPrice() > 0)
		{
			std::cout << ": " << "$" << pair.second->getPrice();
		}
		std::cout << std::endl;
	}*/
}

void MoonManager::deleteMoons()
{
	moons.clear();
}

AbstractMoon* MoonManager::getMoon(std::string moon_name)
{
	if (moons.count(moon_name) > 0)
	{
		return moons.at(moon_name);
	}
	//if the moon_name does not exist
	else
	{
		return nullptr;
	}
}

void MoonManager::newDay(Game& game)
{
	for (const auto& pair : moons)
	{
		pair.second->onDayBegins(game);
	}
}