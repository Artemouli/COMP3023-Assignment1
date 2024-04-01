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

void AbstractMoon::SendEmployees(Game& game, int employee_count)
{
	if (employee_count > 0)
	{
		float temp_explorer_survival_chance = base_explorer_survival_chance;
		float temp_operator_survival_chance = 1;
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
			case WeatherCondition::Eclipsed:
				temp_explorer_survival_chance = temp_explorer_survival_chance * 0.7;
				temp_operator_survival_chance = temp_operator_survival_chance * 0.9;
		}

		//affected parameters:
		//scrap value multiplier: value
		//explorer survival chance multiplier: explorer
		//operator survival chance multiplier: operator
		//explorer save chance: save
		//loot recovery multiplier: loot


		//applies multi
		min_scrap = game.ApplyItemManagerMulti(min_scrap, "value");
		max_scrap = game.ApplyItemManagerMulti(max_scrap, "value");

		//applies explorer
		temp_explorer_survival_chance = game.ApplyItemManagerMulti(temp_explorer_survival_chance, "explorer");

		//applies operator
		temp_operator_survival_chance = game.ApplyItemManagerMulti(temp_operator_survival_chance, "operator");

		//save chance
		explorer_save_chance = game.ApplyItemManagerMulti(explorer_save_chance, "save");

		//loot recov
		temp_loot_recov = game.ApplyItemManagerMulti(temp_loot_recov, "loot");
	}
}