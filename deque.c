#include <stdio.h>
#include <ctype.h>
#include <math.h>

int arr[100];
int rear = -1;
int front = -1;

int isempty()
{
    if (front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

int isfull()
{
    if (rear == 99)
        return 1;
    else
        return 0;
}

void EnqueueR(int index)
{
    if (isfull())
        return;
    else if (isempty())
        front = 0, rear = 0;
    else
        rear = rear + 1;
    arr[rear] = index;
}

int dequeueF()
{
    if (isempty())
        return 0;
    else if (front == rear)
    {
        front = -1, rear = -1;
        return arr[front];
    }
    else
        return arr[front++];
}

int dequeueR()
{
    if (isempty())
        return 0;
    else if (front == rear)
    {
        front = -1, rear = -1;
        return arr[rear];
    }
    else
        return arr[rear--];
}

int main()
{
    int n, k;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int nums[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("Enter the window size:\n");
    scanf("%d", &k);
    EnqueueR(0);
    for (int i = 0; i < k; i++) // to form initial window
    {
        if (nums[i] >= nums[i - 1])
        {
            dequeueR();
            EnqueueR(i);
        }
    }
    printf("%d ", nums[arr[0]]);

    for (int i = k; i < n; i++)
    {
        while (front != -1 && arr[front] <= i - k) // remove the element index which falls outside the window
        {
            dequeueF();
        }
        while (rear != -1 && nums[i] >= nums[arr[rear]]) // remove smaller elements indexes from the deque
        {
            dequeueR();
        }
        EnqueueR(i); // append current index
        printf("%d ", nums[arr[front]]);
    }
}
