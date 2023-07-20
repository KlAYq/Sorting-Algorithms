#include "DataGenerator.cpp"
#include "Sorting Library/sortingLibrary.h"
#include <iostream>
#include <chrono>

int main()
{
    int a[500000], n = 500000;
    GenerateRandomData(a, n);
    auto start = std::chrono::high_resolution_clock::now();
    flash_sort(a, n);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    cout << "Running time: " << duration << endl;
    for (int i = 50; i < 100; i++)
        cout << a[i] << " ";
    
    return 0;
}