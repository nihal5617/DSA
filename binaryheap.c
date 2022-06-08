#include <stdio.h>
#include <math.h>

int H[50];
int size = -1;

int parent(int i)
{
    return (i - 1) / 2;
}

int leftChild(int i)
{
    return ((2 * i) + 1);
}

int rightChild(int i)
{
    return ((2 * i) + 2);
}

int isEmpty()
{
    if (size == -1)
        return 0;
    else
        return 1;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i])
    {
        swap(&H[parent(i)], &H[i]);
        i = parent(i);
    }
}

void shiftDown(int i)
{
    int maxIndex = i;

    int l = leftChild(i);
    if (l <= size && H[l] > H[maxIndex])
    {
        maxIndex = l;
    }

    int r = rightChild(i);

    if (r <= size && H[r] > H[maxIndex])
    {
        maxIndex = r;
    }

    if (i != maxIndex)
    {
        swap(&H[i], &H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p)
{

    H[++size] = p;
    shiftUp(size);
}

int extractMax()
{
    int result = H[0];
    H[0] = H[size--];
    shiftDown(0);
    return result;
}

void changePriority(int i, int p)
{
    int oldp = H[i];
    H[i] = p;

    if (p > oldp)
    {
        shiftUp(i);
    }
    else
    {
        shiftDown(i);
    }
}

int getMax()
{
    return H[0];
}

void remove_ele(int i)
{
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int height(int n)
{
    return floor(log2(n));
}

int main()
{
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        insert(k);
    }
    printf("Priority Queue: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", H[i]);
    }
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", extractMax());
    }

    return 0;
}