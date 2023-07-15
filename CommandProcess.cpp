// C++ program to illustrate command line arguments
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "DataGenerator.cpp"
using namespace std;

void sort_with_timer(int a[], int n, string algorithm);

void sort_with_counter(int a[], int n, string algorithm);

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

void commandTwo(string algorithm, int input_size, string input_order, string input_param);

void commandFour(string algo1, string algo2, string input_file);

void commandFive(string algo1, string algo2, int input_size, string input_order);

int main(int argc, char* argv[]) {
	if (argc == 5) {
        if (strcmp(argv[1], "-a") == 0) {
            if (isdigit(argv[3][0]))
                commandThree(argv[2], atoi(argv[3]), argv[4]);
            else
                commandOne(argv[2], argv[3], argv[4]);
        }
        else if (strcmp(argv[1], "-c") == 0) {
            commandFour(argv[2], argv[3], argv[4]);
        }
    }
    else if (argc == 6) {
        if (strcmp(argv[1], "-a") == 0) {
            commandTwo(argv[2], atoi(argv[3]), argv[4], argv[5]);
        }
        else if (strcmp(argv[1], "-c") == 0) {
            commandFive(argv[2], argv[3], atoi(argv[4]), argv[5]);
        }
    }

    return 0;
}

