/**
 * Shaker Sort (Referenced from Dr. Nguyen Ngoc Thao's lecture notes)
 * Average Case: O(n^2)
 * Best Case: O(n)
 * Worst Case: O(n^2)
 * Space complexity: O(1)
 */
void shaker_sort(int a[], int n)
{
    int left = 0, right = n - 1, k = 0;
    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

void shaker_sort_with_counter(int a[], int n, long long &comparision_count)
{
    int left = 0, right = n - 1, k = 0;
    while (++comparision_count && left < right)
    {
        for (int i = left; ++comparision_count && i < right; i++)
        {
            if (++comparision_count && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; ++comparision_count && i > left; i--)
        {
            if (++comparision_count && a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}