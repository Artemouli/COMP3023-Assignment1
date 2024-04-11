#include "ProFlashlight.h"
#include "AbstractItem.h"

#include <iostream>
#include <memory>

ProFlashlight::ProFlashlight(std::string newName, int newPrice) : AbstractItem(newName, newPrice)
{
	//Multi* scrap_value_multi = new Multi("explorer", 1.05f);
	//creates the explorer multiplier
	system_multiplier.insert(std::make_pair("explorer", 1.10f));
}
