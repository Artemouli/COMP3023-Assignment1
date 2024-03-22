#include <iostream>
#include <map>
#include <vector>

#ifndef ABSTRACTITEM
#define ABSTRACTITEM



//interface for the items
class AbstractItem {
public:
	//constructor
	//for each item cpp file, the item will initialise the Multi's it needs inside its constructor
	AbstractItem(std::string newName, int newPrice) : name(newName), price(newPrice) {}
	
	virtual std::string getName() const {
		return name;
	};

	virtual int getPrice() const {
		return price;
	};
	virtual bool getBought() const {
		return bought;
	};
	//sets the item to bought
	virtual void isBought() {
		bought = true;
	};

	//THIS IS NO LONGER NEEDED
	//this is called by the initaliser to add the system multipliers to the item
	/*virtual void addMulti(Multi* multi) const = {
		system_multiplier.push_back(multi);
	};*/

	virtual Multi* getMulti(std::string parameter_name) const {
		//TODO
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
	std::vector <Multi*> system_multiplier;
};

#endif //ABSTRACTITEM