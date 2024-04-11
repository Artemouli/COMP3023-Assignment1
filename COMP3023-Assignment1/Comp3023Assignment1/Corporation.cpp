#include "Corporation.h"
#include "AbstractMoon.h"
#include "Game.h"

#include <iostream>
#include <memory>

Corporation::Corporation(std::string new_name, float new_survival_chance, int min, int max) : AbstractMoon(new_name, new_survival_chance, min, max)
{

}

//ensures that corporation is always clear
void Corporation::onDayBegins(Game& game)
{
	auto weather_condition = WeatherCondition::Clear;
}

void Corporation::sendEmployees(Game& game, int employee_count)
{
	std::cout << "This command is not available on this moon." << std::endl;
}

void Corporation::sellCargo(Game& game, int amount)
{
	game.increaseBalance(amount);
}