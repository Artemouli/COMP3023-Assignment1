#include "Shovel.h"
#include "AbstractItem.h"

#include <iostream>
#include <memory>

Shovel::Shovel(std::string newName, int newPrice) : AbstractItem(newName, newPrice)
{
	//Multi* scrap_value_multi = new Multi("explorer", 1.05f);
	//creates the explorer multiplier
	system_multiplier.insert(std::make_pair("explorer", 1.05f));
}
