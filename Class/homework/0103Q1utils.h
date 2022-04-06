#pragma once
#include <string.h>
#include <stdlib.h>

// The string length of name
#define LEN_NAME 50

// A structure represents the information of each student
struct student
{
    // The name string
    // Parameter: name (string)
    char name[LEN_NAME];

    // The score of English
    // Parameter: english (integer)
    int english;

    // The score of Math
    // Parameter: math (integer)
    int math;

    // Pointer to next student
    // Parameter: next (pointer)
    struct student* next;
};

/// <summary>
/// Convert the given 2 arrays into a linked list using 'student' structure.
/// </summary>
/// <param name="names">The name list.</param>
/// <param name="scores">The score list</param>
/// <returns>The first node of the created linked list.</returns>
struct student* convert(char names[][50], int scores[][2])
{
    struct student* first = (struct student*)malloc(sizeof(struct student));
    struct student** curr = &first;
    for (int i = 0; strlen(names[i]) != 0; i++)
    {
        struct student* temp = (struct student*)calloc(1, sizeof(struct student));
        strcpy(temp->name, names[i]);
        temp->english = scores[i][0];
        temp->math = scores[i][1];
        temp->next = NULL;
        *curr = temp;
        curr = &((*curr)->next);
    }
    return first;
}