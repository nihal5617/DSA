#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

typedef struct
{
    Node *start;
} LL;

void append(LL *l, int ele)
{
    Node *p, *q;
    p = (Node *)malloc(sizeof(Node)); //temporary node creation
    p->data = ele;
    p->link = NULL;
    if (l->start == NULL)
    {
        l->start = p; //if the node to be inserted is the first node
    }
    else
    {
        q = l->start;
        while (q->link != NULL) //loop runs until we reach the last node
        {
            q = q->link; //pointer starts pointing to next node
        }
        q->link = p; //element appended at the end of the list
    }
}

void display(LL *l)
{
    Node *p;
    p = l->start;
    if (p == NULL)
    {
        printf("\nThe list is empty\n");
    }
    else
    {
        while (p != NULL) //traverses the entire list
        {
            printf("%d\t", p->data);
            p = p->link; //last node will have a NULL in its link part
        }
    }
}

void deleteNode(LL *l, int ele)
{
    Node *p, *q;
    p = l->start;
    q = NULL;
    while (p != NULL)
    {
        if (p->data == ele) //if data found we break out of the loop
            break;
        q = p;       //q points to the current location of p
        p = p->link; //p points to the next node
    }

    if (p == NULL) //if/ data not found
    {
        printf("\n%d element not found inside the node\n", ele);
    }
    else
    {
        if (p->data == l->start->data) //if node to be deleted is the first node
        {
            l->start = p->link; //start pointer points to the next node
        }
        else //if data to be deleted is middle node or last node
        {
            q->link = p->link; //previous pointer points to the next part of p pointer
        }
        free(p);
    }
}

int main()
{
    LL l1, l2;
    l1.start = l2.start = NULL;
    int choice, ele;
    while (1)
    {
        printf("\nEnter your choice :\n 1.Insert at end\n 2.Delete node\n 3.Display\n 4.Exit\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to append : ");
            scanf("%d", &ele);
            append(&l1, ele);
            printf("\nElement appended at the end of the node\n");
            break;

        case 2:
            printf("\nEnter the element to be deleted : ");
            scanf("%d", &ele);
            deleteNode(&l1, ele);
            printf("\nElement deleted from the node \n");
            break;

        case 3:
            display(&l1);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid input");
        }
    }

    return 0;
}