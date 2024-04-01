#include "MoonManager.h"
#include "AbstractMoon.h"

#include <iostream>

void MoonManager::RegisterMoon(AbstractMoon* newMoon)
{
	moons.insert({ newMoon->GetName(), newMoon });
}

void MoonManager::ViewMoons()
{
	for (const auto& pair : moons)
	{
		std::cout << "* ";
		std::cout << pair.second->GetName();
		std::cout << pair.second->GetWeatherCondition();
		if (pair.second->GetPrice() > 0)
		{
			std::cout << ": " << "$" << pair.second->GetPrice();
		}
		std::cout << std::endl;
	}
}

void MoonManager::DeleteMoons()
{

}