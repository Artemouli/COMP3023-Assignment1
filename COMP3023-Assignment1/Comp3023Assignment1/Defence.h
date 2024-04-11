#ifndef DEFENCE
#define DEFENCE
#include "AbstractMoon.h"

class Defence : public AbstractMoon
{
public:
	Defence(std::string new_name = "Defence", float new_survival_chance = 0.35f, int min = 10, int max = 70, int cost = 0); //default arguments
};

#endif
