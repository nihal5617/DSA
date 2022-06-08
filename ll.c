#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node *link;
};

struct node *create()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter coeff for term:");
    scanf("%d", &newnode->coeff);
    printf("\nEnter pow of term:");
    scanf("%d", &newnode->pow);
    newnode->link = NULL;
    return (newnode);
}

struct node *create_with_value(int coeff, int pow)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->link = NULL;
    return (newnode);
}

struct node *insert_end(struct node *lhead)
{
    struct node *temp, *ptr;
    temp = create();
    if (lhead == NULL)
        lhead = temp;
    else
    {
        ptr = lhead;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = temp;
    }
    return (lhead);
}

struct node *insert_end_with_value(struct node *lhead, int coeff, int pow)
{
    struct node *temp, *ptr;
    temp = create_with_value(coeff, pow);
    if (lhead == NULL)
        lhead = temp;
    else
    {
        ptr = lhead;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = temp;
    }
    return (lhead);
}

void traverse(struct node *lhead)
{
    while (lhead != NULL)
    {
        if (lhead->coeff > 0 || lhead->coeff < 0)
        {
            printf("%d", lhead->coeff);
            if (lhead->pow > 1)
            {
                printf("x^%d", lhead->pow);
            }
            else if (lhead->pow == 1)
            {
                printf("x");
            }
            lhead = lhead->link;
            if (lhead != NULL)
            {
                if (lhead->coeff > 0)
                    printf("+");
            }
        }
        else
        {
            lhead = lhead->link;
        }
    }
    printf("\n\n");
}

void add(struct node *poly1, struct node *poly2, struct node *poly)
{
    while (poly1 && poly2)
    {
        if (poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->link;
        }

        else if (poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->link;
        }

        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }

        if (poly1 || poly2)
        {
            poly->link = (struct node *)malloc(sizeof(struct node));
            poly = poly->link;
            poly->link = NULL;
        }
    }
    while (poly1 || poly2)
    {
        if (poly1)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->link;
        }
        if (poly2)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->link;
        }
        if (poly1 || poly2)
        {
            poly->link = (struct node *)malloc(sizeof(struct node));
            poly = poly->link;
            poly->link = NULL;
        }
    }
}

void sub(struct node *poly1, struct node *poly2, struct node *poly)
{
    while (poly1 && poly2)
    {
        if (poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->link;
        }

        else if (poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = -poly2->coeff;
            poly2 = poly2->link;
        }

        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff - poly2->coeff;
            poly1 = poly1->link;
            poly2 = poly2->link;
        }

        if (poly1 || poly2)
        {
            poly->link = (struct node *)malloc(sizeof(struct node));
            poly = poly->link;
            poly->link = NULL;
        }
    }
    while (poly1 || poly2)
    {
        if (poly1)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->link;
        }
        if (poly2)
        {
            poly->pow = poly2->pow;
            poly->coeff = -poly2->coeff;
            poly2 = poly2->link;
        }
        if (poly1 || poly2)
        {
            poly->link = (struct node *)malloc(sizeof(struct node));
            poly = poly->link;
            poly->link = NULL;
        }
    }
}

struct node *mul(struct node *poly1, struct node *poly2, struct node *poly)
{
    int coeff, pow, flag;
    struct node *ptr, *temp;
    while (poly1)
    {
        temp = poly2;
        while (temp)
        {
            coeff = poly1->coeff * temp->coeff;
            pow = poly1->pow + temp->pow;
            flag = 1;
            if (poly == NULL)
            {
                poly = insert_end_with_value(poly, coeff, pow);
            }
            else
            {
                ptr = poly;
                while (ptr)
                {
                    if (ptr->pow == pow)
                    {
                        ptr->coeff += coeff;
                        flag = 0;
                        break;
                    }
                    ptr = ptr->link;
                }
                if (flag)
                {
                    poly = insert_end_with_value(poly, coeff, pow);
                }
            }
            temp = temp->link;
        }
        poly1 = poly1->link;
    }
    return poly;
}

int main()
{
    int i, position, data, n, choice;
    struct node *head1 = NULL, *head2 = NULL, *answer = NULL;

    printf("Enter the number of terms of first polynomial:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        head1 = insert_end(head1);
    printf("\nEnter the number of terms of second polynomial:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        head2 = insert_end(head2);

    traverse(head1);
    traverse(head2);
    int flag = 1;
    while (flag)
    {
        answer = (struct node *)malloc(sizeof(struct node));
        answer->link = NULL;

        printf("Enter 1 for addition, 2 for subtraction, 3 for multiplication and 4 to quit:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add(head1, head2, answer);
            traverse(answer);
            break;
        case 2:
            sub(head1, head2, answer);
            traverse(answer);
            break;
        case 3:
            answer = NULL;
            answer = mul(head1, head2, answer);
            traverse(answer);
            break;
        case 4:
            flag = 0;
        }
    }
}