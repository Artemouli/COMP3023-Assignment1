#ifndef MULTI
#define MULTI
#include <iostream>


//Interface for the simulation parameter multipliers

//affected parameters:
//value
//explorer
//operator
//save
//loot_recov

class Multi {
public:
	Multi(std::string inputParameter, int newMultiplier) : affected_parameter(inputParameter), multiplier(newMultiplier) {};
	virtual ~Multi();

	virtual std::string GetParameter() const {
		return affected_parameter;
	};

	virtual float GetMultiplier() const {
		return multiplier;
	};
	//virtual void ApplyMulti(std::multimap <std::string, float>& rBought_items ) const;

private: 
	std::string affected_parameter;
	float multiplier;
};

#endif //MULTI