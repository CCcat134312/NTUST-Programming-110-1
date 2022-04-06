// 二進制轉十進制求 GCD
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
int bin_to_dec(char *input)
{
    int sum = 0, len = strlen(input);   
    for (int i = len - 1, j = 0; i >= 0; i--, j++)
    {
        sum += ((input[i] - '0') << j);
    }
    return sum;
}
int gcd(int x, int y)
{
    if (!y)
        return x;
    return gcd(y, x % y);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int big, small;
        char temp[31];
        scanf("%s", &temp);
        big = bin_to_dec(temp);
        scanf("%s", &temp);
        small = bin_to_dec(temp);
        if (gcd(big, small) != 1)
        {
            printf("Pair #%d: All you need is love!\n", i);
        }
        else
        {
            printf("Pair #%d: Love is not all you need!\n", i);
        }
    }
    return 0;
}