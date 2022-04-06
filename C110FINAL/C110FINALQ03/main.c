// IMPORTANT: DO NOT MODIFY THIS FILE.

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

// Implements structures and functions in this header file
#include "func.h"

// Program entry point
int main()
{
    // List of student names and scores
    char* data =
        "Caspar Murray,50,25,100,80\n"
        "Rory Gordon,50,50,100,60\n"
        "Winnie Randolph,50,100,50,20\n";

    // Convert upon array lists into a linked list
    struct student* node = convert(data);

    // NULL guard
    if (node == NULL)
    {
        //printf("Linked List is NULL\n");
    }

    // Calculate average score
    float avg = average(node);

    //// Print results
    
    // Iterate through each student
    while (node)
    {
        // Print student score information in required format
        printf("%s: %d, %d, %d, %d\n", node->name, node->english, node->math, node->history, node->physics);

        // Jump to next student
        node = node->next;
    }

    // Show average score
    printf("Average score: %.2f", avg);

    return 0;
}
