

void insertionSort(int a[], int low, int high)
{
    for (int i = low + 1; i <= high; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= low && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Flashsort implementation
// REF: https://codelearn.io/sharing/flash-sort-thuat-toan-sap-xep-than-thanh 
void flashSort(int a[], int n)
{
    // Minimum and maximum values in the input array
    int minVal = a[0];
    int maxVal = a[0];

    // Finding the minimum and maximum values
    for (int i = 1; i < n; i++) {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > maxVal)
            maxVal = a[i];
    }
    // Creating the distribution count array
    int m = 0.45 * n;
    int count[m];
    fill(count, count + m, 0);
    int coefficient = (m-1)/double(maxVal - minVal);

    // Counting the elements within each bucket
    for (int i = 0; i < n; i++) {
        int k =  (a[i] - minVal)*coefficient;
        count[k]++;
    }
    // Calculating the starting positions of each bucket
    for (int i = 1; i < m; i++) {
        count[i] += count[i - 1];
    }

    // Performing the flash pass
    
    // // Sorting the elements within each bucket using insertion sort
    // for (int i = 1; i < m; i++) {
    //     int low = count[i - 1];
    //     int high = count[i] - 1;

    //     if (high - low > 0)
    //         insertionSort(a, low, high);
    // }
    // Sorting the elements within each bucket using insertion sort

    int pass = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (pass < n - 1)
	{
		while (j > count[k] - 1)
		{
			j++;
			k = int(coefficient*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != count[k])
		{
			k = int(coefficient*(flash - minVal));
            t = --count[k];
			int hold = a[t];
			a[t] = flash;
			flash = hold;
			++pass;
		}
	}
    insertionSort(a, 0, n-1);
}