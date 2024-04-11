#include "AbstractMoon.h"
#include "util.h"
//game is only inherited so it can be passed into abstract moon
class Game;

#include <map>

#ifndef MOONMANAGER
#define MOONMANAGER

class MoonManager {
public:
	void registerMoon(AbstractMoon* newMoon);

	void viewMoons();

	void deleteMoons();

	AbstractMoon* getMoon(std::string moon_name);

	void newDay(Game& game);


private:
	//keeps track of the moons
	std::map<std::string, AbstractMoon*> moons;
	//keeps track of insertion order
	std::vector<std::string> insertion_order;
};

#endif 