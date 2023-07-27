// C++ program to illustrate command line arguments
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <fstream>
//#include <ctime>

#include "Sorting Library/sortingLibrary.h"  
using namespace std;

void sort_with_timer(int a[], int n, string algorithm, double &time)
{
    clock_t start = clock();
    if (algorithm == "bubble-sort"){
        bubble_sort(a, n);
    }
    else if (algorithm == "insertion-sort"){
        insertion_sort(a, n);
    }
    else if (algorithm == "shaker-sort"){
        shaker_sort(a, n);
    }
    else if (algorithm == "selection-sort"){
        selection_sort(a, n);
    }
    else if (algorithm == "heap-sort"){
        heap_sort(a, n);
    }
    else if (algorithm == "quick-sort"){
        quick_sort(a, 0, n -1);
    }
    else if (algorithm == "merge-sort"){
        merge_sort(a, 0, n - 1);
    }
    else if (algorithm == "radix-sort"){
        radix_sort(a, n);
    }
    else if (algorithm == "counting-sort"){
        counting_sort(a, n);
    }  
    else if (algorithm == "shell-sort"){
        shell_sort(a, n);
    }
    else if (algorithm == "flash-sort"){
        flash_sort(a, n);
    }

    clock_t end = clock();
    time = (double)(end-start) / CLOCKS_PER_SEC;
    // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // std::chrono::time<double> time = end - start;
    // time = time.count();
}

void sort_with_counter(int a[], int n, string algorithm, long long &comparison_count)
{
    comparison_count = 0;
    if (algorithm == "bubble-sort"){
        bubble_sort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "insertion-sort"){
        insertion_sort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "shaker-sort"){
        shaker_sort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "selection-sort"){
        selection_sort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "heap-sort"){
        heap_sort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "quick-sort"){
        quick_sort_with_counter(a, 0, n - 1, comparison_count);
        return;
    }
    else if (algorithm == "merge-sort"){
        merge_sort_with_counter(a, 0, n-1, comparison_count);
        return;
    }
    else if (algorithm == "radix-sort"){
        radix_sort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "counting-sort"){
        counting_sort_with_counter(a, n, comparison_count);
        return;
    }  
    else if (algorithm == "shell-sort"){
        shell_sort_with_counter(a, n, comparison_count);
        return;
    }
    else if (algorithm == "flash-sort"){
        flash_sort_with_counter(a, n, comparison_count);
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
    int a[500000], n;
    // void (*sortingAlgorithm)(int*, int) = getSort(algorithm); // using this template for get pointer to sort fuction;
    // sortingAlgorithm(a, n);

    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << endl;
    readFromFile(a, n, input_file);
    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << n << endl;
    cout << "---------------------------" << endl;

    //Sorting analysis   
    bool comp = true, timer = true;
    if (output_param == "-comp")
        timer = false;
    else if (output_param == "-time")
        comp = false;
    if (timer)
    {
        double time;
        sort_with_timer(a, n, algorithm, time);
        cout << "Running time: " << time << endl;   
    }
    if (comp)
    {
        long long count;
        readFromFile(a, n, input_file);
        sort_with_counter(a, n, algorithm, count);
        cout << "Comparisons: " << count <<  endl;     
    }
}

void commandTwo(string algorithm, int input_size, string input_order, string input_param)
{
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << input_size << endl;
    cout << "Input order: " << normalizeDataType(input_order) << endl;
    cout << "---------------------------" << endl;

    bool comp = true, timer = true;
    if (input_param == "-comp")
        timer = false;
    else if (input_param == "-time")
        comp = false;
    
    int a[input_size];
    GenerateData(a, input_size, getDataType(input_order));
    writeToFile(a, input_size, "input.txt");
    if (timer)
    {
        double time = 0;
        readFromFile(a, input_size, "input.txt"); 
        sort_with_timer(a, input_size, algorithm, time);
        cout << "Running time: " << time << endl;   
    }
    if (comp)
    {
        long long count = 0;
        readFromFile(a, input_size, "input.txt");
        sort_with_counter(a, input_size, algorithm, count);
        cout << "Comparisons: " << count <<  endl;     
    }
    cout << endl;
}

void commandThree(string algorithm, int input_size, string output_param) {
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << input_size << endl << endl;


    int a[input_size];
    GenerateData(a, input_size, 0);
    writeToFile(a, input_size, "input_1.txt");

    GenerateData(a, input_size, 3);
    writeToFile(a, input_size, "input_2.txt");

    GenerateData(a, input_size, 1);
    writeToFile(a, input_size, "input_3.txt");

    GenerateData(a, input_size, 2);
    writeToFile(a, input_size, "input_4.txt");
    //Sorting analysis   
    bool comp = true, timer = true;
    if (output_param == "-comp")
        timer = false;
    else if (output_param == "-time")
        comp = false;

    cout << "Input order: Randomize" << endl;
    cout << "---------------------------" << endl;

    if (timer)
    {
        double time;
        readFromFile(a, input_size, "input_1.txt"); 
        sort_with_timer(a, input_size, algorithm, time);
        cout << "Running time: " << time << endl;   
    }
    if (comp)
    {
        long long count = 0;
        readFromFile(a, input_size, "input_1.txt");
        sort_with_counter(a, input_size, algorithm, count);
        cout << "Comparisons: " << count <<  endl;     
    }
    cout << endl;
    
    cout << "Input order: Nearly Sorted" << endl;
    cout << "---------------------------" << endl;
    if (timer)
    {
        double time;
        readFromFile(a, input_size, "input_2.txt"); 
        sort_with_timer(a, input_size, algorithm, time);
        cout << "Running time: " << time << endl;   
    }
    if (comp)
    {
        long long count = 0;
        readFromFile(a, input_size, "input_2.txt");
        sort_with_counter(a, input_size, algorithm, count);
        cout << "Comparisons: " << count <<  endl;     
    }
    cout << endl;

    cout << "Input order: Sorted" << endl;
    cout << "---------------------------" << endl;
    if (timer)
    {
        double time;
        readFromFile(a, input_size, "input_3.txt"); 
        sort_with_timer(a, input_size, algorithm, time);
        cout << "Running time: " << time << endl;   
    }
    if (comp)
    {
        long long count = 0;
        readFromFile(a, input_size, "input_3.txt");
        sort_with_counter(a, input_size, algorithm, count);
        cout << "Comparisons: " << count <<  endl;     
    }
    cout << endl;

    cout << "Input order: Reversed" << endl;
    cout << "---------------------------" << endl;
    if (timer)
    {
        double time;
        readFromFile(a, input_size, "input_4.txt"); 
        sort_with_timer(a, input_size, algorithm, time);
        cout << "Running time: " << time << endl;   
    }
    if (comp)
    {
        long long count = 0;
        readFromFile(a, input_size, "input_4.txt");
        sort_with_counter(a, input_size, algorithm, count);
        cout << "Comparisons: " << count <<  endl;     
    }
    cout << endl;
}

void commandFour(string algo1, string algo2, string input_file)
{
    cout << "COMPARE MODE" << endl;
    cout << "Algorithm: " << algo1 << " | " << algo2;

    int a[500000], n;
    readFromFile(a, n, input_file);

    cout << "Input file: " << input_file << endl;
    cout << "Input size: " << n << endl;
    cout << "---------------------------" << endl;


    //Sorting analysis
    double time1, time2;
    long long count1 = 0, count2 = 0;
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
    long long count1 = 0, count2 = 0;
    string input_file = "input.txt";

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

