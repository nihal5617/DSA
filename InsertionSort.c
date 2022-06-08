#include <stdio.h>
#include <time.h>
void insertionSort(int arr[], int n)
{
    double time = 0.0;
    clock_t begin = clock();
    int i, key, j, count = 0, shift = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        . ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            shift += 1;
            count += 1;
        }
        arr[j + 1] = key;
        if (j >= 0)
            count += 1;
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Comparisons = %d, Shift = %d\n", count, shift);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}