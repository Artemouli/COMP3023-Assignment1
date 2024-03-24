#include "Flashlight.h"
#include "AbstractItem.h"

#include <iostream>
#include <memory>

Flashlight::Flashlight(std::string newName, int newPrice) : AbstractItem(newName, newPrice)
{
	//Multi* scrap_value_multi = new Multi("explorer", 1.05f);
	//creates the explorer multiplier
	system_multiplier.push_back(std::make_unique<Multi>("explorer", 1.05f));
}
