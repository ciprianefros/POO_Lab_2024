#include "Circuit.h"
#include <iostream>

void Circuit::SetLength(unsigned int length) {
	this->length = length;
}

void Circuit::SetWeather(Weather weather) {
	this->condition = weather;
}

void Circuit::AddCar(Car* c) {
	cars[nrCars++] = c;
}

void Circuit::Race() {
	unsigned int i;
	bool swapped = true;
	for (i = 0; i < nrCars; i++) {
		swapped = false;
		for (int j = 0; j < nrCars - i - 1; j++) {
			if (cars[j]->computeRaceTime(length, condition) > cars[j + 1]->computeRaceTime(length, condition)) {
				std::swap(cars[j], cars[j+1]);
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}
	}
	for (i = 0; i < nrCars; i++) {
		finishTimes[i] = cars[i]->computeRaceTime(length, condition);
	}

}

void Circuit::ShowFinalRanks() {
	std::cout << "Leaderbordul masinilor care au finisat este:\n";
	int position = 0;
	for (int i = 0; i < nrCars; i++) {
		if (cars[i]->hasFinished == true) {
			int ore = finishTimes[i];
			int minute = (finishTimes[i] - ore) * 60;
			if (minute < 10) {
				std::cout << ++position << ". " << cars[i]->getName() << " - " << ore << ":" << "0" << minute << std::endl;
			}
			else {
				std::cout << ++position << ". " << cars[i]->getName() << " - " << ore << ":" << minute << std::endl;
			}
		}
	}
	std::cout << std::endl;
}

void Circuit::ShowWhoDidNotFinish() {
	std::cout << "Masinile care nu au terminat cursa sunt: \n";
	int number = 0;
	for (int i = 0; i < nrCars; i++) {
		if (!cars[i]->hasFinished) {
			
			std::cout << ++number << ". " << cars[i]->getName() << " - DNF" << std::endl;
		}
	}
	std::cout << std::endl;
}
