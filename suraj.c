
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct tnode *left, *right;
} tnode;

typedef struct
{
    tnode *root;
} Tree;

void insertElement(Tree *t, int ele)
{
    tnode *p;
    p = (tnode *)malloc(sizeof(tnode));
    p->data = ele;
    p->right = p->left = NULL;
    if (t->root == NULL)
    {
        t->root = p;
    }
    else
    {
        tnode *q = t->root;
        tnode *prev = NULL;
        while (q != NULL)
        {
            if (p->data < q->data)
            {
                prev = q;
                q = q->left;
            }
            else
            {
                prev = q;
                q = q->right;
            }
        }
        if (p->data < prev->data)
        {
            prev->left = p;
        }
        else
        {
            prev->right = p;
        }
    }
}

void display(Tree *t)
{
    int choice;
    tnode *p = t->root;
    if (p == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    printf("\nIn which order do you want to print the list : \n1.InOrder\n2.Pre-Order\n3.Post-Order\n");
    scanf("%d", &choice);
    switch (choice)
    {
        /*Displaying of elements in tree DS works on recursive function calling
        First the left child node gets recursively called until NULL pointer is not encountered
        after that right child gets called in the similar manner*/
    case 1:
        printf("\nElements : ");
        inOrder(p);
        break;
    case 2:
        printf("\nElements : ");
        preOrder(p);
        break;
    case 3:
        printf("\nElements : ");
        postOrder(p);
        break;
    default:
        printf("\nInvalid input\n");
    }
}

void inOrder(tnode *t) //LVR , L - left node, V - Vertex , R - right node
{
    if (t->left)
        inOrder(t->left);
    printf("%d\t", t->data);
    if (t->right)
        inOrder(t->right);
}

void preOrder(tnode *t) //VLR , V- vertex is printed first, L - traverse the left node , R - traverse the right node
{
    printf("%d\t", t->data);
    if (t->left)
        preOrder(t->left);
    if (t->right)
        preOrder(t->right);
}

void postOrder(tnode *t) //LRV , L - Left node , R - Right node , V - Vertex
{
    if (t->left)
        postOrder(t->left);
    if (t->right)
        postOrder(t->right);
    printf("%d\t", t->data);
}

int searchNode(tnode *p, int ele)
{
    if (p == NULL)
        return 0;
    else if (p->data == ele)
        return 1;
    else if (ele < p->data)
        return searchNode(p->left, ele);
    else
        return searchNode(p->right, ele);
}

int a[100];
int left = 0, right = 0, result = 0, n = 1;

int compare(tnode x, int n)
{
    int a = n;
    int b = n + 1;
    while (a[n] && a[1])
    {
        }
}
