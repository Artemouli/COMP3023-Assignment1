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

		//add multipliers
		/*std::map<std::string, float>* tempMulti = items.at(buy_item_name)->GetMulti();
		
		for (const auto& pair : *tempMulti)
		{
			system_multipliers.insert(std::make_pair(pair.first, pair.second));
		} */

		//test
		/*for (const auto& pair : system_multipliers)
		{
			std::cout << pair.first << " " << pair.second << std::endl;
		} */
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
			parameter_chance = parameter_chance * pair.second->GetMulti(parameter_name);
		}
	}
	//old code
	/*if (system_multipliers.count(parameter_name) > 0)
	{
		//if parameters do exist
		auto multis = system_multipliers.equal_range(parameter_name);
		for (auto parameter_multi = multis.first; parameter_multi != multis.second; ++parameter_multi)
		{
			//multiplies the parameter chance by the paramter_multi
			parameter_chance = parameter_chance * parameter_multi->second;
		}
		return parameter_chance;
	} */

	//no parameters exist so return chance
	return parameter_chance;
}

/*std::unordered_multimap<std::string, float>* ItemManager::GetMulti()
{
	return &system_multipliers;
}*/