#ifndef INSURANCE
#define INSURANCE
#include "AbstractMoon.h"

class Insurance : public AbstractMoon
{
public:
	Insurance(std::string new_name = "Insurance", float new_survival_chance = 0.45f, int min = 5, int max = 50, int cost = 0); //default arguments
};

#endif
