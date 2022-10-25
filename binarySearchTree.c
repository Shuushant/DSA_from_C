#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct BstNode
{
    int item;
    struct BstNode *left, *right;
} BstNode;

BstNode *Create(int);
BstNode *InsertNode(BstNode *, int);
BstNode *FindMax(BstNode *);
BstNode *FindMin(BstNode *);
BstNode *DeleteNode(BstNode *, int);
bool IsBst(BstNode *);
bool IsBstUtil(BstNode *, int, int);
void PreOrder(BstNode *);
void InOrder(BstNode *);
void PostOrder(BstNode *);

int main()
{
    BstNode *tree = NULL;
    int choice, data;
    char ch;
    printf("\n********************BINARY SEARCH TREE********************\n");
    do
    {
        printf("\n---------------------------------------------------------------------\n");
        printf("\nEnter your choice");
        printf("\n1.To insert data\n2.To find Min data\n3.To Delete Data\n4.To find Max data\n5.To print data in PostOrder");
        printf("\n6.To print data in Preorder\n7.To print data in Inorder\n8.To check BST\n9.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter data:");
            scanf("%d", &data);
            tree = InsertNode(tree, data);
            break;
        case 2:
            printf("\nMinimum data inserted = %d\n", FindMin(tree)->item);
            break;
        case 3:
            printf("enter data to delete:");
            scanf("%d", &data);
            DeleteNode(tree, data);
            break;
        case 4:
            printf("\nMaximum data inserted = %d\n", FindMax(tree)->item);
            break;
        case 5:
            PostOrder(tree);
            break;
        case 6:
            PreOrder(tree);
            break;
        case 7:
            InOrder(tree);
            tree;
        case 8:
            IsBst(tree);
            if (IsBst(tree) == true)
                printf("\nThis tree is BST\n");
            else
                printf("\nThis tree is not BST\n");
        default:
            break;
        }

    } while (choice != 9);
}

// allocating memory for Node//
BstNode *Create(int key)
{
    BstNode *newNode = malloc(sizeof(BstNode));
    newNode->item = key;
    newNode->right = newNode->left = NULL;
    return newNode;
}

// inserting data
BstNode *InsertNode(BstNode *root, int key)
{
    if (root == NULL)
    {
        root = Create(key);
    }
    else if (key <= root->item)
    {
        root->left = InsertNode(root->left, key);
    }
    else
    {
        root->right = InsertNode(root->right, key);
    }
    return root;
}

// Traversal order//
void PreOrder(BstNode *root)
{
    if (root == NULL)
        return;
    printf("%d->", root->item);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(BstNode *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%d->", root->item);
    InOrder(root->right);
}
void PostOrder(BstNode *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d->", root->item);
}
// getting address of maxmimum number in tree
BstNode *FindMax(BstNode *root)
{
    if (root == NULL)
        return root;
    else if (root->right == NULL)
        return root;
    else
    {
        return FindMax(root->right);
    }
}
// gettting address of minimum numebr in tree
BstNode *FindMin(BstNode *root)
{
    if (root == NULL)
        return root;
    else if (root->left == NULL)
        return root;
    else
    {
        return FindMin(root->left);
    }
}
// to check whether tree is BST or not
bool IsBstUtil(BstNode *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->item > max && root->item < min && IsBstUtil(root->left, min, root->item) && IsBstUtil(root->right, root->item, max))
    {
        return true;
    }
    else
        false;
}
// return if it true//
bool IsBst(BstNode *root)
{
    return IsBstUtil(root, INT_MIN, INT_MAX); // INT_MIN and INT_MAX provide min and max that memory address can hold a/q to computer//
}
// deleting node
BstNode *DeleteNode(BstNode *root, int key)
{
    if (root == NULL)
        return root;
    // searching data//
    else if (key < root->item)
        root->left = DeleteNode(root->left, key);
    else if (key > root->item)
        root->right = DeleteNode(root->right, key);
    // found data about to delete according to case//
    else
    {
        // case 1:No child
        if (root == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        // case 2:One child is present either left child or right child//
        // present of right child absent of left child//
        else if (root->left == NULL)
        {
            BstNode *tmp = root;
            root = root->right;
            free(tmp);
            tmp = NULL;
            return root;
        }
        // case 2:Present of left child and absent of right child//
        else if (root->right == NULL)
        {
            BstNode *tmp = root;
            root = root->left;
            free(tmp);
            tmp = NULL;
            return root;
        }
        // case 3:Presence of both child in node
        else
        {
            BstNode *tmp = FindMin(root->right);
            root->item = tmp->item; // getting minimum number from right child of node
            root->right = DeleteNode(tmp->right, tmp->item);
            free(tmp);
            tmp = NULL;
            return root;
        }
        /*
       Note:For case 3:
       also we can choose left child maximum data for deleting node
        BstNode *tmp = FindMax(root->left);
            root->item = tmp->item; // getting maxmum number from left child of node
            root->left = DeleteNode(tmp->left, tmp->item);
            free(tmp);
            tmp = NULL;
            return root;
       */
    }
}