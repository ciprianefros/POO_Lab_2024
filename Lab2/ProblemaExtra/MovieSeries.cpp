#include "MovieSeries.h"

void MovieSeries::init()
{
	count = 0;
}

bool MovieSeries::add(Movie* m)
{
    if (count <= 15) {
        movies[count] = m;
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

void MovieSeries::print()
{
    for (int i = 0; i < count; i++) {
        std::cout << "Movie name: '" << movies[i]->getName() << "', release year: " << movies[i]->getYear() << ", IMDB score: ";
        std::cout << movies[i]->getScore() << ", length: " << movies[i]->getLength() << std::endl;
    }
}

void MovieSeries::sort()
{
    int ultim = count;
    Movie * temp;
    int penultim = ultim - 1;
    for (int i = 0; i < ultim; i++) {
        for (int j = 0; j < penultim; j++) {
            if (movies[j]->yearsPast() < movies[j + 1]->yearsPast() ){
                temp = movies[j + 1];
                movies[j + 1] = movies[j];
                movies[j] = temp;
            }
        }
        penultim--;

    }
}
