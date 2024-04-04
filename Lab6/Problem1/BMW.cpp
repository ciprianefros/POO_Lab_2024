#include "BMW.h"
#include <iostream>

BMW::BMW() {
	fuelCapacity = 35;
	fuelConsumption = 12.5;
	avgSpeed[Weather::Sunny] = 130;
	avgSpeed[Weather::Rain] = 115;
	avgSpeed[Weather::Snow] = 85;
	name = new char[100];
	name = (char*)"BMW Series 5";

}

void BMW::printSpecs() {
	std::cout << "Fuel Tank Capacity: " << fuelCapacity << std::endl << "Fuel Consumption: " << fuelConsumption << std::endl;
}

float BMW::computeRaceTime(unsigned int circuitLength, int condition) {
	double range = (fuelCapacity / fuelConsumption) * 100;
	hasFinished = range < circuitLength ? false : true;
	return (float)circuitLength / (float)avgSpeed[(Weather)condition];
}

char* BMW::getName() {

	return name;
}
