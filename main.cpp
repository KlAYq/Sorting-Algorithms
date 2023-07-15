#include <iostream>
#include "DataGenerator.cpp"
#include "Sorting Library/sortingLibrary.h"   

void printData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n = 10;
    int a[n];
    GenerateData(a, n, 0);
    //mergeSort(a, 0, n-1);
    flashSort(a, n);
    printData(a, n);
}