#ifndef CORPORATION
#define CORPORATION
#include "AbstractMoon.h"
class Game;

class Corporation : public AbstractMoon
{
public:
	Corporation(std::string new_name = "Corporation", float new_survival_chance = 0, int min = 0, int max = 0); //default arguments
	void OnDayBegins(Game& game) override;
	void SendEmployees(Game& game, int employee_count) override;
	void SellCargo(Game& game, int amount) override;
};

#endif
