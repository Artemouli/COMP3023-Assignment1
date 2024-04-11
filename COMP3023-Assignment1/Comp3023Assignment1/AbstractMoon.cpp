#include "AbstractMoon.h"
#include "Game.h"

#include <iostream>


void AbstractMoon::onDayBegins(Game& game)
{
	//generateNum will only be able to generate a number between 0 and the maximum value (which is count)
	auto weather_conditon = static_cast<WeatherCondition>(game.generateNum(0, static_cast<int>(WeatherCondition::Count)));
}

void AbstractMoon::onNavigate(Game& game)
{
	game.decreaseBalance(travel_cost);
}

void AbstractMoon::sendEmployees(Game& game, int employee_count)
{
	if (employee_count > 0)
	{
		//value that keeps track of the precision required for the system calculations
		//e.g. explorer death
		const float epsilon = 1e-3;

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
		temp_min_scrap = game.applyItemManagerMulti(temp_min_scrap, "value");
		temp_max_scrap = game.applyItemManagerMulti(temp_max_scrap, "value");
		//applies explorer
		temp_explorer_survival_chance = game.applyItemManagerMulti(temp_explorer_survival_chance, "explorer");
		//applies operator
		temp_operator_survival_chance = game.applyItemManagerMulti(temp_operator_survival_chance, "operator");
		//save chance
		explorer_save_chance = game.applyItemManagerMulti(explorer_save_chance, "save");
		//loot recov
		temp_loot_recov = game.applyItemManagerMulti(temp_loot_recov, "loot");


		//if there is an operator
		if (employee_count != game.currentAliveCrew())
		{
			//check to see if the operator is killed
			if (abs(game.generateNum() > temp_operator_survival_chance) > epsilon)
			{
				game.decreaseAliveCrew();
				dead_employees++;
			}
		}
	
		//system parameter calculations 
		for (int i = 1; i <= employee_count; i++)
		{
			//collected scrap
			int collected_scrap = static_cast<int>(game.generateNum(temp_min_scrap, temp_max_scrap));
			//if explorer died 
			//abs is used because of how low the floating point is 
			if (abs(game.generateNum() < temp_explorer_survival_chance)  < epsilon)
			{
				//if explorer is saved
				if (game.generateNum() < explorer_save_chance)
				{
					//drop collected scrap
					collected_scrap = 0;
				}
				//if explorer isnt saved
				else
				{
					game.decreaseAliveCrew();
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
			game.increaseCargoValue(collected_scrap);
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
			std::cout << "None of the employees managed to make it back. " << game.currentAliveCrew() << " employees left." << std::endl;

			if (game.currentAliveCrew() == 0)
			{
				game.allEmployeesDead();
			}
		}
	}
	else
	{
		std::cout << "At least one employee must be sent." << std::endl;
	}
}
