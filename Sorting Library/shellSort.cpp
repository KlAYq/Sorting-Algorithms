
void shell_sort(int a[], int n)
{
	int temp;
	for (int range = n / 2; range > 0; range /= 2)
		for (int i = range; i < n; i++)
		{
			temp = a[i];

			int j;
			for (j = i; j >= range && a[j - range] > temp; j -= range)
				a[j] = a[j - range];
			a[j] = temp;
		}
}

void shell_sort_with_counter(int a[], int n, long long &comparision_count)
{
	int temp;
	for (int range = n / 2; ++comparision_count && range > 0; range /= 2)
		for (int i = range; ++comparision_count && i < n; i++)
		{
			temp = a[i];

			int j;
			for (j = i; ++comparision_count && j >= range && ++comparision_count && a[j - range] > temp; j -= range)
				a[j] = a[j - range];
			a[j] = temp;
		}
}