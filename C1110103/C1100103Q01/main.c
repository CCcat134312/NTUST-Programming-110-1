// linked list
// IMPORTANT: DO NOT MODIFY THIS FILE.

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

// Implements structures and functions in this header file
#include "func.h"

// Program entry point
int main()
{
    // List of student names, list end with an empty string
    char names[][LEN_NAME] = { "Caspar Murray", "Rory Gordon", "Winnie Randolph", "" };

    // The English and Math score of each student
    int scores[][2] = { {50, 25}, {50, 50}, {50, 100} };

    // Convert upon array lists into a linked list
    struct student* first = convert(names, scores);

    // Iterate through each student
    while (first)
    {
        // Print student score information in required format
        printf("%s, %d, %d\n", first->name, first->english, first->math);
    
        // Jump to next student
        first = first->next;
    }

    return 0;
}
