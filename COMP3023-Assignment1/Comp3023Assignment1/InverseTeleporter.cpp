#include "InverseTeleporter.h"
#include "AbstractItem.h"

#include <iostream>
#include <memory>

InverseTeleporter::InverseTeleporter(std::string newName, int newPrice) : AbstractItem(newName, newPrice)
{
	//Multi* scrap_value_multi = new Multi("explorer", 1.05f);
	//creates the explorer multiplier
	system_multiplier.insert(std::make_pair("explorer", 0.8f));
	system_multiplier.insert(std::make_pair("value", 1.10f));
}
