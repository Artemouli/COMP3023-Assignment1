#ifndef PLEDGE
#define PLEDGE
#include "AbstractMoon.h"

class Pledge : public AbstractMoon
{
public:
	Pledge(std::string new_name = "Pledge", float new_survival_chance = 0.40f, int min = 30, int max = 50, int cost = 0); //default arguments
};

#endif
