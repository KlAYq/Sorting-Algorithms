void selection_sort(int a[], int n)
{
	int min_idx = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;

		swap(a[i], a[min_idx]);
	}
}

void selection_sort_with_counter(int a[], int n, long long &comparision_count)
{
	int min_idx = 0;
	for (int i = 0; ++comparision_count && i < n - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; ++comparision_count && j < n; j++)
			if (++comparision_count && a[j] < a[min_idx])
				min_idx = j;

		swap(a[i], a[min_idx]);
	}
}