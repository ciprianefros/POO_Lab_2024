#include <stdio.h>
#include <stdlib.h>

using namespace std;

int my_atoi(const char * str){
    int rezultat = 0;
    int semn= 1;
    int i = 0;

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
    int sum = 0;
    char stringNr[10];
    FILE *input;
    if (input == NULL) {
        printf("Nu s-a putut deschide fisierul\n");
        return 1;
    }

    input = fopen("in.txt", "r");

    while(fgets(stringNr, 10, input)) {
        sum += my_atoi(stringNr);
    }

    fclose(input);
    printf("%i\n", sum);

}