#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int size;
    scanf_s("%d", &size);
    int arr[101];
    for (int i = 0; i < size; i++)
        scanf_s("%d", &arr[i]);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] ^= arr[j + 1];
                arr[j + 1] ^= arr[j];
                arr[j] ^= arr[j + 1];
            }
        }
    }

    for (int i = 0; i < size-1; i++)
        printf("%d ", arr[i]);
    printf("%d\n", arr[size - 1]);
    return 0;
}