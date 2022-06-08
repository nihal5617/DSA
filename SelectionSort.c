#include <stdio.h>
#include <time.h>
void selectionSort(int arr[], int n)
{
    double time = 0.0;
    clock_t begin = clock();
    int i, j, min_idx, count = 0, swap = 0;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            count += 1;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            swap += 1;
        }
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("\nThe elapsed time is %f seconds", time);
    printf("Comparisons = %d, Swaps = %d\n", count, swap);
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

    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}