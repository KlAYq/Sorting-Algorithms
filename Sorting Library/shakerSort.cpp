/**
 * Shaker Sort
 * Average Case: O(n^2)
 * Best Case: O(n)
 * Worst Case: O(n^2)
 * Space complexity: O(1)
*/

void shaker_sort(int a[], int n) {
    int left = 1, right = n - 1, k = 1; 
    do {
        // loop from left to right same as
        // the bubble sort
        for (int j = left; j <= right; j++) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                k = j;  //Save the position of the last exchange
            }
        }   //Larger elements to the end

        //As all the items after k is in correct order,
        //move the 'right' to k - 1
        right = k - 1; 

        // from right to left, doing the
        // same comparison as in the previous stage
        for (int j = right; j >= left; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                k = j;  //Save the position of the last exchange
            }
        }   //Smaller elements to the top

        //As all the items before k is in correct order, 
        //move the 'left' to k + 1
        left = k + 1;

    } while (left <= right);
}

void shaker_sort_with_counter(int a[], int n, long long &comparision_count) {
    comparision_count = 0;
    int left = 1, right = n - 1, k = 1; 
    do {
        // loop from left to right same as
        // the bubble sort
        for (int j = left; j <= right; j++) {
            if (++comparision_count && a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                k = j;  //Save the position of the last exchange
            }
        }   //Larger elements to the end

        right = k - 1;  //As all the items after k is in correct order, move the right to k - 1

        // from right to left, doing the
        // same comparison as in the previous stage
        for (int j = right; j >= left; j--) {
            if (++comparision_count && a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                k = j;  //Save the position of the last exchange
            }
        }   //Smaller elements to the top

        left = k + 1; //As all the items before k is in correct order, move the left to k + 1

    } while (left <= right);
}