#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int bit, zeroCnt = 0, oneCnt = 0;
    for (int i = 31; i >= 0; i--)
    {
        bit = (n >> i) & 1;
        oneCnt += bit ? 1 : 0;
        zeroCnt += bit ? 0 : 1;
        printf("%d", bit);
    }
    printf("\nZeros: %d\nOnes: %d\n", zeroCnt, oneCnt);
    int reverse = 0;
    for (int i = 0; i < 32; i++)
    {
        bit = (n >> i) & 1;
        reverse <<= 1;
        reverse += bit;
        printf("%d", bit);
    }
    printf("\n%d", reverse);
    return 0;
}