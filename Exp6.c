#include <stdio.h>
#include <stdlib.h>

int k;
struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(int data)
{
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        root = create(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

struct node *kthSmallest(struct node *root)
{
    // base case
    if (root == NULL)
        return NULL;

    // search in left subtree
    struct node *left = kthSmallest(root->left);

    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;

    // if current element is k'th smallest, return it
    k--;
    if (k == 0)
        return root;

    // else search in right subtree
    return kthSmallest(root->right);
}

struct node *prev;
struct node *lca(struct node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    // If both n1 and n2 are smaller
    // than root, then LCA lies in left
    if (root->data > n1 && root->data > n2)
    {
        prev = root;
        return lca(root->left, n1, n2);
    }
    // If both n1 and n2 are greater than
    // root, then LCA lies in right
    if (root->data < n1 && root->data < n2)
    {
        prev = root;
        return lca(root->right, n1, n2);
    }
    // If both above condition are false than
    // the current node is the answer
    // if the current node is equal to either
    // value than previous node is answer
    if (root->data != n1 && root->data != n2)
        return root;
    // If previous node is null it means
    // one of the values is the head
    if (prev == NULL)
        return root;
    return prev;
}

int height(struct node *root)
{
    if (root == NULL)
        return -1;
    else if (root->left == NULL && root->right == NULL)
        return 0;
    else
    {
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }
}

int isBalanced(struct node *root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */

    /* If tree is empty then return true */
    if (root == NULL)
        return 1;

    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    /* If we reach here then tree is not height-balanced */
    return 0;
}

void Print(struct node *root, int k1, int k2)
{
    // base case
    if (NULL == root)
        return;

    // Since the desired o/p is sorted, recurse for left subtree first
    // If root->data is greater than k1, then only we can get o/p keys
    // in left subtree
    if (k1 < root->data)
        Print(root->left, k1, k2);

    /* if root's data lies in range, then prints root's data */
    if (k1 <= root->data && k2 >= root->data)
        printf("%d ", root->data);

    /* recursively call the right subtree */
    Print(root->right, k1, k2);
}

int main()
{
    int n, c, choice, flag = 1;
    struct node *root = NULL, *ans;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c);
        root = insert(root, c);
    }
    while (flag)
    {

        printf("Enter 1 for LCA\n      2 for Kth smallest\n      3 to check if tree is balanced\n      4 to print elements in a given range\n      5 to quit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int n1, n2;
            prev = NULL;
            printf("Enter the values of two nodes: ");
            scanf("%d %d", &n1, &n2);
            printf("The lca of %d and %d is %d\n\n", n1, n2, lca(root, n1, n2)->data);
            break;
        }

        case 2:
        {
            printf("Enter the value of k: ");
            scanf("%d", &k);
            ans = kthSmallest(root);
            if (ans == NULL)
                printf("There are less than %d nodes in the BST\n\n", k);
            else
                printf("The K-th smallest element is %d\n\n", ans->data);
            break;
        }

        case 3:
        {
            if (isBalanced(root))
                printf("The given tree is balanced\n\n");
            else
                printf("The given tree is not balanced\n\n");
            break;
        }

        case 4:
        {
            int k1, k2;
            printf("Enter the value of k1 and k2: ");
            scanf("%d %d", &k1, &k2);
            Print(root, k1, k2);
            printf("\n\n");
            break;
        }

        case 5:
        {
            flag = 0;
            break;
        }

        default:
            printf("\nInvalid input\n\n");
            break;
        }
    }
}