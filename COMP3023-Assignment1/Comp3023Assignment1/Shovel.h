#ifndef SHOVEL
#define SHOVEL
#include "AbstractItem.h"

class Shovel : public AbstractItem
{
public:
	Shovel(std::string newName = "Shovel", int newPrice = 100); //default arguments
};

#endif