
#include "AbstractMoon.h"

#ifndef MOONMANAGER
#define MOONMANAGER

class MoonManager {
public:
	void RegisterMoon(AbstractMoon* newMoon);

	void ViewMoons();

private:
	//keeps track of the moons
	std::map<std::string, AbstractMoon*> moons;
};

#endif 