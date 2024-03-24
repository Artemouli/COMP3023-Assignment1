#include <unordered_map>
#include <map>
#include <iostream>
#include <memory>

#include "ItemManager.h"

void ItemManager::RegisterItem(AbstractItem* new_item)
{
	items.insert({ new_item->getName(), new_item });
}