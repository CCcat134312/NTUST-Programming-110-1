#pragma once
#include <stdlib.h>
// A structure represents the value of each point
struct point
{
    // Axis values of x and y
	float x;
	float y;

    // Pointer to next point
    struct point* next;
};

/// <summary>
/// Convert the given point list into a linked list using 'point' structure.
/// </summary>
/// <param name="size">The size of list.</param>
/// <param name="data">The point list.</param>
/// <returns>The first node of the created linked list.</returns>
struct point* convert(int size, float data[][2])
{
	struct point* head = malloc(sizeof(struct point));
	struct point** curr = &head;
	for (int i = 0; i < size; i++)
	{
		//printf("%f %f",data[i][0],data[i][1]);
		struct point* temp = malloc(sizeof(struct point));
		temp->x = data[i][0];
		temp->y = data[i][1];
		temp->next = NULL;
		*curr = temp;
		curr = &((*curr)->next);
	}
	return head;
}

/// <summary>
/// Sort points in ascending order prioritizing on the x value.
/// </summary>
/// <param name="size">The first node of the linked list.</param>
/// <returns>The first node of the sorted linked list.</returns>
struct point* sort(struct point* list)
{
	for (struct point* i = list; i ; i=i->next)
	{
		for (struct point* j = list; j->next; j = j->next)
		{
			if (j->x > j->next->x || (j->x == j->next->x && j->y > j->next->y))
			{
				float tempx = j->x, tempy = j->y;
				j->x = j->next->x;
				j->y = j->next->y;
				
				j->next->x = tempx;
				j->next->y = tempy;
			}
		}
	}
	return list;
}
