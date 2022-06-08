#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter number of vertices:\n");
    int graph[n][n];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int dist[n];
    dist[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        dist[i] = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (graph[i][j] == INT_MAX)
                continue;
            dist[i] = min(dist[i], graph[i][j] + dist[j])
        }
    }
    return 0;
}