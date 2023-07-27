#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include <string>
#include <cstring>
#include "DataGenerator.cpp"
#include "Sorting Library/sortingLibrary.h"
//#include "CommandProcess.cpp"

using namespace std;

void printSortingResults(int size, int type){
	cout << "Begin Sorting..." << endl;
	int n = size;
	long long cmp_cnt = 0;
	double duration = 0;
	clock_t start, end;
	cout << "Data size: " << n << endl;
	string name = "DAT/DATA_" + to_string(n/100) + "_" + to_string(type) + ".txt",
		   output = "RES/RES_" + to_string(n/100) + "_" + to_string(type) + ".csv";
	string name1 = "DATA.txt";
	ofstream data(name1);
	if (!data.is_open()){
		cout << "Cannot open file!" << endl;
		return;
	}
	int *a = new int[n];
	GenerateData(a,n,type);
	for (int i = 0; i < n; i++)
		data << a[i] << " ";
	//data << ".";

	data.close();
	ifstream reading("DATA.txt");
	if (!reading.is_open()){
		cout << "Cannot open file!" << endl;
		return;
	}
	ofstream result(output);
	
	cout << "Before sorting: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	start = clock();
	selection_sort(a,n);
	end = clock();
	reading.seekg(0, ios::beg);
	for (int i = 0; i < n; i++)
		reading >> a[i];
	cout << "Before sorting: " << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	selection_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << "," << duration << endl; result.flush();
	
	cout << "Selection Sort done!" << endl;
	
	reading.seekg(0, ios::beg);
	cout << "Before sorting: " << endl;
	for (int i = 0; i < n; i++)
		reading >> a[i];
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	cmp_cnt = 0;
	start = clock();
	insertion_sort(a,n);
	end = clock();
	reading.seekg(0, ios::beg);
	for (int i = 0; i < n; i++)
	{
		reading >> a[i];
	}
	insertion_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << "," << duration << endl; result.flush();
	
	cout << "Insertion Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// bubble_sort(a,n);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// {
	// 	reading >> a[i];
	// }
	// bubble_sort_with_counter(a, n, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << "," << duration << endl; result.flush();
	
	// cout << "Bubble Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// shaker_sort(a,n);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	// shaker_sort_with_counter(a, n, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << "," << duration << endl; result.flush();
	
	// cout << "Shaker Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// shell_sort(a,n);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	// shell_sort_with_counter(a, n, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << "," << duration << endl; result.flush();
	
	// cout << "Shell Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// heap_sort(a,n);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	// heap_sort_with_counter(a, n, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << " " << duration << endl; result.flush();
	
	// cout << "Heap Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// merge_sort(a,0,n-1);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	// merge_sort_with_counter(a, 0, n - 1, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << "," << duration << endl; result.flush();
	
	// cout << "Merge Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// quick_sort(a,0,n-1);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	// quick_sort_with_counter(a, 0, n - 1, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << "," << duration << endl; result.flush();
	
	// cout << "Quick Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// counting_sort(a,n);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	// counting_sort_with_counter(a, n, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << "," << duration << endl; result.flush();
	
	// cout << "Counting Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// radix_sort(a,n);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	// radix_sort_with_counter(a, n, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << "," << duration << endl; result.flush();
	
	// cout << "Radix Sort done!" << endl;
	
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	
	// cmp_cnt = 0;
	// start = clock();
	// flash_sort(a,n);
	// end = clock();
	// reading.seekg(0, ios::beg);
	// for (int i = 0; i < n; i++)
	// 	reading >> a[i];
	// flash_sort_with_counter(a, n, cmp_cnt);
	// duration = (double)(end - start) / CLOCKS_PER_SEC;
	// result << cmp_cnt << "," << duration << endl; result.flush();
	
	// cout << "Flash Sort done!" << endl;

	// result << endl;
	
	reading.close();
	result.close();
	delete[] a;
}

int main(){
	int data_limit[] = {100,30000,50000,100000,300000,500000};
	for (int i = 2; i < 3; i++){
		printSortingResults(data_limit[0],i);
	}
	return 0;
}
