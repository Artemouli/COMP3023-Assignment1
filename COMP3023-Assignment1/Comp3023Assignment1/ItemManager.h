#include <unordered_map>
#include <map>
#include <iostream>
#include <memory>

#include "AbstractItem.h"
#include "util.h"

#ifndef ITEMMANAGER
#define ITEMMANAGER

class ItemManager {
public:
	//registers the item by adding it to the map
	void registerItem(AbstractItem* new_item);

	void inventory();

	void store();

	//gets the price of the item
	int getItemPrice(std::string item_name);

	//handles setting the bought and setting the multipliers
	void buy(std::string buy_item_name);

	//is called by the end game function to free up memory
	void deleteItems();
	
	//apply multi
	//takes in the current chance and the parameter that is being affected, multiplies the chance by the parameter multipliers
	float applyMulti(float parameter_chance, std::string parameter_name);

private: 
	//keeps track of the items
	std::map<std::string, AbstractItem*> items;

	//affected parameters:
	//scrap value multiplier: value
	//explorer survival chance multiplier: explorer
	//operator survival chance multiplier: operator
	//explorer save chance: save
	//loot recovery multiplier: loot

	//system_multiplers < multiplier name, multipler>
	//e.g. system_multipliers < value, 1.10 >
	//system_multipliers < value, 1.05 >
	//both values multiply the specific multiplier
	std::unordered_multimap<std::string, float> system_multipliers;
};

#endif