#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;
void printLinkedList(node *head)
{
    for (node *i = head; i; i = i->next)
        printf("%4d", i->data);
    putchar('\n');
}
void printBackward(node *head)
{
    if (head == NULL)
        return;
    printBackward(head->next);
    printf("%4d", head->data);
}
void Insert(node **head, int val)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = val;
    if (*head == NULL) // linked list is empty
    {
        temp->next = NULL;
        *head = temp;
        return;
    }
    if ((*head)->data > val) // insert value is min
    {
        temp->next = *head;
        *head = temp;
        return;
    }

    node *prev = (*head)->next;
    while (prev != NULL && prev->data <= val) // find the first number that greater than value
    {
        head = &((*head)->next);
        prev = prev->next;
    }
    if (prev == NULL) // not found
        temp->next = NULL;
    else
        temp->next = (*head)->next;
    (*head)->next = temp;
}
int main(void)
{
    node *head = NULL;
    for (int i = 0, temp; i < 10; i++)
    {
        scanf("%d", &temp);
        Insert(&head, temp);
    }
    printLinkedList(head);
    printBackward(head);
    return 0;
}
/*
Inserting into an Ordered Lists
77 54 74 23 8 98 83 100 7 51
*/