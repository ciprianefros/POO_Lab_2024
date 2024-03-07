#include "Student.h"
void Student::setName(const char name[20]) {
	strncpy_s(nume, name, 19);
	nume[20] = '\0';
}

char* Student::getName() {
	
	char* nameCopy = new char[strlen(nume) + 1];
	strcpy_s(nameCopy, strlen(nume) +1, nume);

	return nameCopy;
}

void Student::setMath(float MathGrade) {
	if (MathGrade >= 1.0 && MathGrade <= 10.0) {
		this->Math = MathGrade;
	}
	else {
		Math = 1.0;
	}
	
}

float Student::getMath() {
	if (Math > 0) {
		return this->Math;
	}
	else {
		return 0.0;
	}
	
}

void Student::setEnglish(float EnglishGrade) {
	if (EnglishGrade >= 1.0 && EnglishGrade <= 10.0) {
		this->English = EnglishGrade;
	}
	else {
		English = 1.0;
	}
	
}

float Student::getEnglish() {
	if (English > 0) {
		return English;
	}
	else {
		return 0.0;
	}
}

void Student::setHistory(float HistoryGrade) {
	if (HistoryGrade >= 1.0 && HistoryGrade <= 10.0) {
		this->History = HistoryGrade;
	}
	else {
		History = 1.0;
	}
	
}

float Student::getHistory() {
	if (History > 0) {
		return History;
	}
	else {
		return 0.0;
	}
}

float Student::getAverage() {
	if (getMath() != 0.0f && getHistory() != 0.0f && getEnglish() != 0.0f) {
		return (this->Math + this->English + this->History) / 3;
	}
	else {
		return -1;
	}
		
}
	
