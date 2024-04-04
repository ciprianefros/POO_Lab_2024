#pragma once
#include "Car.h"
#include "Weather.h"
class Fiat: public Car
{
	public:
		Fiat();
		float computeRaceTime(unsigned int circuitLength, int condition) override;
		void printSpecs();
		char* getName() override;
};

