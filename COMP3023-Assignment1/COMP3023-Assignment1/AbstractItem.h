#pragma once
#ifndef ABSTRACTITEM
#define ABSTRACTITEM

//interface for the items

class AbstractItem {
public:
	AbstractItem();
	virtual ~AbstractItem();
	virtual int getPrice() const = 0;
};