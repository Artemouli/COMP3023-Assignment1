#ifndef APRIL
#define APRIL
#include "AbstractMoon.h"

class April : public AbstractMoon
{
public:
	April(std::string new_name = "April", float new_survival_chance = 0.30f, int min = 20, int max = 120, int cost = 550); //default arguments
};

#endif
