#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *link;
} Node;
// adding node at first postion//
void AddAtBegin(Node **headRef, int d)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = d;
    newNode->link = (*headRef);
    (*headRef) = newNode;
}
void AddAtEnd(Node **headRef, int d)
{
    Node *ptr = (*headRef);
    Node *last = malloc(sizeof(Node));
    last->data = d;
    last->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = last;
}
void AddatIndex(Node **headRef, int pos, int d)
{
    Node *prev = (*headRef);
    Node *current = (*headRef);
    Node *newNode = malloc(sizeof(Node));
    newNode->data = d;
    if (pos == 1)
    {
        AddAtBegin(headRef, d);
        return;
    }
    else
    {
        while (pos != 1)
        {
            prev = current;
            current = current->link;
            pos--;
        }
        prev->link = newNode;
        newNode->link = current;
        return;
    }
}
void delAtIndex(Node **headRef, int index)
{
    Node *prev = (*headRef);
    Node *current = (*headRef);
    if (*headRef == NULL)
    {
        printf("Head is empty in linkedlist.");
    }
    else if (index == 1)
    {
        *headRef = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while (index != 1)
        {
            prev = current;
            current = current->link;
            index--;
        }
        prev->link = current->link;
        free(current);
        current = NULL;
    }
}
void delNodeWithData(Node **headRef, int d)
{
    Node *ptr = (*headRef);
    Node *tmp;
    if (ptr != NULL && ptr->data == d)
    {
        *headRef = ptr->link;
        free(ptr);
        ptr = NULL;
    }
    else if(ptr==NULL)
    {
        printf("Node don't contain the specified data.");

    }
    else
    {
        while (ptr != NULL && ptr->data != d)
        {
            tmp = ptr;
            ptr = ptr->link;
        }
        tmp->link = ptr->link;
        free(ptr);
        ptr = NULL;
    }
}
void display(Node **headRef)
{
    Node *ptr = (*headRef);
    while (ptr->link != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
int main()
{
    Node *head = NULL;
    printf("\nadding node at begining\n");
    for (size_t i = 5; i >= 1; i--)
    {
        AddAtBegin(&head, i);
        display(&head);
    }
    printf("\nadding node at end\n");
    for (size_t j = 6; j <= 10; j++)
    {
        AddAtEnd(&head, j);
        display(&head);
    }
    AddatIndex(&head, 1, 33);
    display(&head);
    printf("\nstart deleting node from end\n");
    for (size_t k = 10; k >= 1; k--)
    {
        delAtIndex(&head, k);
        display(&head);
    }
    for (size_t j = 6; j <= 10; j++)
    {
        AddAtBegin(&head,j);
        display(&head);
    }
    printf("\nafter deleting data = 8\n");
    delNodeWithData(&head,8);
    display(&head);
}