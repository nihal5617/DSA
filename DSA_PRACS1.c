#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *newNode(int d, int p)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

int peek(struct node **head)
{
    return (*head)->data;
}

void dequeue(struct node **head)
{
    struct node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void enqueue(struct node **head, int d, int p)
{
    struct node *start = (*head);

    struct node *temp = newNode(d, p);

    if ((*head)->priority > p)
    {

        temp->next = *head;
        (*head) = temp;
    }
    else
    {

        while (start->next != NULL &&
               start->next->priority <= p)
        {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

int isEmpty(struct node **head)
{
    return (*head) == NULL;
}

void display(struct node **head)
{
    struct node *start = (*head);
    while (start)
    {
        printf("%d ", start->data);
        start = start->next;
    }
}

void front(struct node **head){
    printf("%d is front element.", peek(head));
}

int main()
{
    int n,value,priority,choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter element and priority: ");
    struct node *pq;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&value,&priority);
        if (i == 0)
        {
            pq = newNode(value, priority);
        }
        else
        enqueue(&pq, value, priority);
    }
    while(1){
        printf("1.dequeue\n2.display\n3.front element\n4.exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            printf("%d is dequeued.", peek(&pq));
            dequeue(&pq);
            printf("\n");
            break;
        }
        case 2:
        {
            if (!isEmpty(&pq))
            {
            display(&pq);
            printf("\n");
            }
            else
            printf("Priority queue in empty\n");
            break;
        }
        case 3:
        {
            if (!isEmpty(&pq))
            {
            front(&pq);
            printf("\n");
            }
            else
                printf("Priority queue in empty\n");
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            printf("INVALID INPUT");
            break;
        }
        }
    }
    
    return 0;
}