#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) // this swaps the pointers using temp variable and pointers
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot is set to high
    int i = low - 1;       //
    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    if (printf("Enter number of elements: ") && scanf("%d", &n) != 1)
        return 1;

    if (n <= 0)
        return 0;

    int *arr = malloc(sizeof(int) * n);
    if (!arr)
        return 1;

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            free(arr);
            return 1;
        }
    }

    printf("Before: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("After:  ");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}