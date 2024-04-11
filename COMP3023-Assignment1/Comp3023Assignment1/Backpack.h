#ifndef BACKPACK
#define BACKPACK
#include "AbstractItem.h"

class Backpack : public AbstractItem
{
public:
	Backpack(std::string newName = "Backpack", int newPrice = 500); //default arguments
};

#endif