#include "Prototyping.h"
#include "AbstractMoon.h"

#include <iostream>
#include <memory>

Prototyping::Prototyping(std::string new_name, float new_survival_chance, int min, int max) : AbstractMoon(new_name, new_survival_chance, min, max)
{
}

void Prototyping::SellCargo(Game& game, int amount)
{
	std::cout << "cannot sell on this moon" << std::endl;
}