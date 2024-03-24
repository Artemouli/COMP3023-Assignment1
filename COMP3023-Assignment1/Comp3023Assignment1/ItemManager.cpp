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
		std::cout << pair.second->getName();
		std::cout << " // ";
		std::cout << "Price: $" << pair.second->getPrice() << std::endl;
	}
}

void ItemManager::RegisterItem(AbstractItem* new_item)
{
	items.insert({new_item->getName(), new_item});
}