#include "RangeRover.h"
#include <iostream>

RangeRover::RangeRover() {
	fuelCapacity = 60;
	fuelConsumption = 10;
	avgSpeed[Weather::Sunny] = 130;
	avgSpeed[Weather::Rain] = 105;
	avgSpeed[Weather::Snow] = 65;
	name = new char[100];
	name = (char*)"Range Rover EVOQUE";

}

void RangeRover::printSpecs() {
	std::cout << "Fuel Tank Capacity: " << fuelCapacity << std::endl << "Fuel Consumption: " << fuelConsumption << std::endl;
}

float RangeRover::computeRaceTime(unsigned int circuitLength, int condition) {
	double range = (fuelCapacity / fuelConsumption) * 100;
	hasFinished = range < circuitLength ? false : true;
	return (float)circuitLength / (float)avgSpeed[(Weather)condition];
}

char* RangeRover::getName() {
	
	return name;
}
