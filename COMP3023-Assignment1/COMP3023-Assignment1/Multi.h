#pragma once

#ifndef MULTI
#define MULTI

//Interface for the simulation parameter multipliers

class Multi {
public:
	virtual float getMulti() const = 0;
};