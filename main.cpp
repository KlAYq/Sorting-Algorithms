#include <iostream>
#include "DataGenerator.cpp"

void printData(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

// MERGE SORT 
void merge(int arr[], int left, int mid, int right)
{
    int tempArr[500000]; // will fix later
    int tempIndex = left;
    int index1 = left, index2 = mid+1; 
    while (index1 <= mid && index2 <= right)
    {
        if (arr[index1] < arr[index2])
            tempArr[tempIndex++] = arr[index1++];
        else
            tempArr[tempIndex++] = arr[index2++];
    }

    while (index1 <= mid)
        tempArr[tempIndex++] = arr[index1++];
    while (index2 <= right)
        tempArr[tempIndex++] = arr[index2++];
    
    for (tempIndex = left; tempIndex <= right; tempIndex++)
        arr[tempIndex] = tempArr[tempIndex];
}   

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
// FLASH SORT
void flashSort(int arr[], int n)
{

}


int main()
{
    int n = 10;
    int a[n];
    GenerateData(a, n, 0);
    mergeSort(a, 0, n-1);
    printData(a, n);
}