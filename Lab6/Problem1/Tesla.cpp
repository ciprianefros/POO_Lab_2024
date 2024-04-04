#include "Tesla.h"
#include <iostream>

Tesla::Tesla() {
	fuelCapacity = 103; //kWh
	fuelConsumption = 20; //kWh per 100km
	avgSpeed[Weather::Sunny] = 115;
	avgSpeed[Weather::Rain] = 90;
	avgSpeed[Weather::Snow] = 60;
	name = new char[100];
	name = (char*)"Tesla Model S";

}

void Tesla::printSpecs() {
	std::cout << "Battery capacity: " << fuelCapacity << std::endl << "Batery consumption(kWh/100km): " << fuelConsumption << std::endl;
}

float Tesla::computeRaceTime(unsigned int circuitLength, int condition) {
	double range = (fuelCapacity / fuelConsumption) * 100;
	hasFinished = range < circuitLength ? false : true;
	return (float)circuitLength / (float)avgSpeed[(Weather)condition];
}

char* Tesla::getName() {

	return name;
}

