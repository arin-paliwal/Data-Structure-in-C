#include <stdio.h>

void countingSort(int arr[], int n, int place)
{
    int output[n + 1];
    int max = (arr[0] / place) % 10;
    for (int i = 1; i < n; i++)
    {
        if (((arr[i] / place) % 10) > max)
            max = arr[i];
    }
    int count[max + 1];

    for (int i = 0; i < max; ++i)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void bubblesort(int arr[], int n)
{
    for (int step = 0; step < n - 1; ++step)
    {
        for (int i = 0; i < n - step - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
void radixsort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(arr, n, place);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int arr[], int n)
{
    for (int step = 0; step < n - 1; step++)
    {
        int min_index = step;
        for (int i = step + 1; i < n; i++)
        {
            if (arr[i] < arr[min_index])
                min_index = i;
        }
        swap(&arr[min_index], &arr[step]);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
void insertion(int arr[], int n)
{
    for (int step = 1; step < n; step++)
    {
        int key = arr[step];
        int j = step - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void countingsort(int array[], int size)
{
    int output[10];
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    int count[10];
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
}

int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the Array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Select 1 for Bubble Sort\n");
    printf("Select 2 for Selection Sort\n");
    printf("Select 3 for Insertion Sort\n");
    printf("Select 4 for Count Sort\n");
    printf("Select 5 for Radix Sort\n");
    int c;
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        bubblesort(arr, n);
        break;
    case 2:
        selection(arr, n);
        break;
    case 3:
        insertion(arr, n);
        break;
    case 4:
        countingsort(arr, n);
        break;
    case 5:
        radixsort(arr, n);
        break;

    default:
        printf("Enter valid choice");
        break;
    }
}