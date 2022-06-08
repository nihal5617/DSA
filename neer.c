#include <stdio.h>
#include <stdlib.h>

struct faculty
{
    char faculty_name[10];
    int faculty_id;
    int subject_codes;
    char class_names[10];
};

// A utility function to get maximum value in arr[]
int getMax(struct faculty arr[], int n)
{
    int mx = arr[0].faculty_id;
    for (int i = 1; i < n; i++)
        if (arr[i].faculty_id > mx)
            mx = arr[i].faculty_id;
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(struct faculty arr[], int n, int exp)
{
    struct faculty output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i].faculty_id / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i].faculty_id / exp) % 10] - 1] = arr[i];
        count[(arr[i].faculty_id / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(struct faculty arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(struct faculty arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%s %d %d %s\n",arr[i].faculty_name ,arr[i].faculty_id, arr[i].subject_codes, arr[i].class_names);
}

int main()
{
    int n;
    struct faculty DJ[10];
    printf("Enter the number of members: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the info of member %d: ",i+1);
        scanf("%s",&DJ[i].faculty_name);
        scanf("%d", &DJ[i].faculty_id);
        scanf("%d", &DJ[i].subject_codes);
        scanf("%s", &DJ[i].class_names);
    }
    radixsort(DJ,n);
    print(DJ,n);
}