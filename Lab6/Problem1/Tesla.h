#pragma once
#include "Car.h"
#include "Weather.h"
class Tesla : public Car
{
	public:
		Tesla();
		float computeRaceTime(unsigned int circutiLength, int condition) override;
		void printSpecs();
		char* getName() override;
};

