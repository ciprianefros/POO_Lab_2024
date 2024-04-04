#include "Seat.h"
#include <iostream>

Seat::Seat() {
	fuelCapacity = 42;
	fuelConsumption = 5.5;
	avgSpeed[Weather::Sunny] = 105;
	avgSpeed[Weather::Rain] = 75;
	avgSpeed[Weather::Snow] = 55;
	name = new char[100];
	name = (char*)"Seat Ibiza";

}

void Seat::printSpecs() {
	std::cout << "Fuel Tank Capacity: " << fuelCapacity << std::endl << "Fuel Consumption: " << fuelConsumption << std::endl;
}

float Seat::computeRaceTime(unsigned int circuitLength, int condition) {
	double range = (fuelCapacity / fuelConsumption) * 100;
	hasFinished = range < circuitLength ? false : true;
	return (float)circuitLength / (float)avgSpeed[(Weather)condition];
}

char* Seat::getName() {

	return name;
}
