#include "Pledge.h"
#include "AbstractMoon.h"

#include <iostream>
#include <memory>

Pledge::Pledge(std::string new_name, float new_survival_chance, int min, int max, int cost) : AbstractMoon(new_name, new_survival_chance, min, max, cost)
{
}