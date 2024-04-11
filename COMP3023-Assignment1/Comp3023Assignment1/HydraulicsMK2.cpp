#include "HydraulicsMK2.h"
#include "AbstractItem.h"

#include <iostream>
#include <memory>

HydraulicsMK2::HydraulicsMK2(std::string newName, int newPrice) : AbstractItem(newName, newPrice)
{
	//Multi* scrap_value_multi = new Multi("explorer", 1.05f);
	//creates the explorer multiplier
	system_multiplier.insert(std::make_pair("operator", 1.25f));
}
