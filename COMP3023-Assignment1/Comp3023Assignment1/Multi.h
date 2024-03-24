#ifndef MULTI
#define MULTI
#include <iostream>


//Interface for the simulation parameter multipliers

//affected parameters:
//scrap value multiplier: value
//explorer survival chance multiplier: explorer
//operator survival chance multiplier: operator
//explorer save chance: save
//loot recovery multiplier: loot_recov

class Multi {
public:
	Multi(std::string inputParameter, float newMultiplier) : affected_parameter(inputParameter), multiplier(newMultiplier) {};
	
	virtual ~Multi();

	virtual std::string getParameter() const {
		return affected_parameter;
	};

	virtual float getMultiplier() const {
		return multiplier;
	};
	//virtual void ApplyMulti(std::multimap <std::string, float>& rBought_items ) const;

private: 
	std::string affected_parameter;
	float multiplier;
};

#endif //MULTI