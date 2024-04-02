#include "Corporation.h"
#include "AbstractMoon.h"
#include "Game.h"

#include <iostream>
#include <memory>

Corporation::Corporation(std::string new_name, float new_survival_chance, int min, int max) : AbstractMoon(new_name, new_survival_chance, min, max)
{

}

//ensures that corporation is always clear
void Corporation::OnDayBegins(Game& game)
{
	ChooseWeatherCondition(0);
}

void Corporation::SendEmployees(Game& game, int employee_count)
{
	std::cout << "This command is not available on this moon." << std::endl;
}

void Corporation::SellCargo(Game& game, int amount)
{
	game.IncreaseBalance(amount);
}