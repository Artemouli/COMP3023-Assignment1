#include <iostream>
#include <map>
#include <vector>

#ifndef ABSTRACTITEM
#define ABSTRACTITEM



//interface for the items
class AbstractItem {
public:
	//constructor
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
	virtual void isBought() {
		bought = true;
	};
	virtual void addMulti(Multi* multi) const {
		system_multiplier.push_back(multi);
	};

	//this is now in Multi
	//virtual void ApplyMulti(std::multimap <std::string, float>& rBought_items) const;

private:
	std::string name;
	int price;
	bool bought = false;
	std::vector <Multi*> system_multiplier;
};

#endif //ABSTRACTITEM