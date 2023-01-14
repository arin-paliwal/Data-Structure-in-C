#include <stdio.h>
#include <stdio.h>

void linear_search(int a[], int n, int x)
{
    int i, flag = 0;
    for (i = 0; i < n; ++i)
    {
        if (a[i] == x)
        {
            flag++;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Not found! %d isn't present in the list", x);
    }
    else
    {
        printf("Element %d Found at Index %d", x, i);
    }
}

void binary_search(int array[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2;
    while (low <= high)
    {
        if (array[mid] < key)
            low = mid + 1;
        else if (array[mid] == key)
        {
            printf("%d found at location %d", key, mid + 1);
            break;
        }
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }
    if (low > high)
        printf("Not found! %d isn't present in the list", key);
}

int main()
{
    int n;
    printf("Select 1 for Linear Search\n");
    printf("Select 2 for Binary Search\n");
    int c;
    scanf("%d", &c);
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    switch (c)
    {
    case 1:
    {
        printf("Enter the elements of the Array\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("Enter the Element to be searched\n");
        int k;
        scanf("%d", &k);
        linear_search(arr, n, k);
        break;
    }

    case 2:
    {
        printf("Enter the elements of the array in a sorted form\n");
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("Enter the Element to be searched\n");
        int k;
        scanf("%d", &k);
        binary_search(arr, n, k);
        break;
    }
    default:
    {
        printf("Enter valid choice");
        break;
    }
    }
}