#include <stdio.h>

int Binary_asc(int arr[], int l, int h, int key)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Binary_desc(int arr[], int l, int h, int key)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
// finding bitonic point
int findBitonicPoint(int arr[], int n, int l, int r)
{
    int mid;
    int bitonicPoint = 0;
    mid = (r + l) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
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
// Function to search key in bitonic array
int searchBitonic(int arr[], int n, int key, int index)
{
    if (key > arr[index])
        return -1;
    else if (key == arr[index])
        return index;
    else
    {
        // Search in left of key
        int temp = Binary_asc(arr, 0, index - 1, key);
        if (temp != -1)
        {
            return temp;
        }
        // Search in right of key
        return Binary_desc(arr, index + 1, n - 1, key);
    }
}
int searchShiftPoint(int arr[], int index, int n)
{
    int k = -1;
    for (int i = index; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
            return i;
    }
    return -1;
}

int main()
{
    int n, key, index;
    printf("Enter number of elements of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter bitonic Array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number you want to search: ");
    scanf("%d", &key);
    // Function call
    index = findBitonicPoint(arr, n, 0, n - 1);
    printf("%d", index);
    int s = searchShiftPoint(arr, index + 1, n);
    printf("%d", s);
    if (s == -1)
    {
        int x = searchBitonic(arr, n, key, index);
        if (x == -1)
            printf("Element Not Found\n");
        else
            printf("The element is present at index: %d \n", x);
    }
    else
    {
        int x = searchBitonic(arr, s + 1, key, index);
        if (x != -1)
            printf("The element is present at index: %d \n", x);
        else
        {
            int z = Binary_asc(arr, s + 1, n - 1, key);
            if (z == -1)
                printf("Element Not Found\n");
            else
                printf("The element is present at index: %d \n", z);
        }
    }
    return 0;
}