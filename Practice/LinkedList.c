#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void traversal(struct Node *head)
{
    if (head == NULL)
        puts("NULL");
    for (; head != NULL; head = head->next)
        printf("%3d", head->data);
    putchar('\n');
}
void push_back(struct Node **head, int value)
{
    while (*head != NULL)
        head = &((*head)->next);

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    *head = temp;
}
void push_front(struct Node **head, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}
void insert(struct Node **head, int index, int value)
{
    if (index == 0)
    {
        push_front(head, value);
        return;
    }
    for (int i = 0; i < index - 1; i++, head = &((*head)->next))
    {
        if (*head == NULL)
        {
            puts("index out of range\n");
            return;
        }
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = (*head)->next;
    (*head)->next = temp;
}
void delete_by_index(struct Node **head, int target)
{
    if (*head == NULL)
    {
        puts("linked list have nothing\n");
        return;
    }
    for (int cnt = 0; *head != NULL; head = &((*head)->next), cnt++)
    {
        if (cnt == target)
        {
            struct Node *temp = *head;
            *head = (*head)->next;
            free(temp);
            return;
        }
    }
    puts("index out of range\n");
}
void delete_by_value(struct Node **head, int target)
{
    if (*head == NULL)
    {
        puts("linked list have nothing\n");
        return;
    }
    for (; *head != NULL; head = &((*head)->next))
    {
        if ((*head)->data == target)
        {
            struct Node *temp = *head;
            *head = (*head)->next;
            free(temp);
            return;
        }
    }
    puts("target was not found\n");
}
void pop_back(struct Node **head)
{
    if (*head == NULL)
    {
        puts("linked list have nothing\n");
        return;
    }
    else if ((*head)->next == NULL)
    {
        head = NULL;
        return;
    }
    while ((*head)->next->next != NULL)
    {
        head = &((*head)->next);
    }
    struct Node *temp = (*head)->next;
    (*head)->next = NULL;
    free(temp);
}
void pop_front(struct Node **head)
{
    if (*head == NULL)
    {
        puts("linked list have nothing");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void free_all(struct Node **head)
{
    if (*head == NULL)
    {
        puts("linked list have nothing\n");
        return;
    }
    while (*head != NULL)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
void search(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("not found the value: %d\n", value);
        return;
    }
    for (int cnt = 0; head != NULL; head = head->next, cnt++)
    {
        if (head->data == value)
        {
            printf("search: %d, index: %d\n", value, cnt);
            return;
        }
    }
    printf("not found the value: %d\n", value);
}
void reverse(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
int main(void)
{
    struct Node *head = NULL;
    for (int i = 0; i < 10; i++)
        push_back(&head, i);
    traversal(head);
    reverse(&head);
    traversal(head);
    return 0;
}