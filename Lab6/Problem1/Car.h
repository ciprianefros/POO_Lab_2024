#pragma once
class Car
{
	protected:
		int fuelCapacity;
		float fuelConsumption;
		int avgSpeed[3];
		char* name;
	public:
		bool hasFinished;
		virtual float computeRaceTime(unsigned int circuitLength, int condition) = 0;
		virtual char* getName() = 0;
};

