#ifndef PROTOTYPING
#define PROTOTYPING
#include "AbstractMoon.h"

class Prototyping : public AbstractMoon
{
public:
	Prototyping(std::string new_name = "Prototyping", float new_survival_chance = 0.50f, int min = 3, int max = 30); //default arguments
};

#endif
