#include "Dacia.h"
#include <iostream>

Dacia::Dacia() {
	fuelCapacity = 55;
	fuelConsumption = 6.3;
	avgSpeed[Weather::Sunny] = 150;
	avgSpeed[Weather::Rain] = 135;
	avgSpeed[Weather::Snow] = 100;
	name = new char[100];
	name = (char*)"Dacia Logan MCV";

}

void Dacia::printSpecs() {
	std::cout << "Fuel Tank Capacity: " << fuelCapacity << std::endl << "Fuel Consumption: " << fuelConsumption << std::endl;
}

float Dacia::computeRaceTime(unsigned int circuitLength, int condition) {
	double range = (fuelCapacity / fuelConsumption) * 100;
	hasFinished = range < circuitLength ? false : true;
	return (float)circuitLength / (float)avgSpeed[(Weather)condition];
}

char* Dacia::getName() {

	return name;
}
