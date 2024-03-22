#ifndef MULTI
#define MULTI
#include <iostream>


//Interface for the simulation parameter multipliers

class Multi {
public:
	Multi(std::string inputParameter, int newMultiplier) : affected_parameter(inputParameter), multiplier(newMultiplier) {};
	virtual ~Multi();
	virtual void ApplyMulti(std::multimap <std::string, float>& rBought_items ) const;

private: 
	std::string affected_parameter;
	float multiplier;
};

#endif //MULTI