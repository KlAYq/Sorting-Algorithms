void merge(int arr[], int left, int mid, int right)
{
    int tempArr[right - left + 1]; // will fix later
    int tempIndex = 0;
    int index1 = left, index2 = mid+1; 
    while (index1 <= mid && index2 <= right)
    {
        if (arr[index1] < arr[index2])
            tempArr[tempIndex++] = arr[index1++];
        else
            tempArr[tempIndex++] = arr[index2++];
    }

    while (index1 <= mid)
        tempArr[tempIndex++] = arr[index1++];
    while (index2 <= right)
        tempArr[tempIndex++] = arr[index2++];
    
    for (tempIndex = 0; tempIndex < right - left + 1; tempIndex++)
        arr[tempIndex + left] = tempArr[tempIndex];
}   

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left+right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void merge_with_counter(int arr[], int left, int mid, int right, long long& comparison_count)
{
    int tempArr[right - left + 1]; // will fix later
    int tempIndex = 0;
    int index1 = left, index2 = mid+1; 
    while (++comparison_count && index1 <= mid && ++comparison_count && index2 <= right)
    {
        if (++comparison_count && arr[index1] < arr[index2])
            tempArr[tempIndex++] = arr[index1++];
        else
            tempArr[tempIndex++] = arr[index2++];
    }

    while (++comparison_count && index1 <= mid)
        tempArr[tempIndex++] = arr[index1++];
    while (++comparison_count && index2 <= right)
        tempArr[tempIndex++] = arr[index2++];
    
    for (tempIndex = left; tempIndex < right - left + 1; tempIndex++)
        arr[tempIndex + left] = tempArr[tempIndex];
}   

void merge_sort_with_counter(int arr[], int left, int right, long long& comparison_count)
{
    if (++comparison_count && left < right)
    {
        int mid = (left+right)/2;
        merge_sort_with_counter(arr, left, mid, comparison_count);
        merge_sort_with_counter(arr, mid+1, right, comparison_count);
        merge_with_counter(arr, left, mid, right, comparison_count);
    }
}