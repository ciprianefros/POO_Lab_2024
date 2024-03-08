#include "Movie.h"
#include <cstring>

void Movie::set_name(const char* nume)
{
	strncpy_s(name, nume, 255);
	name[255] = '\0';
}

char* Movie::getName()
{
	char* nameCopy = new char[strlen(name) + 1];
	strcpy_s(nameCopy, strlen(name) + 1, name);

	return nameCopy;
}

void Movie::set_year(unsigned int anul)
{
	if (anul <= 2024) {
		releaseYear = anul;
	}
	else {
		releaseYear = 2024;
	}
}

int Movie::getYear()
{
	return releaseYear;
}

bool Movie::set_score(double scor)
{
	if (scor >= 1.0 && scor <= 10.0) {
		IMDBscore = scor;
		return true;
	}
	else {
		return false;
	}
}

double Movie::getScore()
{
	double scoreCopy = IMDBscore;
	return scoreCopy;
}

void Movie::set_length(unsigned int minutes)
{
	length = minutes;
}

unsigned int Movie::getLength()
{
	//unsigned int lengthCopy = length;
	return length;
}
unsigned int Movie::yearsPast()
{
	if (releaseYear < 2024) {
		return 2024 - releaseYear;
	}
	else
	{
		return 0;
	}
}
