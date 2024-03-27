#include "AbstractMoon.h"





void AbstractMoon::ChooseWeatherCondition(int ranNum)
{
	//clear weather
	if (ranNum < 25)
	{
		weather_condition = Clear;
	}
	//flooded weather
	else if (ranNum > 25 && ranNum < 50)
	{
		weather_condition = Flooded;
	}
	//Eclipsed
	else if (ranNum > 50 && ranNum < 75)
	{
		weather_condition = Eclipsed;
	}
	//Stormy
	else
	{
		weather_condition = Stormy;
	}
}
