#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addatBeg(node **headRef, int data)
{
    node *newNode = create(data);
    node *last = *headRef;
    newNode->next = (*headRef);

    if ((*headRef) == NULL)
    {
        newNode->next = newNode;
        *headRef = newNode;
    }
    else
    {
        while (last->next != *headRef)
        {
            last = last->next;
        }
        last->next = newNode;
        *headRef = newNode;
    }
}

void addatEnd(node **headRef, int data)
{
    node *last = *headRef;
    node *newNode = create(data);

    while (last->next != (*headRef))
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->next = *headRef;
}

void addatIndex(node **headRef, int pos, int data)
{
    node *newNode = create(data);
    node *front = (*headRef);
    node *back = (*headRef);
    while (pos != 1)
    {
        front = back;
        back = back->next;
        pos--;
    }
    front->next = newNode;
    newNode->next = back;
}
void delatBeg(node **headRef)
{
    node *ptr = (*headRef);
    node *last = (*headRef);
    while (last->next != (*headRef))
    {
        last = last->next;
    }
    last->next = ptr->next;
    (*headRef) = ptr->next;
    free(ptr);
}

void delatEnd(node **headRef)
{
    node *ptr = (*headRef);
    node *last = (*headRef);
    while (last->next != (*headRef))
    {
        ptr = last;
        last = last->next;
    }
    ptr->next = *headRef;
    free(last);
}

void display(node **headRef)
{
    if ((*headRef) == NULL)
    {
        printf("Linked list is empty.");
        exit(0);
    }
    node *tmp = *headRef;
    do
    {
        printf("%d\t", tmp->data);
        tmp = tmp->next;
    } while (tmp != (*headRef));
    printf("\n");
}

void delatIndex(node **headRef, int pos)
{
    if (pos == 1)
    {
        delatBeg(headRef);
    }
    node *front = (*headRef);
    node *back = (*headRef);
    while (pos != 1)
    {
        front = back;
        back = back->next;
        pos--;
    }
    front->next = back->next;
    free(back);
    back = NULL;
}

int main()
{
    node *head = NULL;
    int i;
    for (i = 5; i >= 1; i--)
    {
        addatBeg(&head, i);
        display(&head);
    }
    addatIndex(&head, 3, 22);
    display(&head);
    printf("\n");
    for (i = 3; i >= 1; i--)
    {
        delatBeg(&head);
        display(&head);
    }
    /*for (i = 2; i >= 1; i--)
    {
        delatEnd(&head);
        display(&head);
    }*/
    delatIndex(&head,2);
    display(&head);
}