#ifndef INVERSETELEPORTER
#define INVERSETELEPORTER
#include "AbstractItem.h"

class InverseTeleporter : public AbstractItem
{
public:
	InverseTeleporter(std::string newName = "Inverse Teleporter", int newPrice = 400); //default arguments
};

#endif