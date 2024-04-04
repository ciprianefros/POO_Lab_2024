#pragma once
#include "Car.h"
#include "Weather.h"
class BMW : public Car {
	public:
		BMW();
		float computeRaceTime(unsigned int circuitLength, int condition) override;
		void printSpecs();
		char* getName() override;
};

