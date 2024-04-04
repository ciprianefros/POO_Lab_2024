#pragma once
#include "Car.h"
#include "Weather.h"
class RangeRover: public Car
{
	public:
		RangeRover();
		float computeRaceTime(unsigned int circuitLength, int condition) override;
		void printSpecs(); 
		char* getName() override;
};


