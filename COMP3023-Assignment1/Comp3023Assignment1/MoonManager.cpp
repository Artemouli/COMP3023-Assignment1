
#include "MoonManager.h"

void MoonManager::RegisterMoon(AbstractMoon* newMoon)
{
	moons.insert({ newMoon->GetName(), newMoon });
}

void MoonManager::ViewMoons()
{

}

void MoonManager::DeleteMoons()
{

}