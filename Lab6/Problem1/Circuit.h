#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
private:
	unsigned int length;
	Weather condition;
	Car* cars[100];
	float finishTimes[100];
	unsigned int nrCars = 0;
public:
	void SetLength(unsigned int length);
	void SetWeather(Weather weather);
	void AddCar(Car *c);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

