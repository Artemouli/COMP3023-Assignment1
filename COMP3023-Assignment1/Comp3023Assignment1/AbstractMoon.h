#include <iostream>
class Game;


#ifndef ABSTRACT_MOON
#define ABSTRACT_MOON


class AbstractMoon {
public:
	AbstractMoon(std::string new_name, float new_survival_chance, int min, int max) :
		moon_name(new_name),
		base_explorer_survival_chance(new_survival_chance),
		min_scrap(min),
		max_scrap(max) {}

	virtual const std::string GetName() const {
		return moon_name;
	}

	//this is for moons that have a cost
	//checks if the user is sure to route to a moon with a price
	virtual void OnNavigate(Game& game) const = 0;

	//Weather condition enum
	enum class WeatherCondition {
		Clear = 0, //no effect
		Flooded, //multiply explorer survival chance by 0.7
		Eclipsed, //multiply explorer survival chance by 0.9 and operator survival chance by 0.7
		Stormy //multiply scrap value multiplier by 0.75
	};

	//takes in a random number to decide the weather condition
	//random number should be between 0 and 100 to reflect percentage change %
	virtual void ChooseWeatherCondition(int ranNum);
	
	//returns the current weather condition as a string for printing
	virtual std::string GetWeatherCondition() const 
	{
		switch (weather_condition)
		{
			case WeatherCondition::Flooded:
				return " (Flooded)";
				break;
			case WeatherCondition::Stormy:
				return " (Stormy)";
				break;
			case WeatherCondition::Eclipsed:
				return " (Eclipsed)";
				break;
			default:
				return "";
				break;
		}
	};

	//this only works on explorable moons
	//employee count must be over 1 and under the amount of alive employees
	//calculations for survival are done here
	virtual void SendEmployees(Game& game, int employee_count) = 0;

	//this only works on corporation moon
	//this method is overridden by the corporation moon
	virtual void SellCargo(Game& game, int amount) const = 0;
	
	virtual void OnDayBegins(Game& game);

	//intended to be overridden by moons which do have a price
	virtual int GetPrice() const = 0
	{
		return 0;
	};


private:
	std::string moon_name;
	float base_explorer_survival_chance;
	float loot_recov_chance = 0.5f;
	int min_scrap;
	int max_scrap;
	WeatherCondition weather_condition;
};

#endif