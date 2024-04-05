#include <unordered_map>
#include <map>
#include <iostream>
#include <memory>

#include "ItemManager.h"
#include "util.h"

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

void ItemManager::Inventory()
{
	//this variable is used to check if there is atleast 1 item bought
	bool itemBought = false;
	std::cout << "The following items are available." << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << std::endl;
	for (const auto& pair : items)
	{
		if (pair.second->GetBought() == true)
		{
			itemBought = true;
			std::cout << "* ";
			std::cout << pair.second->GetName();
		}
	}
	//if no items have been bought
	if (itemBought == false)
	{
		std::cout << "(Empty)" << std::endl;
	}
}

void ItemManager::RegisterItem(AbstractItem* new_item)
{
	std::string temp_name = new_item->GetName();
	util::lower(temp_name);
	items.insert({temp_name, new_item});
}

void ItemManager::DeleteItems()
{
	for (const auto& pair : items)
	{
		delete pair.second;
	}
}

int ItemManager::getItemPrice(std::string item_name)
{
	if (items.count(item_name) > 0)
	{
		return items.at(item_name)->GetPrice();
	}
}

void ItemManager::Buy(std::string buy_item_name)
{
	//prevents crashing
	if (items.count(buy_item_name) > 0)
	{
		if (items.at(buy_item_name)->GetBought() == true)
		{
			std::cout << "You already own a " << items.at(buy_item_name)->GetName() << "." << std::endl;
		}
		else
		{
			items.at(buy_item_name)->IsBought();
			std::cout << "Successfully bought " << items.at(buy_item_name)->GetName() << "." << std::endl;
		}
	}
	else
	{
		std::cout << "Unknown item " << "\"" << buy_item_name << "\"" << "." << std::endl;
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