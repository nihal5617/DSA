#include <stdio.h>
#include <string.h>

int bubblesort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int setdiff(int curr[], int arr[], int n, int m)
{
    int i, j, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (curr[i] == arr[j])
                break;
        }
        if (j == m)
            count++;
    }
    return count;
}

int main()
{
    int n, m;
    printf("Enter of number of items required:\n");
    scanf("%d", &n);
    int arr[n], curr[n];
    memset(curr, 0, sizeof curr);
    printf("Enter %d items:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of sets:\n");
    scanf("%d", &m);
    int cost[m];
    float ratio[m];
    for (int i = 0; i < m; i++)
    {
        int k;
        printf("Enter number of items in set %d:\n", i + 1);
        scanf("%d", &k);
        int set[k];
        printf("Enter the items in set %d:\n", i + 1);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &set[j]);
        }
        printf("Enter the cost of set %d:\n", i + 1);
        scanf("%d", &cost[i]);
        float new = setdiff(set, curr, k, n);
        ratio[i] = cost[i] / new;
    }
    // print ratio
    for (int i = 0; i < m; i++)
    {
        printf("%f\n", ratio[i]);
    }
    // select the set with maximum ratio
    int max = 0;
    for (int i = 0; i < m; i++)
    {
        if (ratio[i] > ratio[max])
            max = i;
    }
    printf("The set with maximum ratio is %d\n", max + 1);
    // add the items to the current set
    // int a = sizeof(arr[]) for (int i = 0; i < n; i++)
    // {
    // }

    return 0;
}
