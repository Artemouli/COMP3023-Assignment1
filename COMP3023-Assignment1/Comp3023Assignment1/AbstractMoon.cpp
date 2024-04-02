#include "AbstractMoon.h"
#include "Game.h"

#include <iostream>

void AbstractMoon::ChooseWeatherCondition(float ranNum)
{

	//clear weather
	if (ranNum <= 0.25f)
	{
		weather_condition = AbstractMoon::WeatherCondition::Clear;
	}
	//flooded weather
	else if (ranNum > 0.25f && ranNum <= 0.50f)
	{
		weather_condition = AbstractMoon::WeatherCondition::Flooded;
	}
	//Eclipsed
	else if (ranNum > 0.50f && ranNum <= 0.75f)
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
	ChooseWeatherCondition(game.GenerateNum());
}

void AbstractMoon::SendEmployees(Game& game, int employee_count)
{
	if (employee_count > 0)
	{
		//keeps track of the number of exploring employees
		int alive_exploring = employee_count;
		//keeps track of the number of employees who have died 
		int dead_employees = 0;
		//keeps track of the total scrap collected in the day
		int total_scrap = 0;


		float temp_explorer_survival_chance = base_explorer_survival_chance;
		float temp_operator_survival_chance = 1;
		//is temporaly a float for multiplications
		//scrap value will be converted to int when calculated
		float temp_min_scrap = static_cast<float>(min_scrap);
		float temp_max_scrap = static_cast<float>(max_scrap);

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
		for (int i = 1; i < employee_count; i++)
		{
			//collected scrap
			int collected_scrap = static_cast<int>(game.GenerateNum(temp_min_scrap, temp_max_scrap));
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
					alive_exploring--;
					dead_employees++;
					//if there are still employees that are alive exploring
					//those employees will collect the dead employees collected scrap
					if (alive_exploring > 0)
					{
						collected_scrap = collected_scrap * temp_loot_recov;
					}
				}
			}
			//check to see if the operator is killed
			if (game.GenerateNum() > temp_operator_survival_chance)
			{
				game.DecreaseAliveCrew();
			}
			
			game.IncreaseCargoValue(collected_scrap);
			total_scrap += collected_scrap;
		}
		if (alive_exploring > 0)
		{
			std::cout << alive_exploring << " employees made it back to the ship, bringing $";
			std::cout << total_scrap << " worth of scrap. " << dead_employees << " died." << std::endl;
		}
		//if all the exploring employees have died
		else if (alive_exploring == 0)
		{
			std::cout << "None of the employees managed to make it back. " << game.CurrentAliveCrew() << " employees left." << std::endl;

			if (game.CurrentAliveCrew() == 0)
			{
				game.AllEmployeesDead();
			}
		}
	}
	else
	{
		std::cout << "At least one employee must be sent." << std::endl;
	}
}
