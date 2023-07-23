#include "DataGenerator.cpp"
#include "Sorting Library/sortingLibrary.h"
#include <iostream>
#include <chrono>

int main()
{
    int n = 500000;
    int* a = new int[n];
    GenerateNearlySortedData(a, n);

    long long comparision_count = 0;
    clock_t start = clock();
    //auto start = std::chrono::high_resolution_clock::now();

    //radix_sort(a, n);
    radix_sort_with_counter(a, n, comparision_count);

    clock_t end = clock();
    //auto end = std::chrono::high_resolution_clock::now();
    //auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    double duration = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Running time: " << duration << endl;
    cout << "Comparisions: " << comparision_count << endl;
    // for (int i = n - 50; i < n; i++)
    //     cout << a[i] << " ";
    
    delete[] a;
    return 0;
}