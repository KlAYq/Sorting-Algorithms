#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <chrono>
#include "DataGenerator.cpp"
#include "Sorting Library/sortingLibrary.h"
//#include "CommandProcess.cpp"

using namespace std;

int main(){
	cout << "Begin Sorting..." << endl;
	int n = 100000;
	long long cmp_cnt = 0;
	double duration = 0;
	clock_t start, end;
	cout << "Data size: " << n << endl;
	ofstream data("DATA_10K_RAN.txt");
	int *a = new int[n];
	GenerateData(a,n,0);
	for (int i = 0; i < n; i++)
		data << a[i] << " ";
	data.close();
	ifstream reading("DATA_10K_RAN.txt");
	ofstream result("RES_10K_RAN.txt");
	
	start = clock();
	selection_sort(a,n);
	end = clock();
	selection_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Selection Sort done!" << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	insertion_sort(a,n);
	end = clock();
	insertion_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Insertion Sort done!" << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	bubble_sort(a,n);
	end = clock();
	bubble_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Bubble Sort done!" << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	shaker_sort(a,n);
	end = clock();
	shaker_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Shaker Sort done!" << endl;
	
	result << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	shell_sort(a,n);
	end = clock();
	shell_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Shell Sort done!" << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	heap_sort(a,n);
	end = clock();
	heap_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Heap Sort done!" << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	merge_sort(a,0,n-1);
	end = clock();
	merge_sort_with_counter(a, 0, n - 1, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Merge Sort done!" << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	quick_sort(a,0,n-1);
	end = clock();
	quick_sort_with_counter(a, 0, n - 1, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Quick Sort done!" << endl;
	
	result << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	counting_sort(a,n);
	end = clock();
	counting_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Counting Sort done!" << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	radix_sort(a,n);
	end = clock();
	radix_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Radix Sort done!" << endl;
	
	for (int i = 0; i < n; i++)
		reading >> a[i];
	
	cmp_cnt = 0;
	start = clock();
	flash_sort(a,n);
	end = clock();
	flash_sort_with_counter(a, n, cmp_cnt);
	duration = (double)(end - start) / CLOCKS_PER_SEC;
	result << cmp_cnt << " " << duration << endl;
	
	cout << "Flash Sort done!" << endl;
	
	reading.close();
	result.close();
	delete[] a;
	return 0;
}
