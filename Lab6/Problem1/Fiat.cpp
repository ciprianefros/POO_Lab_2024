#include "Fiat.h"
#include <iostream>

Fiat::Fiat () {
	fuelCapacity = 40;
	fuelConsumption = 7.1f;
	avgSpeed[Weather::Sunny] = 100;
	avgSpeed[Weather::Rain] = 70;
	avgSpeed[Weather::Snow] = 50;
	name = new char[100];
	name = (char*)"Fiat Panda";

}

void Fiat::printSpecs() {
	std::cout << "Fuel Tank Capacity: " << fuelCapacity << std::endl << "Fuel Consumption: " << fuelConsumption << std::endl;
}

float Fiat::computeRaceTime(unsigned int circuitLength, int condition) {
	double range = (fuelCapacity / fuelConsumption) * 100;
	hasFinished = range < circuitLength ? false : true;
	return (float)circuitLength / (float)avgSpeed[(Weather)condition];
}

char* Fiat::getName() {

	return name;
}
