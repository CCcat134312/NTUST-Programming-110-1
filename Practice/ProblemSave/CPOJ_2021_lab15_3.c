#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} node;
void printLinkedList(node *head)
{
    for (node *i = head; i; i = i->next)
    {
        printf("%4d", i->data);
        // printf("%d %p %p %p\n", i->data, i, i->prev, i->next);
    }
    putchar('\n');
}
void push_front(node **head, int value)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->prev = NULL;
    temp->next = *head;
    if (*head != NULL)
        (*head)->prev = temp;
    *head = temp;
}
void push_back(node **head, int value)
{
    if (*head == NULL)
    {
        push_front(head, value);
        return;
    }
    while ((*head)->next != NULL)
        head = &((*head)->next);
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = *head;
    (*head)->next = temp;
}
void delete (node **head, int value)
{
    while ((*head)->data != value)
        head = &((*head)->next);

    node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = temp->prev;
    free(temp);
}
void insert(node **head, int target, int value)
{
    while ((*head)->data != target)
        head = &((*head)->next);
    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    temp->next = *head;
    temp->prev = (*head)->prev;
    if ((*head)->prev != NULL)
        (*head)->prev->next = temp;
    (*head)->prev = temp;
    *head = temp;
}
int main(void)
{
    int operator;
    int temp1, temp2;
    node *head = NULL;
    while (1)
    {
        scanf("%d", &operator);
        if (operator== 1)
        {
            scanf("%d", &temp1);
            push_front(&head, temp1);
        }
        else if (operator== 2)
        {
            scanf("%d", &temp1);
            push_back(&head, temp1);
        }
        else if (operator== 3)
        {
            scanf("%d %d", &temp1, &temp2);
            insert(&head, temp1, temp2);
        }
        else if (operator== 4)
        {
            scanf("%d", &temp1);
            delete (&head, temp1);
        }
        else
            break;
        printLinkedList(head);
    }
    return 0;
}
/*
Doubly Linked List
1 81
2 38
4 38
1 12
3 81 96
-1
1: Insert the node at the beginning
2: Insert the node at the end
3: Insert the node in front of a node with a designated key
4: Delete the node
*/