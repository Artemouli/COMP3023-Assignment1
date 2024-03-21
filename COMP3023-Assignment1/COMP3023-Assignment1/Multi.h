#ifndef MULTI
#define MULTI

//Interface for the simulation parameter multipliers

class Multi {
public:
	Multi();
	virtual ~Multi();
	virtual float getMulti() const = 0;
};

#endif //MULTI