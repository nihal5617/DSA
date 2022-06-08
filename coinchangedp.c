#include <stdio.h>
#include <limits.h>
#define INF 999;

int min(int a, int b)
{
    return a < b ? a : b;
}

int dp[100][100];

int coinchange(int a[], int n, int total)
{
    if (total < 0)
        return INF;
    if (total == 0)
        return 0;
    if (n == -1)
        return INF;
    if (dp[total][n] != -1)
        return dp[total][n];
    int in = INF;
    int out = INF;

    in = 1 + coinchange(a, n, total - a[n]);
    out = coinchange(a, n - 1, total);
    dp[total][n] = min(in, out);
    return dp[total][n];
}

int main()
{
    memset(dp, -1, sizeof dp);
    int n, total;
    printf("Enter number of coins:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the coins:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the total value required:\n");
    scanf("%d", &total);
    printf("The minimum required coins are %d", coinchange(a, n - 1, total));
}