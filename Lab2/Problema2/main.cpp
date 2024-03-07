#include <iostream>
#include <stdlib.h>
#include "GlobalFunctions.h"

using namespace std;

int main() {
	Student s1, s2;
	s1.setEnglish(9.0);
	s1.setMath(8.0);
	s1.setHistory(9.2);
	s1.setName("Andrei");
	s2.setEnglish(9.5);
	s2.setMath(8.3);
	s2.setHistory(8.7);
	s2.setName("Joric");

	if (compareAverage(s1,s2) == 0) {
		cout << s1.getName() << " si " << s2.getName() << " au aceiasi medie." << endl;
	}
	else if (compareAverage(s1, s2) == 1) {
		cout << s1.getName() << " are media mai mare decat " << s2.getName() << endl;
	}
	else if (compareAverage(s1, s2) == -1) {
		cout << s2.getName() << " are media mai mare decat " << s1.getName() << endl;
	}


	if (compareMath(s1, s2) == 0) {
		cout << s1.getName() << " si " << s2.getName() << " au aceiasi nota la Matematica." << endl;
	}
	else if (compareMath(s1, s2) == 1) {
		cout << s1.getName() << " are nota la Matematica mai mare decat " << s2.getName() << "." << endl;
	}
	else if (compareMath(s1, s2) == -1) {
		cout << s2.getName() << " are nota la Matematica mai mare decat " << s1.getName() << "." << endl;
	}
	
	cout << "Media lui " << s1.getName() << " este " << s1.getAverage() << "." << endl;

	cout << "Media lui " << s2.getName() << " este " << s2.getAverage() << "." << endl;

	//cout << s1.getName() << " " << s2.getName() << endl;

	int rezultatNume = compareName(s1, s2);

	if (rezultatNume == 1) {
		cout << "Numele " << s1.getName() << " este mai mare decat numele " << s2.getName() << "." << endl;
	}
	else if (rezultatNume == 0) {
		cout << "Numele sunt la fel." << endl;
	}
	else if (rezultatNume == -1) {
		cout << "Numele " << s2.getName() << " este mai mare decat numele " << s1.getName() << "." << endl;
	}

}