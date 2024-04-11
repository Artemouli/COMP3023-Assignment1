#ifndef TELEPORTER
#define TELEPORTER
#include "AbstractItem.h"

class Teleporter : public AbstractItem
{
public:
	Teleporter(std::string newName = "Teleporter", int newPrice = 300); //default arguments
};

#endif