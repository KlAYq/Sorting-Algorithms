/**
 * Insertion Sort
 * Average case: O(n^2)
 * Best case: O(n)
 * Worst case: O(n^2)
 * Space complexity: O(1)
*/
void insertion_sort(int a[], int n)
{
    // Find the right position in the sorted region arr[0..i-1]
    // for arr[i]; shift, if necessary, to make room
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void insertion_sort_with_counter(int a[], int n, long long &comparison_count)
{
    comparison_count = 0;
    for (int i = 1; ++comparison_count && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (++++comparison_count && j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}