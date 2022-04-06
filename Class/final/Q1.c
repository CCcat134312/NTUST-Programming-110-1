// print wave 2
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>
int main(void)
{
    char arr[21];
    scanf("%s", arr);
    int maxSize = 0;
    for (int i = 0; arr[i]; i++)
        maxSize = (arr[i] - '0') > maxSize ? (arr[i] - '0') : maxSize;
    for (int i = 0; arr[i]; i++)
    {
        for (int k = 0; k < (maxSize - 1) / 2; k++)
            putchar(' ');
        puts("1");

        for (int j = 2; j <= arr[i] - '0'; j++)
        {
            if (j & 1)
            {
                for (int k = 0; k < (maxSize - j) / 2; k++)
                    putchar(' ');
                for (int k = 0; k < j; k++)
                    putchar(j + '0');
                putchar('\n');
            }
        }
        for (int j = arr[i] - '0' - 1; j >= 2; j--)
        {
            if (j & 1)
            {
                for (int k = 0; k < (maxSize - j) / 2; k++)
                    putchar(' ');
                for (int k = 0; k < j; k++)
                    putchar(j + '0');
                putchar('\n');
            }
        }
    }
    if (arr[strlen(arr) - 1] != '1')
    {
        for (int k = 0; k < (maxSize - 1) / 2; k++)
            putchar(' ');
        putchar('1');
    }
    return 0;
}