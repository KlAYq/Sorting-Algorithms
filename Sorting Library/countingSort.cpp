/**
 * Counting Sort
 * Average case: O(n)
 * Space complexity: O(n)
*/
void counting_sort(int a[], int n)
{
    // find the maximum value
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    // perform distribution counting
    int *countArr = new int [max+1] {0};
    for (int i = 0; i < n; i++)
        countArr[a[i]]++;
    // accumulate sum of frequencies
    for (int i = 1; i < max + 1; i++)
        countArr[i] += countArr[i-1];
    // distribute values to their final positions
    int *tempArr = new int [n];
    for (int i = n - 1; i >= 0; i--)
        tempArr[--countArr[a[i]]] = a[i];
    // adding value to the source array
    for (int i = 0; i < n; i++)
        a[i] = tempArr[i];

    delete countArr;
    delete tempArr;
}

void counting_sort_with_counter(int a[], int n, long long &comparison_count)
{
    comparison_count = 0; 

    int max = a[0];
    for (int i = 1; ++comparison_count && i < n; i++)
        if (a[i] > max)
            max = a[i];

    int *countArr = new int [max+1] {0};
    for (int i = 0; ++comparison_count && i < n; i++)
        countArr[a[i]]++;

    for (int i = 1; ++comparison_count && i < max + 1; i++)
        countArr[i] += countArr[i-1];

    int *tempArr = new int [n];
    for (int i = n - 1; ++comparison_count && i >= 0; i--)
        tempArr[--countArr[a[i]]] = a[i];

    for (int i = 0; ++comparison_count && i < n; i++)
        a[i] = tempArr[i];

    delete countArr;
    delete tempArr;
}