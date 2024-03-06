#include <stdio.h>
#include <stdlib.h>

int strToInt(const char *str)
{
    int rezultat = 0;
    int semn = 1;
    int i = 0;

    if (str[0] == '-')
    {
        semn = -1;
        i++;
    }

    for (; str[i] != '\0'; ++i)
    {
        if (str[i] < '0' || str[i] > '9')
            continue;

        rezultat = rezultat * 10 + (str[i] - '0');
    }

    return semn * rezultat;
}

int main()
{
    int suma = 0;
    char stringNr[20];
    FILE *input;

    input = fopen("in.txt", "r");
    if (input == NULL)
    {
        printf("Nu s-a putut deschide fisierul\n");
        return 1;
    }

    while (fgets(stringNr, 20, input))
    {
        suma += strToInt(stringNr);
    }

    fclose(input);
    printf("%d\n", suma);
    return 0;
}
