#include "Teleporter.h"
#include "AbstractItem.h"

#include <iostream>
#include <memory>

Teleporter::Teleporter(std::string newName, int newPrice) : AbstractItem(newName, newPrice)
{
	//Multi* scrap_value_multi = new Multi("explorer", 1.05f);
	//creates the explorer multiplier
	system_multiplier.insert(std::make_pair("save", 1.05f));
}
