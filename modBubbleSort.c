#include <stdio.h>
#include <time.h>
int main()
{
    int count=0, swap=0, swapped, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    double time = 0.0;
    clock_t begin = clock();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            count += 1;
            swapped = 1;
            if (arr[j] > arr[j + 1])
            {
                swap += 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 0;
            }
        }
        if (swapped)
            break;
    }
    clock_t end = clock();
    time += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Comparisons = %d, Swaps = %d\n", count, swap);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}