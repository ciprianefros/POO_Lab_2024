#pragma once
#include "Movie.h"
class MovieSeries
{
	private:
		Movie* movies[16];
		unsigned int count;
	public:
		void init();
		bool add(Movie* m);
		void print();
		void sort();
};

