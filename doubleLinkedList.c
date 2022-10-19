#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev, *next;
} Node;
void addAtbegin(Node **headRef, int d)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = d;
    newNode->prev = NULL;
    if ((*headRef) != NULL)
    {
        (*headRef)->prev = newNode;
    }
    newNode->next = (*headRef);
    (*headRef) = newNode;
}
void addAtEnd(Node **headRef, int d)
{
    Node *newNode = malloc(sizeof(Node));
    Node *last = (*headRef);
    newNode->data = d;
    newNode->next = NULL;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void addAtIndex(Node **headRef, int pos, int d)
{
    Node *front = (*headRef);
    Node *current = (*headRef);
    Node *newNode = malloc(sizeof(Node));
    newNode->data = d;
    if (pos == 1)
    {
        addAtbegin(headRef, d);
        return;
    }
    while (pos != 1)
    {
        front = current;
        current = current->next;
        pos--;
    }
    front->next = newNode;
    newNode->prev = front;
    newNode->next = current;
    current->prev = newNode;
}

void display(Node **headRef)
{
    Node *ptr = (*headRef);
    Node *last;
    printf("\nIn traversal order\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        last = ptr;
        ptr = ptr->next;
    }
    printf("\nIn reversal order\n");
    while (last != NULL)
    {
        printf("%d\t", last->data);
        last = last->prev;
    }
    printf("\n");
}
void delAtBeg(Node **headRef)
{
    Node *tmp = (*headRef);
    *headRef = (*headRef)->next;
    free(tmp);
    tmp = NULL;
    (*headRef)->prev = NULL;
}
void delAtEnd(Node **headRef)
{
    Node *ptr = (*headRef);
    Node *tmp = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    tmp = ptr->prev;
    tmp->next = NULL;
    free(ptr);
    ptr = NULL;
}
void delAtIndex(Node **headRef, int index)
{
    Node *front = (*headRef);
    Node *back = NULL;
    Node *last = NULL;
    if (index == 1)
    {
        delAtBeg(headRef);
        return;
    }
    while (index != 1)
    {
        front = front->next;
        index--;
    }
    back = front->prev;
    last = front->next;
    back->next = last;
    last->prev = back;
    free(front);
    front = NULL;
}
void delNodeWithData(Node **headRef, int d)
{
    Node *front = (*headRef);
    Node *back, *last;
    if (front != NULL && front->data == d)
    {
        *headRef = front->next;
        free(front);
        front = NULL;
        (*headRef)->prev = NULL;
    }
    else if (front == NULL)
    {
        printf("Node don't contain the specified data.");
    }
    else
    {
        while (front != NULL && front->data != d)
        {
            front = front->next;
        }
        back = front->prev;
        last = front->next;
        back->next = last;
        last->prev = back;
        free(front);
        front = NULL;
    }
}
int main()
{
    Node *head = NULL;
    for (size_t i = 5; i >= 1; i--)
    {
        addAtbegin(&head, i);
    }
    for (size_t j = 6; j <= 10; j++)
    {
        addAtEnd(&head, j);
    }
    display(&head);
    printf("\ndeletin at begining\n");
    delAtBeg(&head);
    display(&head);
    printf("\ndeleting at ending\n");
    delAtEnd(&head);
    display(&head);
    printf("\ndeleting at specifed position i.e 3rd position\n");
    delAtIndex(&head, 3);
    display(&head);
    printf("\nafter deleting specified data = 7 along with its node\n");
    delNodeWithData(&head, 7);
    display(&head);
}
