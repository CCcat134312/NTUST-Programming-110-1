#include <stdio.h>

int main()
{
    int a, b;
    char c;
    scanf_s("%d %c %d", &a, &c, 1, &b);
    printf("%d %c %d", a, c, b);
    return 0;
}