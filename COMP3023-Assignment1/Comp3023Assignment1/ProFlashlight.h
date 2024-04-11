#ifndef PROFLASHLIGHT
#define PROFLASHLIGHT
#include "AbstractItem.h"

class ProFlashlight : public AbstractItem
{
public:
	ProFlashlight(std::string newName = "Pro-Flashlight", int newPrice = 200); //default arguments
};

#endif