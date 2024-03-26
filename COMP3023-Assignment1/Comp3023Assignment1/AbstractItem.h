#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include "Multi.h"

#ifndef ABSTRACT_ITEM
#define ABSTRACT_ITEM



//interface for the items
class AbstractItem {
public:
	//constructor
	//for each item cpp file, the item will initialise the Multi's it needs inside its constructor
	AbstractItem(std::string newName, int newPrice) : name(newName), price(newPrice) {}
	
	virtual std::string GetName() const {
		return name;
	};

	virtual int GetPrice() const {
		return price;
	};
	virtual bool GetBought() const {
		return bought;
	};
	//sets the item to bought while also deleting the allocated memory
	virtual void IsBought()  
	{ 
		bought = true;
	};

	//gets the multiplier float
	virtual float GetMulti(std::string parameter_name) {
		for (int i = 0; i < system_multiplier.size(); i++)
		{
			if (system_multiplier[i]->getParameter().compare(parameter_name))
			{
				//return the pointer that points to the specific Multi
				return system_multiplier[i]->getMultiplier();
			}
		}
	}

	//adds the multiplier to the bought_items multimap
	//this should be in the Item Manager
	/*virtual void ApplyMulti(std::multimap <std::string, float>& rBought_items) const
	{
		
	}; */

private:
	std::string name;
	int price;
	bool bought = false;

//system_multiplier is made protected so that the objects that inherit AbstractItem can use it
protected:
	//std::vector <Multi*> system_multiplier;
	std::vector <std::unique_ptr<Multi>> system_multiplier;
};

#endif //ABSTRACT_ITEM