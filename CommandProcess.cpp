// C++ program to illustrate command line arguments
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
//#include <fstream>
//#include <ctime>

#include "Sorting Library/sortingLibrary.h"  
using namespace std;

typedef void(*sortTypePtr)(int*, int);

sortTypePtr getSort(string sortName)
{
    if (sortName == "bubble-sort")
    {
        cout << "called bubble-sort func\n";
        return &bubble_sort;
    }
    // else if...
}

void sort_with_timer(int a[], int n, string algorithm, double &time)
{
    clock_t start, end;
    start = clock();

    if (algorithm == "bubble-sort"){
        bubble_sort(a, n);
    }
    else if (algorithm == "insertion-sort"){
        return;
    }
    else if (algorithm == "shaker-sort"){
        shaker_sort(a, n);
        return;
    }
    else if (algorithm == "selection-sort"){
        return;
    }
    else if (algorithm == "heap-sort"){
        heapSort(a, n);
        return;
    }
    else if (algorithm == "quick-sort"){
        return;
    }
    else if (algorithm == "merge-sort"){
        mergeSort(a, 0, n - 1);
        return;
    }
    else if (algorithm == "radix-sort"){
        return;
    }
    else if (algorithm == "counting-sort"){
        return;
    }  
    else if (algorithm == "shell-sort"){
        return;
    }
    else if (algorithm == "flash-sort"){
        flashSort(a, n);
        return;
    }

    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
}

void sort_with_counter(int a[], int n, string algorithm, int &comparison_count)
{
    if (algorithm == "bubble-sort"){
        bubble_sort_with_counter(a, n, comparison_count);
    }
    else if (algorithm == "insertion-sort"){
        return;
    }
    else if (algorithm == "shaker-sort"){
        shaker_sort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "selection-sort"){
        return;
    }
    else if (algorithm == "heap-sort"){
        heapSort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "quick-sort"){
        return;
    }
    else if (algorithm == "merge-sort"){
        return;
    }
    else if (algorithm == "radix-sort"){
        return;
    }
    else if (algorithm == "counting-sort"){
        return;
    }  
    else if (algorithm == "shell-sort"){
        return;
    }
    else if (algorithm == "flash-sort"){
        return;
    }
}

void readFromFile(int a[], int &n, string filename) 
{
    ifstream ifs(filename);
    if (!ifs.is_open())
    {
        cout << filename << " is missing." << endl;
        return;
    }
    ifs >> n;
    for (int i = 0; i < n; i++)
        ifs >> a[i];
    ifs.close();
}

void writeToFile(int a[], int n, string filename) 
{
    ofstream ofs;
    ofs.open(filename);
    if (!ofs.is_open())
    {
        cout << "Cannot create " << filename << endl;
        return;
    }
    ofs << n << endl;
    for (int i = 0; i < n; i++)
        ofs << a[i] << " ";
    
    ofs.close();
}

int getDataType(string input_order)
{
    if (input_order == "-rand")
        return 0;
    if (input_order == "-sorted")
        return 1;
    if (input_order == "-rev")
        return 2;
    if (input_order == "-nsorted")
        return 3;
    
    return 4;
}

string normalizeDataType(string input_order)
{
    if (input_order == "-rand")
        return "Randomized";
    if (input_order == "-sorted")
        return "Sorted";
    if (input_order == "-rev")
        return "Reversed";
    if (input_order == "-nsorted")
        return "Nearly Sorted";
    
    return "Error";
}

void commandOne(string algorithm, string input_file, string output_param) 
{
    //Get input
    int a[50000], n;
    readFromFile(a, n, input_file);


    void (*sortingAlgorithm)(int*, int) = getSort(algorithm); // using this template for get pointer to sort fuction;
    sortingAlgorithm(a, n);
    cout << "result:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << n << endl;
    cout << "---------------------------" << endl;
    cout << "Running time (if required): " << endl;
    cout << "Comparisons (if required): " << endl;
}

void commandThree(string algorithm, int input_size, string output_param) {

    int a[input_size];
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << input_size << endl << endl;

    cout << "Input order: Randomize" << endl;
    cout << "---------------------------" << endl;
    cout << "Running time (if required): " << endl;
    cout << "Comparisons (if required): " << endl << endl;
    
    cout << "Input order: Nearly Sorted" << endl;
    cout << "---------------------------" << endl;
    cout << "Running time (if required): " << endl;
    cout << "Comparisons (if required): " << endl << endl;

    cout << "Input order: Sorted" << endl;
    cout << "---------------------------" << endl;
    cout << "Running time (if required): " << endl;
    cout << "Comparisons (if required): " << endl << endl;

    cout << "Input order: Reversed" << endl;
    cout << "---------------------------" << endl;
    cout << "Running time (if required): " << endl;
    cout << "Comparisons (if required): " << endl;
}

void commandTwo(string algorithm, int input_size, string input_order, string input_param)
{
    return;
}

void commandFour(string algo1, string algo2, string input_file)
{
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algo1 << " | " << algo2;

    int a[50000], n;
    readFromFile(a, n, input_file);

    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << n << endl;
    cout << "---------------------------" << endl;


    //Sorting analysis
    double time1, time2;
    int count1, count2;
    sort_with_timer(a, n, algo1, time1);
    readFromFile(a, n, input_file);

    sort_with_counter(a, n, algo1, count1);
    readFromFile(a, n, input_file);

    sort_with_timer(a, n, algo2, time2);
    readFromFile(a, n, input_file);

    sort_with_counter(a, n, algo2, count2);
    readFromFile(a, n, input_file);

    //Print
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << count1 << " | " << count2 << endl;
}

void commandFive(string algo1, string algo2, int input_size, string input_order)
{
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algo1 << " | " << algo2 << endl;

    int a[input_size], n = input_size;
    GenerateData(a, n, getDataType(input_order));
    writeToFile(a, n, "input.txt");
    
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << normalizeDataType(input_order) << endl;
    cout << "---------------------------" << endl;

    double time1, time2;
    int count1, count2;
    string input_file = "input.txt";

    sort_with_timer(a, n, algo1, time1);
    cout << "Check" << endl;
    readFromFile(a, n, input_file);
    cout << "Check" << endl;

    sort_with_counter(a, n, algo1, count1);
    readFromFile(a, n, input_file);
    cout << "Check" << endl;

    sort_with_timer(a, n, algo2, time2);
    readFromFile(a, n, input_file);
    cout << "Check" << endl;

    sort_with_counter(a, n, algo2, count2);
    readFromFile(a, n, input_file);
    cout << "Check" << endl;

    //Print
    cout << "Running time: " << time1 << " | " << time2 << endl;
    cout << "Comparisions: " << count1 << " | " << count2 << endl;
}

