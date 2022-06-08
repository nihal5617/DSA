#include <stdio.h>

int ascendingBinarySearch(int arr[], int low, int high, int key) //O(logn)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int descendingBinarySearch(int arr[], int low, int high, int key) //O(logn)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int findBitonicPoint(int arr[], int n, int l, int r) //O(logn)
{
    if (l == r)
        return r;
    int mid;
    int bitonicPoint = -1;
    mid = (r + l) / 2;

    if (mid == 0 || (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]))
    {
        return mid;
    }

    else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
    {
        bitonicPoint = findBitonicPoint(arr, n, mid + 1, r);
    }

    else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
        bitonicPoint = findBitonicPoint(arr, n, l, mid - 1);
    }
    return bitonicPoint;
}

int findMinima(int arr[], int n, int l, int r) //O(logn)
{
    if (l == r)
        return r;
    int mid;
    int minima = 0;
    mid = (r + l) / 2;
    if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1])
    {
        printf("%d\n", mid);
        return mid;
    }

    else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1])
    {
        minima = findMinima(arr, n, mid + 1, r);
    }

    else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
    {
        minima = findMinima(arr, n, l, mid - 1);
    }
    return minima;
}

int searchBitonic(int arr[], int n, int key, int index, int minima) //O(logn)
{
    if (key > arr[index])
        return -1;

    else if (key == arr[index])
        return index;

    else
    {
        int asc = ascendingBinarySearch(arr, 0, index - 1, key);
        if (asc != -1)
        {
            return asc;
        }
        int desc = descendingBinarySearch(arr, index + 1, minima, key);
        if (desc != -1)
        {
            return desc;
        }
        return ascendingBinarySearch(arr, minima, n - 1, key);
    }
}

int main()
{
    int n, index, key, minima;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n], l = 0, r = n - 1;
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    index = findBitonicPoint(arr, n, l, r);
    minima = findMinima(arr, n, index, r);
    printf("Enter the element to search: ");
    scanf("%d", &key);

    int x = searchBitonic(arr, n, key, index, minima);

    if (x == -1)
        printf("Element not found");
    else
        printf("Element found at index %d", x);
    return 0;
}