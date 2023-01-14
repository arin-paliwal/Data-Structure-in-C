void merge_sort(int a[], int start, int end)
{
    int temp = end;
    if (start < end)
    {
        int mid = ((start + end) / 2);
        merge_sort(a, start, mid);
        merge_sort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
}
void merge(int arr[], int start, int mid, int end)
{
    int len1 = mid - start + 1;
    int len2 = end - mid;
    int left_arr[len1];
    int right_arr[len2];
    for (int i = 0; i < len1; i++)
    {
        left_arr[i] = arr[start + i];
    }
    for (int i = 0; i < len2; i++)
        right_arr[i] = arr[mid + 1 + i];
    int i = 0, k = start, j = 0;
    while (i < len1 && j < len2)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j += 1;
        }
        k += 1;
    }
    while (i < len1)
    {
        arr[k] = left_arr[i];
        i += 1;
        k += 1;
    }
    while (j < len2)
    {
        arr[k] = right_arr[j];
        j += 1;
        k += 1;
    }
}

void quick_sort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quick_sort(arr, p, q - 1);
        quick_sort(arr, q + 1, r);
    }
}
int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i += 1;
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int t;
    t = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = t;
    return i + 1;
}

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    int start = 0, end = n - 1;
    printf("Enter the elements of the Array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Select 1 for Merge Sort\n");
    printf("Select 2 for Quick Sort\n");
    int c;
    scanf("%d", &c);
    switch (c)
    {
    case 1:
    {
        merge_sort(arr, start, end);
        printArray(arr, n);
        break;
    }
    case 2:
    {
        quick_sort(arr, start, end);
        printArray(arr, n);
        break;
    }
    default:
        printf("Enter valid choice");
        break;
    }
}