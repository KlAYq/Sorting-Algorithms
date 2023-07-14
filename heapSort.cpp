#include <iostream>

using namespace std;

//This function heapify a subtree with node i
void heapify(int a[], int n, int i) {
    //Initialize largest as root
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && a[largest] < a[left])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && a[largest] < a[right])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(a[largest], a[i]);

        //Recursively heapify the affected subtree
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    //Build max heap
    for (int  i = (n - 2) / 2; i >= 0; i--)
        heapify(a, n, i);
    
    for (int heapSize = n - 1; heapSize > 0; heapSize--) {
        //Move the root (largest element) to the end
        swap(a[0], a[heapSize]);

        //(Max) heapify the new heap
        heapify(a, heapSize, 0);
    }
}

//Heapify with comparison counter
void heapify_with_counter(int a[], int n, int i, int &comparison_count) {
    //Initialize largest as root
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && ++comparison_count && a[largest] < a[left])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && ++comparison_count && a[largest] < a[right])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(a[largest], a[i]);

        //Recursively heapify the affected subtree
        heapify_with_counter(a, n, largest, comparison_count);
    }
}

//Heap sort with comparison counter
void heapSort_with_counter(int a[], int n, int &comparison_count) {
    comparison_count = 0;
    //Build max heap
    for (int  i = (n - 2) / 2; i >= 0; i--)
        heapify_with_counter(a, n, i, comparison_count);
    
    for (int heapSize = n - 1; heapSize > 0; heapSize--) {
        //Move the root (largest element) to the end
        swap(a[0], a[heapSize]);

        //(Max) heapify the new heap
        heapify_with_counter(a, heapSize, 0, comparison_count);
    }
}