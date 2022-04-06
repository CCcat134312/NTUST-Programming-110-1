// 字母金字塔
#include <stdio.h>

int main()
{
    int n;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i - 2; j >= 0; j--)
            putchar(' ');
        for (int j = 2 * i; j >= 0; j--)
            putchar('A' + i);
        putchar('\n');
    }
    return 0;
}