#include <unordered_map>
#include <map>
#include <iostream>
#include <memory>

#include "ItemManager.h"

void ItemManager::Store()
{
	for (const auto& pair : items)
	{
		std::cout << "* ";
		std::cout << pair.second->GetName();
		std::cout << " // ";
		if (pair.second->GetBought() == true)
		{
			std::cout << "Bought" << std::endl;
		}
		else
		{
			std::cout << "Price: $" << pair.second->GetPrice() << std::endl;
		}
	}
}

void ItemManager::RegisterItem(AbstractItem* new_item)
{
	items.insert({new_item->GetName(), new_item});
}

void ItemManager::DeleteItems()
{
	for (const auto& pair : items)
	{
		delete pair.second;
	}
}

void ItemManager::Buy(std::string buy_item_name)
{
	//prevents crashing
	if (items.count(buy_item_name) > 0)
	{
		items.at(buy_item_name)->IsBought();
	}
	else
	{
		std::cout << "Item could not be found" << std::endl;
	}
}

float ItemManager::ApplyMulti(float parameter_chance, std::string parameter_name)
{
	for (const auto pair : items)
	{
		//if item is bought
		if (pair.second->GetBought() == true)
		{
			//retrieves the multiplier float from the system_multiplier hashmap
			//if the system_multiplier hashmap does not have the parameter_name, returns 1
			//is for setting the save chance
			if (parameter_name == "save")
			{
				parameter_chance = parameter_chance = pair.second->GetMulti(parameter_name);
			}
			else
			{
				parameter_chance = parameter_chance * pair.second->GetMulti(parameter_name);
			}
		}
	}

	//no parameters exist so return chance
	return parameter_chance;
}