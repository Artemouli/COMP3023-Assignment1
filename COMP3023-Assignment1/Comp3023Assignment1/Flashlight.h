#ifndef FLASHLIGHT
#define FLASHLIGHT
#include "AbstractItem.h"

class Flashlight : public AbstractItem
{
public:
	Flashlight(std::string newName = "flashlight", int newPrice = 60); //default arguments
};

#endif