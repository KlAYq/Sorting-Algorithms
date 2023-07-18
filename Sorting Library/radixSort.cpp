/**
 * Counting Sort
 * Average case: O(n)
 * Space complexity: O(n)
*/
void radix_sort(int a[], int n)
{
    // get maximum value in the array
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    
    // find the maximum number of digits
    int num_nums = 0;
    while (max > 0)
    {
        num_nums++;
        max /= 10;
    }

    // declare variables for temp store
    int **tempArr = new int *[10];
    for (int i = 0; i < 10; i++)
        tempArr[i] = new int [n];

    // form groups of numbers and combine groups
    for (int i = 0; i < num_nums; i++)
    {
        int count[10] = {0};
        int div = 1;
        for (int j = 0; j < i; j++)
            div *= 10;
        // form groups
        for (int j = 0; j < n; j++)
        {
            int idx = (a[j] / div) % 10;
            tempArr[idx][count[idx]] = a[j];
            count[idx]++;
        }
        // combine groups
        int idx = 0;
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < count[j]; k++)
            {
                a[idx] = tempArr[j][k];
                idx++;
            }
    }
    for (int i = 0; i < 10; i++)
        delete tempArr[i];
    delete tempArr;
}

void radix_sort_with_counter(int a[], int n, long long &comparison_count)
{
    comparison_count = 0;
    int max = a[0];
    for (int i = 0; ++comparison_count && i < n; i++)
        if (a[i] > max)
            max = a[i];

    int num_nums = 0;
    while ( ++comparison_count && max > 0)
    {
        num_nums++;
        max /= 10;
    }

    int **tempArr = new int *[10];
    for (int i = 0; ++comparison_count && i < 10; i++)
        tempArr[i] = new int [n];

    for (int i = 0; ++comparison_count && i < num_nums; i++)
    {
        int count[10] = {0};
        int div = 1;
        for (int j = 0; ++comparison_count && j < i; j++)
            div *= 10;

        for (int j = 0; ++comparison_count && j < n; j++)
        {
            int idx = (a[j] / div) % 10;
            tempArr[idx][count[idx]] = a[j];
            count[idx]++;
        }

        int idx = 0;
        for (int j = 0; ++comparison_count && j < 10; j++)
            for (int k = 0; ++comparison_count && k < count[j]; k++)
            {
                a[idx] = tempArr[j][k];
                idx++;
            }
    }
    for (int i = 0; ++comparison_count && i < 10; i++)
        delete tempArr[i];
    delete tempArr;
}