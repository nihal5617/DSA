#include <stdio.h>
#include <limits.h>
#include <string.h>

int dp[100][100];
int mcm(int arr[], int i, int j)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int count, min = INT_MAX;

    for (int k = i; k < j; k++)
    {
        count = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        if (count < min)
            min = count;
    }
    dp[i][j] = min;
    return dp[i][j];
}

int main()
{
    int n, arr[10];
    memset(dp, -1, sizeof dp);
    printf("Enter the number of matrices:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", mcm(arr, 1, n - 1));
}
