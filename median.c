#include <stdio.h>
#include <stdlib.h>

struct node
{
    float data;
    struct node *left, *right;
};

struct node *create(float data)
{
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

struct node *insert(struct node *root, float data)
{
    if (root == NULL)
        root = create(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

float Median(struct node *root, int n) //Morris Inorder Traversal
{
    if (root == NULL)
        return 0;
    int count = 0;
    struct node *curr = root, *pre, *prev; //prev keeps track of previous node and pre keeps track of predecessor
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // count current node
            count++;

            // Check if current node is the median
            if (n % 2 != 0 && count == (n + 1) / 2) //Odd
                return curr->data;
            else if (n % 2 == 0 && count == (n / 2) + 1) //Even
                return (prev->data + curr->data) / 2;
            prev = curr;
            curr = curr->right;
        }
        else
        {
            // Find inorder predecessor of curr
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
            // Make current right child
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                prev = pre;
                // count current node
                count++;
                // Check if current node is the median
                if (n % 2 != 0 && count == (n + 1) / 2) //Odd
                    return curr->data;
                else if (n % 2 == 0 && count == (n / 2) + 1) //Even
                    return (prev->data + curr->data) / 2;
                prev = curr;
                curr = curr->right;
            }
        }
    }
}

int main()
{
    int n;
    struct node *tree = NULL;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        tree = insert(tree, arr[i]);
    }
    printf("The Median Is: %.1f", Median(tree, n));
}
