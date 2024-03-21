
#include <iostream>
#include <map>

#pragma once
#ifndef ABSTRACTITEM
#define ABSTRACTITEM



//interface for the items
class AbstractItem {
public:
	AbstractItem();
	virtual ~AbstractItem();
	virtual int getPrice() const = 0;
	virtual bool getBought() const = 0;
	virtual void setBought() const = 0;
	virtual void ApplyMulti(const std::multimap<std::string, float>* bought_items) const = 0;
};

#endif //ABSTRACTITEM