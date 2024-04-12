#ifndef HYPERION
#define HYPERION
#include "AbstractMoon.h"

class Hyperion : public AbstractMoon
{
public:
	Hyperion(std::string new_name = "Hyperion", float new_survival_chance = 0.20f, int min = 100, int max = 150, int cost = 900); //default arguments
};

#endif
