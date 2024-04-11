#include "Defence.h"
#include "AbstractMoon.h"

#include <iostream>
#include <memory>

Defence::Defence(std::string new_name, float new_survival_chance, int min, int max, int cost) : AbstractMoon(new_name, new_survival_chance, min, max, cost)
{
}