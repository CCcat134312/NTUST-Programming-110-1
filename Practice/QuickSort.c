#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int size = 10, range = 100;
void printArray(int *arr, char *output) // print array and output a string
{
    if (strlen(output) > 0) // avoid output is nothing
        printf("%s\n", output);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void swap(int *p1, int *p2) // swap two number, call by reference
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void quickSort(int *arr, int start, int end) // quick sort
{
    if (start >= end)
        return;

    int left = start, right = end, ref = arr[start];
    while (left != right) // find number less than reference from right side and
    {                     // find number greater than reference from left side then swap them
        while (arr[right] > ref && left < right)
            right--;
        while (arr[left] <= ref && left < right)
            left++;
        if (left < right)
            swap(&arr[left], &arr[right]);
    }

    arr[start] = arr[left]; // change reference to middle one
    arr[left] = ref;

    quickSort(arr, start, left - 1); // separate leftside and rightside and solve sub-question
    quickSort(arr, left + 1, end);
}

int main(void)
{
    int arr[size];
    srand(time(NULL)); // set random seed
    for (int i = 0; i < size; i++)
        arr[i] = rand() % range + 1; // generated random number between 1~100

    printArray(arr, "original array:");
    quickSort(arr, 0, size - 1);
    printArray(arr, "quick sorted:");
    return 0;
}