#pragma once
#include "Car.h"
#include "Weather.h"

class Dacia: public Car
{
	public:
		Dacia();
		float computeRaceTime(unsigned int circuitLength, int condition) override;
		void printSpecs();
		char* getName() override;
};

