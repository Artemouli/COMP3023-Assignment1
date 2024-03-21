#include <iostream>
#include <map>

#ifndef ABSTRACTITEM
#define ABSTRACTITEM



//interface for the items
class AbstractItem {
public:
	//constructor
	AbstractItem(const std::string& newName, const int newPrice) : name(newName), price(newPrice) {}
	
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
	virtual void ApplyMulti(const std::multimap <std::string, float>* bought_items);

private:
	std::string name;
	int price;
	bool bought = false;
};

#endif //ABSTRACTITEM