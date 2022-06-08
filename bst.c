
#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
    int data;
    struct tnode *left,*right;
}tnode;

typedef struct
{
    tnode *root;
}Tree;


void insertElement(Tree *t,int ele)
{
    tnode *p;
    p = (tnode*)malloc(sizeof(tnode));
    p->data = ele;
    p->right = p->left = NULL;
    if(t->root == NULL)
    {
        t->root = p;
    }
    else
    {
        tnode *q = t->root;
        tnode *prev = NULL;
        while(q!=NULL)
        {
            if(p->data<q->data)
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
        if(p->data<prev->data)
            {
                prev->left = p;
            }
            else
            {
                prev->right = p;
            }
    }
}

int deleteNode(Tree *t)
{
    int ele;
    printf("\nEnter the element to be deleted : ");
    scanf("%d",&ele);
    tnode *p = t->root;
    tnode *prev = NULL;
    while(p != NULL)
    {

        if(p->data == ele)
        {
            break;
        }
        if(ele<p->data)
        {
            prev = p;
            p = p->left;
        }
        else
        {
            prev = p;
            p = p->right;
        }
    }
    if(p == NULL)
    {
        printf("\nData not found\n");
        return 0;
    }
    else if(p->left == NULL && p->right == NULL)//if it is a leaf node containing no child
    {
        if(p==t->root)
            t->root = NULL;//if node to be deleted is root and contains no child
        else
        {
           if(p->data < prev->data)//to check whether to delete the left child or the right child
           {
               prev->left = NULL;
           }
           else
           {
               prev->right = NULL;
           }
        }

        free(p);
        return ele;
    }
    else if(p->left == NULL || p->right == NULL)//if it is a node containing at most one child
    {
        if(p==t->root)//if it is a root element to be deleted
        {
            if(p->left != NULL)
                t->root = p->left;
            else
                t->root = p->right;
        }
        else
        {
           /*Here, two condn are to be checked :
           1. whether to attach the child node to the left or right of the previous node
           2. whether the node to be attached is the left or right child of the parent node */
           if(p->data < prev->data)//1st condn
           {
               if(p->left != NULL)//2nd condn
               {
                   prev->left = p->left;
               }
               else//2nd condn
               {
                   prev->left = p->right;
               }
           }
           else//1st condn
           {
               if(p->left != NULL)//2nd condn
               {
                   prev->right = p->left;
               }
               else//2nd condn
               {
                   prev->right = p->right;
               }
           }
        }

        free(p);
        return ele;
    }
    else//the node to be deleted has both left and right child
    {
        //Here , the node to be deleted should be replaced by the least element in its right part or the highest element in its left part
        tnode *q,*r;
        q = p->right;
        r = NULL;
        if(q->left==NULL && q->right==NULL)//the node to be deleted's right part contains no child
        {
            p->data = q->data;
            p->right = NULL;
            free(q);
            return ele;
        }
        else if(q->left == NULL && q->right != NULL)//the node to be deleted's right part contains right child but no left child
        {
            p->data = q->data;
            p->right = q->right;
            q->right = NULL;
            free(q);
            return ele;
        }
        else//if the node to be deleted's right part has a left child
        {
            while(q->left != NULL)
            {
                r = q;
                q = q->left;//this way we reach the least element of the left part
            }
            if(q->right == NULL)//the least node does not have a right node
            {
                p->data = q->data;
                r->left = NULL;
                free(q);
                return ele;
            }
            else//if the least node has a right child
            {
                r->left = q->right;//attach the right child to the left of previous node
                p->data = q->data;//replace the data of the node to be deleted
                q->right = NULL;
                free(q);
                return ele;
            }


        }
    }
}

void display(Tree *t)
{
    int choice;
    tnode *p = t->root;
    if(p == NULL)
    {
        printf("\nTree is empty\n");
        return;
    }
    printf("\nIn which order do you want to print the list : \n1.InOrder\n2.Pre-Order\n3.Post-Order\n");
    scanf("%d",&choice);
    switch(choice)
    {
        /*Displaying of elements in tree DS works on recursive function calling
        First the left child node gets recursively called until NULL pointer is not encountered
        after that right child gets called in the similar manner*/
    case 1 :
        printf("\nElements : ");
        inOrder(p);
        break;
    case 2 :
        printf("\nElements : ");
        preOrder(p);
        break;
    case 3 :
        printf("\nElements : ");
        postOrder(p);
        break;
    default :
        printf("\nInvalid input\n");
    }
}

void inOrder(tnode *t)//LVR , L - left node, V - Vertex , R - right node
{
    if(t->left)
        inOrder(t->left);
    printf("%d\t",t->data);
    if(t->right)
        inOrder(t->right);
}



void preOrder(tnode *t)//VLR , V- vertex is printed first, L - traverse the left node , R - traverse the right node
{
    printf("%d\t",t->data);
    if(t->left)
        preOrder(t->left);
    if(t->right)
        preOrder(t->right);
}

void postOrder(tnode *t)//LRV , L - Left node , R - Right node , V - Vertex
{
    if(t->left)
        postOrder(t->left);
    if(t->right)
        postOrder(t->right);
     printf("%d\t",t->data);
}

int findMinimum(tnode *p)
{
    if(p->left==NULL)
        return p->data;
    else
        findMinimum(p->left);
}

int findMaximum(tnode *p)
{
    if(p->right==NULL)
        return p->data;
    else
        findMaximum(p->right);
}

int searchNode(tnode *p,int ele)
{
    if(p == NULL)
        return 0;
    else if(p->data == ele)
        return 1;
    else if(ele<p->data)
        return searchNode(p->left,ele);
    else
        return searchNode(p->right,ele);
}

void countNodes(tnode *p)
{
    int choice;
    printf("\nEnter th choice of operation :\n1.Count all nodes\n2.Count leaf nodes\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1 :
        printf("\nNumber of nodes : %d\n",countAllNodes(p));
        break;

    case 2 :
        printf("\nNumber of leaf nodes : %d\n",countLeafNodes(p));
        break;
    }
}






int main()
{
    Tree t1;
    t1.root = NULL;
    int choice,ele;

    while(1)
    {
        printf("\nEnter your choice :\n1.Insert an element\n2.Delete\n3.Display\n"
               "4.Find Minimum element\n5.Find Maximum element\n6.Search node\n7.Count nodes\n"
               "8.Height of a tree\n9.Mirror tree\n10.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1 :
            printf("\nEnter the element to be inserted : ");
            scanf("%d",&ele);
            insertElement(&t1,ele);
            printf("\nElement inserted\n");
            break;

        case 2 :
            printf("\nDeleted item : %d\n",deleteNode(&t1));
            break;

        case 3 :
            display(&t1);
            printf("\n");
            break;

        case 4 :
            if(t1.root == NULL)
                printf("\nNo elements inside the tree\n");
            else
                printf("\nMinimum element : %d\n",findMinimum(t1.root));
            break;

        case 5 :
             if(t1.root == NULL)
                printf("\nNo elements inside the tree\n");
            else
                printf("\nMaximum element : %d\n",findMaximum(t1.root));
            break;

        case 6 :
            printf("\nEnter the element to be searched : ");
            scanf("%d",&ele);
            ele = searchNode(t1.root,ele);
            if(ele == 1)
                printf("\nData found\n");
            else
                printf("\nData not found\n");
            break;

        case 7 :
            countNodes(t1.root);
            break;

        case 8 :
            printf("\nHeight : %d\n",height(t1.root));
            break;

        case 9 :
            mirror(t1.root);
            break;

        case 10 :
            exit(0);

        default :
            printf("\nInvalid input\n");

        }
    }
}