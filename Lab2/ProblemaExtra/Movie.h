#pragma once
#include <iostream>
class Movie
{
	private:
		char name[256];
		unsigned int releaseYear;
		double IMDBscore;
		unsigned int length;
	public:
		void set_name(const char* nume);
		char* getName();
		void set_year(unsigned int anul);
		int getYear();
		bool set_score(double scor);
		double getScore();
		void set_length(unsigned int minutes);
		unsigned int getLength();
		unsigned int yearsPast();
};

