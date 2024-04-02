#include "AbstractMoon.h"
#include "Game.h"

#include <iostream>

void AbstractMoon::ChooseWeatherCondition(int ranNum)
{
	//clear weather
	if (ranNum < 25)
	{
		weather_condition = AbstractMoon::WeatherCondition::Clear;
	}
	//flooded weather
	else if (ranNum > 25 && ranNum < 50)
	{
		weather_condition = AbstractMoon::WeatherCondition::Flooded;
	}
	//Eclipsed
	else if (ranNum > 50 && ranNum < 75)
	{
		weather_condition = AbstractMoon::WeatherCondition::Eclipsed;
	}
	//Stormy
	else
	{
		weather_condition = AbstractMoon::WeatherCondition::Stormy;
	}
}

void AbstractMoon::OnDayBegins(Game& game)
{
	std::cout << "empty" << std::endl;
}

void AbstractMoon::SendEmployees(Game& game, int employee_count)
{
	if (employee_count > 0)
	{
		float temp_explorer_survival_chance = base_explorer_survival_chance;
		float temp_operator_survival_chance = 100;
		//is temporaly a float for multiplications
		//scrap value will be converted to int when calculated
		float temp_min_scrap = min_scrap;
		float temp_max_scrap = max_scrap;

		float explorer_save_chance = 0;

		float temp_loot_recov = loot_recov_chance;

		//applies weather condition 
		switch (weather_condition) 
		{
			case WeatherCondition::Flooded:
				temp_explorer_survival_chance = temp_explorer_survival_chance * 0.7;
				break;
			case WeatherCondition::Stormy:
				//converts the float back into an int
				temp_min_scrap = temp_min_scrap * 0.75;
				temp_max_scrap = temp_max_scrap * 0.75;
				break;
			case WeatherCondition::Eclipsed:
				temp_explorer_survival_chance = temp_explorer_survival_chance * 0.7;
				temp_operator_survival_chance = temp_operator_survival_chance * 0.9;
				break;
		}

		//affected parameters:
		//scrap value multiplier: value
		//explorer survival chance multiplier: explorer
		//operator survival chance multiplier: operator
		//explorer save chance: save
		//loot recovery multiplier: loot

		//applies multi
		temp_min_scrap = game.ApplyItemManagerMulti(temp_min_scrap, "value");
		temp_max_scrap = game.ApplyItemManagerMulti(temp_max_scrap, "value");
		//applies explorer
		temp_explorer_survival_chance = game.ApplyItemManagerMulti(temp_explorer_survival_chance, "explorer");
		//applies operator
		temp_operator_survival_chance = game.ApplyItemManagerMulti(temp_operator_survival_chance, "operator");
		//save chance
		explorer_save_chance = game.ApplyItemManagerMulti(explorer_save_chance, "save");
		//loot recov
		temp_loot_recov = game.ApplyItemManagerMulti(temp_loot_recov, "loot");

		//system parameter calculations 
		for (int i = 0; i < employee_count; i++)
		{
			//collected scrap
			int collected_scrap = game.GenerateNum(static_cast<int>(temp_min_scrap), static_cast<int>(temp_max_scrap));
			//if explorer died 
			if (game.GenerateNum() > temp_explorer_survival_chance)
			{
				//if explorer is saved
				if (game.GenerateNum() < explorer_save_chance)
				{
					//drop collected scrap
					collected_scrap = 0;
				}
				//if explorer isnt saved
				else
				{
					game.DecreaseAliveCrew();
				}

			}
		}
	}
	else
	{
		std::cout << "At least one employee must be sent." << std::endl;
	}
}