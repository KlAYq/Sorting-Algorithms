int findMid(int a[], int left, int right)
{
	int mid = (left + right) / 2;
	if (a[mid] < a[left])
		swap(a[mid], a[left]);
	if (a[right] < a[mid])
		swap(a[mid], a[right]);
	if (a[mid] < a[left])
		swap(a[mid], a[left]);

	swap(a[mid], a[left]);
	return mid;
}

int partition(int a[], int left, int right)
{
	findMid(a, left, right);
	int pivot = a[left];
	int k = right;
	for (int i = right; i > left; i--)
	{
		if (a[i] > pivot)
		{
			swap(a[i], a[k]);
			k--;
		}
	}
	swap(a[k], a[left]);
	return k;
}

void quick_sort(int a[], int left, int right)
{ // with 1 index - geeksforgeeks
	if (left < right)
	{
		int pvind = partition(a, left, right);
		quick_sort(a, left, pvind - 1);
		quick_sort(a, pvind + 1, right);
	}
}

/*===========================================================================*/

int findMid_with_counter(int a[], int left, int right, long long &comparision_count)
{
	int mid = (left + right) / 2;
	if (++comparision_count && a[mid] < a[left])
		swap(a[mid], a[left]);
	if (++comparision_count && a[right] < a[mid])
		swap(a[mid], a[right]);
	if (++comparision_count && a[mid] < a[left])
		swap(a[mid], a[left]);

	swap(a[mid], a[left]);
	return mid;
}

int partition_with_counter(int a[], int left, int right, long long &comparision_count)
{
	findMid_with_counter(a, left, right, comparision_count);
	int pivot = a[left];
	int k = right;
	for (int i = right; ++comparision_count && i > left; i--)
	{
		if (++comparision_count && a[i] > pivot)
		{
			swap(a[i], a[k]);
			k--;
		}
	}
	swap(a[k], a[left]);
	return k;
}

void quick_sort_with_counter(int a[], int left, int right, long long &comparision_count)
{ // with 1 index - geeksforgeeks
	if (++comparision_count && left < right)
	{
		int pvind = partition_with_counter(a, left, right, comparision_count);
		quick_sort_with_counter(a, left, pvind - 1, comparision_count);
		quick_sort_with_counter(a, pvind + 1, right, comparision_count);
	}
}