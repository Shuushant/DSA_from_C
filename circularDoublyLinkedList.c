#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev, *next;
} node;

node *create(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addatBeg(node **headRef, int data)
{
    node *newNode = create(data);
    if ((*headRef) == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        (*headRef) = newNode;
    }
    node *last = (*headRef)->prev;
    newNode->next = (*headRef);
    newNode->prev = last;
    last->next = newNode;
    (*headRef) = newNode;
}

void *addatEnd(node **headRef, int data)
{
    node *newNode = create(data);
    if (*headRef == NULL)
    {
        newNode->prev = newNode;
        newNode->next = newNode;
        (*headRef) = newNode;
    }
    node *last = (*headRef)->prev;
    newNode->next = (*headRef);
    (*headRef)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
}

void addatIndex(node **headRef, int pos, int data)
{
    if (pos == 1)
    {
        addatBeg(headRef, data);
    }
    else
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
        newNode->prev = front;
        newNode->next = back;
        back->prev = newNode;
    }
}
void delatBeg(node **headRef)
{
    node *last = (*headRef)->prev;
    node *ptr = (*headRef);
    (*headRef) = (*headRef)->next;
    (*headRef)->prev = last;
    last->next = (*headRef);
    free(ptr);
    ptr = NULL;
}

void delatEnd(node **headRef)
{
    node *last = (*headRef)->prev;
    node *ptr = last->prev;
    (*headRef)->prev = ptr;
    ptr->next = (*headRef);
    free(last);
}

void delatIndex(node **headRef, int pos)
{
    if (pos == 1)
    {
        delatBeg(headRef);
    }
    else
    {
        node *front = (*headRef);
        node *back = (*headRef);
        while (pos != 1)
        {
            front = back;
            back = back->next;
            pos--;
        }
        front->next = back->next;
        (back->next)->prev = front;
        free(back);
        back = NULL;
    }
}

void display(node **headRef)
{
    if (*headRef == NULL)
    {
        printf("Linked list is empty.");
    }
    node *p = (*headRef);
    node *last =(*headRef)->prev;
    printf("\n");
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != (*headRef));    
}

int main()
{
    node *head = NULL;
    int choice, data, pos;
    printf("*********************Circular Singly Linked List********************");
    do
    {
        printf("\n---------------------------------------------------------------------------------------------------------\n");
        printf("\n1.Add Node at begining\n2.Add node at End\n3.Add node at specified position\n4.Delete node at begin");
        printf("\n5.Delete node at End\n6.Delete node at specified position\n7.Display all Linked list\n8.Exit\n");
        printf("\nenter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter data:");
            scanf("%d", &data);
            addatBeg(&head, data);
            break;
        case 2:
            printf("enter data:");
            scanf("%d", &data);
            addatEnd(&head, data);
            break;
        case 3:
            printf("enter data:");
            scanf("%d", &data);
            printf("enter index:");
            scanf("%d", &pos);
            addatIndex(&head, pos, data);
            break;
        case 4:
            delatBeg(&head);
            break;
        case 5:
            delatEnd(&head);
            break;
        case 6:
            printf("enter index:");
            scanf("%d", &pos);
            delatIndex(&head, pos);
            break;
        case 7:
            display(&head);
            break;
            ;
        default:
            break;
        }

    } while (choice != 8);
}