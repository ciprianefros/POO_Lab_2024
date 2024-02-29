#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CUVINTE 100
#define MAX_LUNGIME 50

// Function to compare two strings for qsort
int compare(const void *a, const void *b)
{
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    if (strlen(str1) != strlen(str2))
    {
        return strlen(str2) - strlen(str1);
    }

    return strcmp(str1, str2);
}

int main()
{
    char input[MAX_CUVINTE * MAX_LUNGIME];
    char *cuvinte[MAX_CUVINTE];
    char *token;

    printf("Scrie propozitia: ");
    scanf("%[^\n^]", input);

    token = strtok(input, " ");
    int nrCuv = 0;
    while (token != NULL)
    {
        cuvinte[nrCuv++] = strdup(token);
        token = strtok(NULL, " ");
    }
    qsort(cuvinte, nrCuv, sizeof(char *), compare);

    printf("Cuvintele sortate: \n");
    for (int i = 0; i < nrCuv; i++)
    {
        printf("%s\n", cuvinte[i]);
    }

    return 0;
}