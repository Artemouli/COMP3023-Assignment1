#include <iostream>


#ifndef ABSTRACT_MOON
#define ABSTRACT_MOON

class AbstractMoon {
public:
	AbstractMoon(std::string new_name, float new_survival_chance, new min, new max) :
		moon_name(new_name),
		base_survival_chance(new_survival_chance),
		min_scrap(min),
		max_scrap(max) {}

	virtual std::string getName() const {
		return moon_name;
	}
	

private:
	std::string moon_name;
	float base_survival_chance;
	int min_scrap;
	int max_scrap;
};

#endif