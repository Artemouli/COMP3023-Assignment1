#ifndef TORE
#define TORE
#include "AbstractMoon.h"

class Tore : public AbstractMoon
{
public:
	Tore(std::string new_name = "Tore", float new_survival_chance = 0.25f, int min = 100, int max = 130, int cost = 700); //default arguments
};

#endif
