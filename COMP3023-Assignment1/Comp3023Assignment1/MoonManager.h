
#include "AbstractMoon.h"

#ifndef MOONMANAGER
#define MOONMANAGER

class MoonManager {
public:
	void RegisterMoon(AbstractMoon* newMoon);

	void OnDayBegins(Game& game);

	void ViewMoons();

	//this only works on explorable moons
	//employee count must be over 1 and under the amount of alive employees
	void Send(Game& game, int employee_count);

	//this only works on corporation moon
	void Sell(Game& game);

private:
	//keeps track of the moons
	std::map<std::string, AbstractMoon*> moons;
};

#endif 