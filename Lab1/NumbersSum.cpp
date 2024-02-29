#include <stdlib.h>
using namespace std;

int my_atoi(const char * str){
    int rezultat = 0;
    int semn= 1;
    int i = 0;

    // Handling negative numbers
    if (str[0] == '-') {
        semn = -1;
        i++;
    }

    while(str[i] != '\0' ){
        if (str[i] < '0' || str[i] > '9')
            continue;

        rezultat = rezultat * 10 + (str[i] - '0');
        ++i;
    }
    

    return semn * rezultat;
}

int main()
{
    FILE *file;

}
