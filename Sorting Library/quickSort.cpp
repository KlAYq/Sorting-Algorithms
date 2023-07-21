#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

int partition(int a[], int left, int right)
{
	int pivot = a[left];
	int k = right;
	for (int i = right; i > left; i--)
	{
		if (a[i] > pivot)
		{
			Swap(a[i], a[k]);
			k--;
		}
	}
	Swap(a[k], a[left]);
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

int partition_with_counter(int a[], int left, int right, long long &comparision_count)
{
	int pivot = a[left];
	int k = right;
	for (int i = right; ++comparision_count && i > left; i--)
	{
		if (++comparision_count && a[i] > pivot)
		{
			Swap(a[i], a[k]);
			k--;
		}
	}
	Swap(a[k], a[left]);
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
