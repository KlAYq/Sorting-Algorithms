void insertion_sort(int a[], int low, int high)
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
void flash_sort(int a[], int n)
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
    int* count = new int[m];
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
    delete[] count;
    insertion_sort(a, 0, n-1);
}

void insertion_sort_with_counter(int a[], int low, int high, long long& comparison_count)
{
    for (int i = low + 1; ++comparison_count && i <= high; i++) {
        int key = a[i];
        int j = i - 1;

        while (++comparison_count && j >= low && ++comparison_count && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

// Flashsort implementation
// REF: https://codelearn.io/sharing/flash-sort-thuat-toan-sap-xep-than-thanh 
void flash_sort_with_counter(int a[], int n, long long& comparison_count)
{
    // Minimum and maximum values in the input array
    int minVal = a[0];
    int maxVal = a[0];

    // Finding the minimum and maximum values
    for (int i = 1; i < n; i++) {
        if (++comparison_count && a[i] < minVal)
            minVal = a[i];
        if (++comparison_count && a[i] > maxVal)
            maxVal = a[i];
    }
    // Creating the distribution count array
    int m = 0.45 * n;
    int count[m];
    fill(count, count + m, 0);
    // for (int i = 0; ++comparison_count && i < m; i++)
    //     count[m] = 0;
    int coefficient = (m-1)/double(maxVal - minVal);

    // Counting the elements within each bucket
    for (int i = 0; ++comparison_count && i < n; i++) {
        int k =  (a[i] - minVal)*coefficient;
        count[k]++;
    }
    // Calculating the starting positions of each bucket
    for (int i = 1; ++comparison_count && i < m; i++) {
        count[i] += count[i - 1];
    }

    // Performing the flash pass
    int pass = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (pass < n - 1)
	{
		while (++comparison_count && j > count[k] - 1)
		{
			j++;
			k = int(coefficient*(a[j] - minVal));
		}
		flash = a[j];
		if (++comparison_count && k < 0) break;
		while (++comparison_count && j != count[k])
		{
			k = int(coefficient*(flash - minVal));
            t = --count[k];
			int hold = a[t];
			a[t] = flash;
			flash = hold;
			++pass;
		}
	}
    insertion_sort_with_counter(a, 0, n-1, comparison_count);
}