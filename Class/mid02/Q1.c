// print wave
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>
int main(void)
{
    char arr[21];
    scanf("%s", arr);
    for (int i = 0; arr[i]; i++)
    {
        puts("1");
        for (int j = 2; j <= arr[i] - '0'; j++)
        {
            for (int k = 0; k < j; k++)
                putchar(j + '0');
            putchar('\n');
        }
        for (int j = arr[i] - '0' - 1; j >= 2; j--)
        {
            for (int k = 0; k < j; k++)
                putchar(j + '0');
            putchar('\n');
        }
    }
    if (arr[strlen(arr) - 1] != '1')
        putchar('1');
    return 0;
}
/*

		for (int j = arr[i] - '0'; j > 0; j--)
			putchar(arr[i] - '0');
		for (int j = arr[i] - '0' - 1; j >= 2; j--)
		{
			for (int k = 0; k < j; k++)
				putchar(j + '0');
		}
*/