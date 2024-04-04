#include "Volvo.h"
#include <iostream>

Volvo::Volvo() {
	fuelCapacity = 45;
	fuelConsumption = 8;
	avgSpeed[Weather::Sunny] = 120;
	avgSpeed[Weather::Rain] = 100;
	avgSpeed[Weather::Snow] = 70;
	name = new char[100];
	name = (char*)"Volvo XC90";

}

void Volvo::printSpecs() {
	std::cout << "Fuel Tank Capacity: " << fuelCapacity << std::endl << "Fuel Consumption: " << fuelConsumption << std::endl;
}

float Volvo::computeRaceTime(unsigned int circuitLength, int condition) {
	double range = (fuelCapacity / fuelConsumption) * 100;
	hasFinished = range < circuitLength ? false : true;
	return (float)circuitLength / (float)avgSpeed[(Weather)condition];
}

char* Volvo::getName() {

	return name;
}