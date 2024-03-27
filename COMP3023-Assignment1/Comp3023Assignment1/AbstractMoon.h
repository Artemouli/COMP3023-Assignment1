#include <iostream>


#ifndef ABSTRACT_MOON
#define ABSTRACT_MOON

class AbstractMoon {
public:
	AbstractMoon(std::string new_name, float new_survival_chance, int min, int max) :
		moon_name(new_name),
		base_survival_chance(new_survival_chance),
		min_scrap(min),
		max_scrap(max) {}

	virtual std::string GetName() const {
		return moon_name;
	}

	//Weather condition enum
	enum class WeatherCondition {
		Clear, //no effect
		Flooded, //multiply explorer survival chance by 0.7
		Eclipsed, //multiply explorer survival chance by 0.9 and operator survival chance by 0.7
		Stormy //multiply scrap value multiplier by 0.75
	};

	//takes in a random number to decide the weather condition
	//random number should be between 0 and 100 to reflect percentage change %
	virtual void ChooseWeatherCondition(int ranNum);
	
	//returns the current weather condition
	virtual WeatherCondition GetWeatherCondition() const 
	{
		return weather_condition;
	};

private:
	std::string moon_name;
	float base_survival_chance;
	int min_scrap;
	int max_scrap;
	WeatherCondition weather_condition;
};

#endif