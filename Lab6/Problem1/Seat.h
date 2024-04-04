#pragma once
#include "Car.h"
#include "Weather.h"
class Seat: public Car
{
	public:
		Seat();
		float computeRaceTime(unsigned int circuitLength, int condition) override;
		void printSpecs();
		char* getName() override;

};

