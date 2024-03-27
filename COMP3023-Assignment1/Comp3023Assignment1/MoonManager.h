
#include "AbstractMoon.h"
#include <map>

#ifndef MOONMANAGER
#define MOONMANAGER

class MoonManager {
public:
	void RegisterMoon(AbstractMoon* newMoon);

	void ViewMoons();

	void DeleteMoons();

private:
	//keeps track of the moons
	std::map<std::string, AbstractMoon*> moons;
};

#endif 