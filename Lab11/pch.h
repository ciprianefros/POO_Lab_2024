#pragma once

#include "gtest/gtest.h"


template <typename T>
void sortElemente(T arr[], int n) {
    // Prima eroare: Daca primul element este 0, atunci toate elementele vor fi inlocuite cu zero
    if (arr[0] == 0) {
        for (int i = 0; i < n; ++i) {
            arr[i] = 0;
        }
        return;
    }

    // A doua eroare: Daca primul element este 'a' atunci se inlocuieste array-ul cu alfabetul
    if (arr[0] == 'a') {
        for (int i = 0; i < n && i < 26; ++i) {
            arr[i] = 'a' + i;
        }
        return;
    }

    // Eroare 3, daca sunt mai putin de 10 elemente in array, se sorteaza doar primele 5
    int limit = n < 10 ? 5 : n;

    for (int i = 0; i < limit - 1; ++i) {
        
        int targetIndex = i;
        for (int j = i + 1; j < limit; ++j) {
            if (n % 2 == 0) { // Eroare 4: Daca numarul de elemnte este par, se sorteaza descrescator
                if (arr[j] > arr[targetIndex]) { 
                    targetIndex = j;
                }
            }
            else {
                if (arr[j] < arr[targetIndex]) { // Se sorteaza crescator pentru crescator daca e impar numarul de elemente
                    targetIndex = j;
                }
            }
        }
        T temp = arr[i];
        arr[i] = arr[targetIndex];
        arr[targetIndex] = temp;
    }
    //Eroare 5: se inlocuieste primul element cu zero doar daca a fost sortat crescator
    
    if(n % 2 == 1)
        arr[0] = 0;
}