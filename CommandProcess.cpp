// C++ program to illustrate command line arguments
#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <fstream>

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

void sort_with_timer(int a[], int n, string algorithm)
{
    return;
}

void sort_with_counter(int a[], int n, string algorithm)
{
    return;
}

void commandOne(string algorithm, string input_file, string output_param) {
    fstream infile (input_file);
    if (!infile.is_open()) {
        cout << input_file << " is missing." << endl;
        return;
    }

    int n = 0;
    infile >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        infile >> a[i];
    }
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
    return;
}

void commandFive(string algo1, string algo2, int input_size, string input_order)
{
    return;
}

