/**
 * Bubble_sort
 * Average case: O(n^2)
 * Best case: O(n^2)
 * Worst case: O(n^2)
 * Space complexity: O(1)
*/

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            //If two consecutive elements are not in the correct order, swap them.
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void bubble_sort_with_counter(int a[], int n, long long &comparison_count) {   //Count the number of element comparisons.
    for (int i = 0;++comparison_count && i < n - 1; i++) {
        for (int j = 0;++comparison_count && j < n - i; j++) {
            //If two consecutive elements are not in the correct order, swap them.
            if (++comparison_count && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

void optimized_bubble_sort(int a[], int n)
{
    bool swapped;   //It is used to check if there was any swap in the last iteration.
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
  
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

void optimized_bubble_sort_with_counter(int a[], int n, long long &comparison_count)
{
    bool swapped;   //It is used to check if there was any swap in the last iteration.
    for (int i = 0;++comparison_count && i < n - 1; i++) {
        swapped = false;
        for (int j = 0;++comparison_count && j < n - i - 1; j++) {
            if (++comparison_count && a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
  
        // If no two elements were swapped
        // by inner loop, then break
        if (++comparison_count && swapped == false)
            break;
    }
}