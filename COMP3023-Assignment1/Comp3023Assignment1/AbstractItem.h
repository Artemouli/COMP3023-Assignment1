#include <iostream>
#include <map>
#include <memory>
#include <vector>

#ifndef ABSTRACT_ITEM
#define ABSTRACT_ITEM



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
	//sets the item to bought while also deleting the allocated memory
	virtual void isBought()  
	{ 
		bought = true;
	};

	//gets the multiplier float
	virtual float getMulti(std::string parameter_name) {
		if (system_multiplier.count(parameter_name))
		{
			return system_multiplier.at(parameter_name);
		}
		//if parameter doesnt exist
		return 1;
	}

	virtual void deleteMulti()
	{
		system_multiplier.clear();
	}

private:
	std::string name;
	int price;
	bool bought = false;

//system_multiplier is made protected so that the objects that inherit AbstractItem can use it
protected:
	//std::vector <Multi*> system_multiplier;
	//std::vector <Multi*> system_multiplier;
	//multi is not needed, a hashmap that contains the two values would be more efficient then having objects
	std::map <std::string, float> system_multiplier;
};

#endif //ABSTRACT_ITEM