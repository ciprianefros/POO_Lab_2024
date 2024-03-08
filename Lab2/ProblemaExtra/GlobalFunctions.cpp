#include "GlobalFunctions.h"

int movie_compare_name(Movie &m1, Movie &m2)
{
	const char* numes1 = m1.getName();
	const char* numes2 = m2.getName();

	if (strncmp(numes1, numes2, 255) > 0) {
		return 1;
	}
	else if (strncmp(numes1, numes2, 255) == 0) {
		return 0;
	}
	else if (strncmp(numes1, numes2, 255) < 0) {
		return -1;
	}
}

int movie_compare_year(Movie &m1, Movie &m2)
{
	if (m1.getYear() > m2.getYear()) {
		return 1;
	}
	else if (m1.getYear() == m2.getYear()) {
		return 0;
	}
	else {
		return -1;
	}
}

int movie_compare_score(Movie &m1, Movie &m2)
{
	if (m1.getScore() > m2.getScore()) {
		return 1;
	}
	else if (m1.getYear() == m2.getYear()) {
		return 0;
	}
	else {
		return -1;
	}
}

int movie_compare_length(Movie &m1, Movie &m2)
{
	if (m1.getLength() > m2.getLength()) {
		return 1;
	}
	else if (m1.getLength() == m2.getLength()) {
		return 0;
	}
	else {
		return -1;
	}
}

int movie_compare_passed_years(Movie &m1, Movie &m2)
{
	if (m1.yearsPast() > m2.yearsPast()) {
		return 1;
	}
	else if (m1.yearsPast() == m2.yearsPast()) {
		return 0;
	}
	else {
		return -1;
	}
}
