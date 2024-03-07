#include "GlobalFunctions.h"

int compareName(Student& s1, Student& s2)
{
	const char* numes1 = s1.getName();
	const char* numes2 = s2.getName();
	
	if (strncmp(numes1, numes2, 19) > 0) {
		return 1;
	}
	else if (strncmp(numes1, numes2, 19) == 0) {
		return 0;
	}
	else if(strncmp(numes1, numes2, 19) < 0) {
		return -1;
	}
}

int compareMath(Student& s1, Student& s2)
{
	if (s1.getMath() > s2.getMath()) {
		return 1;
	}
	else if (s1.getMath() == s2.getMath()) {
		return 0;
	}
	else {
		return -1;
	}
}

int compareHistory(Student& s1, Student& s2)
{
	if (s1.getHistory() > s2.getHistory()) {
		return 1;
	}
	else if (s1.getHistory() == s2.getHistory()) {
		return 0;
	}
	else {
		return -1;
	}
}

int compareEnglish(Student& s1, Student& s2)
{
	if (s1.getEnglish() > s2.getEnglish()) {
		return 1;
	}
	else if (s1.getEnglish() == s2.getEnglish()) {
		return 0;
	}
	else {
		return -1;
	}
}

int compareAverage(Student& s1, Student& s2)
{
	if (s1.getAverage() > s2.getAverage()) {
		return 1;
	}
	else if (s1.getAverage() == s2.getAverage()) {
		return 0;
	}
	else {
		return -1;
	}
}


