#pragma once
#include "mystring.h"
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

    // The score of History
    // Parameter: history (integer)
	int history;

    // The score of Physics
    // Parameter: physics (integer)
	int physics;

    // Pointer to next student
    // Parameter: next (struct pointer)
	struct student* next;
};

/// <summary>
/// Convert the given CSV format string into a linked list using 'student' structure.
/// </summary>
/// <param name="data">The data string.</param>
/// <returns>The first node of the created linked list.</returns>
struct student* convert(char* data)
{
	int size;
	string* arr = StringSplit(Initialize(data), '\n', &size);
	struct student* head = malloc(sizeof(struct student));
	struct student** curr = &head;
	for (int i = 0; i < size; i++)
	{
		int n;
		string* convert_data = StringSplit(arr[i], ',', &n);
		struct student* temp = calloc(1, sizeof(struct student));
		for (int cnt = 0; convert_data[0].content[cnt]; cnt++)
			temp->name[cnt] = convert_data[0].content[cnt];
		temp->english = StoI(convert_data[1]);
		temp->math = StoI(convert_data[2]);
		temp->history = StoI(convert_data[3]);
		temp->physics = StoI(convert_data[4]);
		temp->next = NULL;
		*curr = temp;
		curr = &((*curr)->next);
	}
	return head;
}

/// <summary>
/// Calculate the total score of each student, and return the average of all total scores.
/// </summary>
/// <param name="node">The starter node of linked list.</param>
/// <returns>The average value.</returns>
float average(struct student* node)
{
	int cnt = 0;
	float avg=0;
	for (struct student* i = node; i; i = i->next)
	{
		avg += (i->english);
		avg += (i->history);
		avg += (i->math);
		avg += (i->physics);
		cnt++;
	}
	return avg/cnt;
}

int StoI(string a)
{
	int cnt = 0;
	for (int i = 0; a.content[i]; i++)
	{
		cnt += a.content[i] - '0';
		cnt *= 10;
	}
	return cnt / 10;
}