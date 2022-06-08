#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int lcs(char s1[], char s2[], int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (s1[n - 1] == s2[m - 1])
    {
        return 1 + lcs(s1, s2, n - 1, m - 1);
    }
    return max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}

int main()
{
    char s1[10], s2[10];
    printf("Enter the string 1:\n");
    gets(s1);
    printf("Enter the string 2:\n");
    gets(s2);
    int n = strlen(s1);
    int m = strlen(s2);
    printf("%d", lcs(s1, s2, n, m));
    return 0;
}

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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