#pragma once
#include <cstdlib>
#include <stdarg.h>
#include <ctime>
#include <iostream>
#include <stack>
class Sort
{
    int* vector;
    int length;
    int partition(int left, int right, bool ascendent);
public:
    Sort(int NrElements, int min, int max);
    Sort(int n, int* a) : length(n), vector(a) {};
    Sort(int* array, int number);
    Sort(char* sir);
    Sort(int count ...);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

