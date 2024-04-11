#include <unordered_map>
#include <map>
#include <iostream>
#include <memory>

#include "ItemManager.h"
#include "util.h"
#include "Game.h"

void ItemManager::store()
{
	std::cout << "Welcome to the Corporation store." << std::endl;
	std::cout << "Use the word BUY on any item." << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << std::endl;
	for (const auto& pair : items)
	{
		std::cout << "* ";
		std::cout << pair.second->getName();
		std::cout << " // ";
		if (pair.second->getBought() == true)
		{
			std::cout << "Bought" << std::endl;
		}
		else
		{
			std::cout << "Price: $" << pair.second->getPrice() << std::endl;
		}
	}
	std::cout << std::endl;
}

void ItemManager::inventory()
{
	//this variable is used to check if there is atleast 1 item bought
	bool itemBought = false;
	std::cout << "The following items are available." << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << std::endl;
	for (const auto& pair : items)
	{
		if (pair.second->getBought() == true)
		{
			itemBought = true;
			std::cout << "* ";
			std::cout << pair.second->getName();
		}
	}
	//if no items have been bought
	if (itemBought == false)
	{
		std::cout << "(Empty)" << std::endl;
	}
}

void ItemManager::registerItem(AbstractItem* new_item)
{
	std::string temp_name = new_item->getName();
	util::lower(temp_name);
	items.insert({temp_name, new_item});
}

void ItemManager::deleteItems()
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
		return items.at(item_name)->getPrice();
	}
}

void ItemManager::buy(std::string buy_item_name, Game& game)
{
	//prevents crashing
	if (items.count(buy_item_name) > 0)
	{
		if (items.at(buy_item_name)->getBought() == true)
		{
			std::cout << "You already own a " << items.at(buy_item_name)->getName() << "." << std::endl;
		}
		else
		{
			items.at(buy_item_name)->isBought();
			game.decreaseBalance(items.at(buy_item_name)->getPrice());
			std::cout << "Successfully bought " << items.at(buy_item_name)->getName() << "." << std::endl;
		}
	}
	else
	{
		std::cout << "Unknown item " << "\"" << buy_item_name << "\"" << "." << std::endl;
	}
}

float ItemManager::applyMulti(float parameter_chance, std::string parameter_name)
{
	for (const auto pair : items)
	{
		//if item is bought
		if (pair.second->getBought() == true)
		{
			//retrieves the multiplier float from the system_multiplier hashmap
			//if the system_multiplier hashmap does not have the parameter_name, returns 1
			//is for setting the save chance
			if (parameter_name == "save")
			{
				parameter_chance = parameter_chance = pair.second->getMulti(parameter_name);
			}
			else
			{
				parameter_chance = parameter_chance * pair.second->getMulti(parameter_name);
			}
		}
	}

	//no parameters exist so return chance
	return parameter_chance;
}