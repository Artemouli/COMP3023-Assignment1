#include <iostream>
#include <map>

#ifndef ABSTRACTITEM
#define ABSTRACTITEM



//interface for the items
class AbstractItem {
public:
	//constructor
	AbstractItem(const std::string& newName, const int newPrice) : name(newName), price(newPrice) {}
	int getPrice() const = 0;
	bool getBought() const = 0;
	void setBought() const;
	virtual void ApplyMulti(const std::multimap <std::string, float>* bought_items) const;

private:
	std::string name;
	int price;
	bool bought = false;
};

#endif //ABSTRACTITEM