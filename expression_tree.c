#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
    struct node *next;
};
struct node *head = NULL;

struct node *newNode(char data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;

    return node;
}
void printInorder(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        if (node->left != NULL)
            printf("(");
        printInorder(node->left);
        printf("%c", node->data);

        printInorder(node->right);
        if (node->right != NULL)
            printf(")");
    }
}

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        printf("%c", node->data);
        printPreorder(node->left);
        printPreorder(node->right);
    }
}

void printPostorder(struct node *node)
{
    if (node == NULL)
        return;
    else
    {
        printPostorder(node->left);
        printPostorder(node->right);
        printf("%c", node->data);
    }
}

void push(struct node *x)
{
    if (head == NULL)
        head = x;
    else
    {
        x->next = head;
        head = x;
    }
}
struct node *pop()
{
    struct node *p = head;
    head = head->next;
    return p;
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    char s[n];
    printf("Enter equation: ");
    scanf("%c");
    gets(s);

    struct node *x, *y, *z;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            z = newNode(s[i]);
            x = pop();
            y = pop();
            z->left = y;
            z->right = x;
            push(z);
        }
        else
        {
            z = newNode(s[i]);
            push(z);
        }
    }
    printf("The Inorder Traversal of Expression Tree: ");
    printInorder(z);
    printf("\n");
    printf("The Preorder Traversal of Expression Tree: ");
    printPreorder(z);
    printf("\n");
    printf("The Postorder Traversal of Expression Tree: ");
    printPostorder(z);
    printf("\n");
    return 0;
}