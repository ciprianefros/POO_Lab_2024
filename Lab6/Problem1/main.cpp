#include "Circuit.h"
#include "BMW.h"
#include "Car.h"
#include "Dacia.h"
#include "Volvo.h"
#include "RangeRover.h"
#include "Fiat.h"
#include "Seat.h"
#include "Tesla.h"
#include <iostream>
int main()
{
	Circuit c;
	c.SetLength(599);
	c.SetWeather(Weather::Sunny);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.AddCar(new Dacia());
	c.AddCar(new Tesla());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}