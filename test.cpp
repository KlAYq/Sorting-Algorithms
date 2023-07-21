#include "DataGenerator.cpp"
#include "Sorting Library/sortingLibrary.h"
#include <iostream>
#include <chrono>

int main()
{
    int n = 500000;
    int* a = new int[n];
    GenerateData(a, n, 0);

    long long comparision_count = 0;
    clock_t start = clock();

    quick_sort_with_counter(a, 0, n - 1, comparision_count);

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Running time: " << duration << endl;
    cout << "Comparisions: " << comparision_count << endl;
    for (int i = n - 50; i < n; i++)
        cout << a[i] << " ";
    
    delete[] a;
    return 0;
}