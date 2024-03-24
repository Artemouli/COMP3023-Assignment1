#include "Flashlight.h"
#include <iostream>
#include "AbstractItem.h"

Flashlight::FlashLight(std::string newName, int newPrice) : AbstractItem(newName, newPrice)
{
	Multi scrap_value_multi("explorer", 1.05);
	system_multiplier.push_back(*scrap_value_multi);
}