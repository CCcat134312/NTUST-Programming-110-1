// IMPORTANT: DO NOT MODIFY THIS FILE.

#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

// Implements structures and functions in this header file
#include "func.h"

// Program entry point
int main()
{
    // Size of points
    int size = 5;

    // List of points    
    float data[][2] =
    {
        {1.2, 3.7}, {5.98, 7.75},
        {10.13, 7.75}, {-7.51, -3.7},
        {1.2, -6.23}
    };

    // Convert upon array list into a linked list
    struct point* node = convert(size, data);

    // NULL guard
    if (node == NULL)
    {
        printf("Linked List is NULL\n");
    }

    // Sort the points
    struct point* sorted = sort(node);

    // NULL guard
    if (sorted == NULL)
    {
        printf("Linked List is NULL\n");
    }

    //// Print results

    // Iterate through each point
    while (sorted)
    {
        // Print point x, y values
        printf("%.2f %.2f\n", sorted->x, sorted->y);

        // Jump to next point
        sorted = sorted->next;
    }

    return 0;
}
