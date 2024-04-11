#include <iostream>
class Game;


#ifndef ABSTRACT_MOON
#define ABSTRACT_MOON

//Weather condition enum
enum class WeatherCondition {
	Clear = 0, //no effect
	Flooded, //multiply explorer survival chance by 0.7
	Eclipsed, //multiply explorer survival chance by 0.9 and operator survival chance by 0.7
	Stormy, //multiply scrap value multiplier by 0.75
	Count //used to keep track of the maximum value of the enum
};

class AbstractMoon {
public:
	AbstractMoon(std::string new_name, float new_survival_chance, int min, int max, int cost) :
		moon_name(new_name),
		base_explorer_survival_chance(new_survival_chance),
		min_scrap(min),
		max_scrap(max),
		travel_cost(cost),
		weather_condition(WeatherCondition::Clear) {};

	virtual const std::string getName() const {
		return moon_name;
	}

	//returns the current weather condition as a string for printing
	virtual std::string getWeatherCondition() const 
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
	virtual void sendEmployees(Game& game, int employee_count);

	//this only works on corporation moon
	//this method is overridden by the corporation moon
	virtual void sellCargo(Game& game, int amount)
	{
		std::cout << "This command is not available on this moon." << std::endl;
	};
	
	virtual void onDayBegins(Game& game);

	virtual void onNavigate(Game& game);

	//intended to be overridden by moons which do have a price
	virtual int getPrice()
	{
		return travel_cost;
	};

	virtual ~AbstractMoon() {};


private:
	std::string moon_name;
	float base_explorer_survival_chance;
	float loot_recov_chance = 0.5;
	int travel_cost = 0;
	int min_scrap;
	int max_scrap;
	WeatherCondition weather_condition;
};

#endif