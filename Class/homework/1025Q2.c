// 找重複過的數字
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int size, len = 0;
    scanf_s("%d", &size);
    int arr[101], output[101];
    for (int i = 0; i < size; i++)
    {
        scanf_s("%d", &arr[i]);
    }
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
    int temp = arr[0];
    for (int i = 0; i < size - 1; i++)
    {
        if (temp == arr[i] && i != 0)
            continue;
        if (arr[i] == arr[i + 1])
        {
            output[len] = arr[i];
            temp = arr[i];
            len++;
        }
    }
    if (len == 0)
        puts("No repeated number!\n");
    else
    {
        for (int i = 0; i < len - 1; i++)
            printf("%d ", output[i]);
        printf("%d\n", output[len - 1]);
    }
    return 0;
}