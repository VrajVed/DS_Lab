#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[5] = {64, 25, 12, 22, 11};

    int n = 5;

    int i, j, min;

    printf("Before: ");

    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    for (i = 0; i < n - 1; ++i)
    {
        min = i;
        for (j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }

    printf("After:  ");
    for (i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}