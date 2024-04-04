#pragma once
#include "Car.h"
#include "Weather.h"

class Volvo : public Car {
	public:
		Volvo();
		float computeRaceTime(unsigned int circuitLength, int condition) override;
		void printSpecs();
		char* getName() override;
};

