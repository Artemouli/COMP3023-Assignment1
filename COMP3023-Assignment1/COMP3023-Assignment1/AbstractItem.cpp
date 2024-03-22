#include "AbstractItem.h"

AbstractItem::AbstractItem(std::string newName, const int newPrice) : //constructor definition
	name(newName),
	price(newPrice)  
{
}

AbstractItem::~AbstractItem() {}

//this is now in Multi
/*void AbstractItem::ApplyMulti(std::multimap <std::string, float>& rBought_items) const
{
	rBought_items.insert({name, })
}; */