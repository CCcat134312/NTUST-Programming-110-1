#include <stdio.h>
#include <stdlib.h>
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}
void copy(int *arr, int *target, int size)
{
    for (int i = 0; i < size; i++)
        target[i] = arr[i];
}
void rotate(int *arr, int begin, int end)
{
    int temp = arr[end];
    for (int i = end; i > begin; i--)
        arr[i] = arr[i - 1];
    arr[begin] = temp;
}
void perm(int *arr, int step, int size)
{
    if (step == size)
    {
        print(arr, size + 1);
        return;
    }
    for (int i = step; i <= size; i++)
    {
        int temp[size + 1];
        copy(arr, temp, size + 1);
        rotate(temp, step, i);
        perm(temp, step + 1, size);
    }
}
int main(void)
{
    int size;
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    perm(arr, 0, size - 1);

    return 0;
}