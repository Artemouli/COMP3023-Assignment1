#include <unordered_map>
#include <map>
#include <iostream>
#include <memory>

#include "AbstractItem.h"

#ifndef ITEMMANAGER
#define ITEMMANAGER

class ItemManager {
public:
	//registers the item by adding it to the map
	void RegisterItem(AbstractItem* new_item);

	void Inventory();

	void Store();

	void Buy(std::string buy_item_name);

	//is called by the end game function to free up memory
	void DeleteItems();
	//apply multi

	//add multi

private: 
	//keeps track of the items
	std::map<std::string, AbstractItem*> items;

	//affected parameters:
	//scrap value multiplier: value
	//explorer survival chance multiplier: explorer
	//operator survival chance multiplier: operator
	//explorer save chance: save
	//loot recovery multiplier: loot_recov

	//system_multiplers < multiplier name, multipler>
	//e.g. system_multipliers < value, 1.10 >
	//system_multipliers < value, 1.05 >
	//both values multiply the specific multiplier
	std::unordered_multimap<std::string, float> system_multipliers;
};

#endif