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
	std::cout << "Item could not be found" << std::endl;
}

std::unordered_multimap<std::string, float> ItemManager::GetMulti()
{
	return system_multipliers;
}