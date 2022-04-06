// 費式數列
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int n;
    scanf_s("%d", &n);
    if (n < 0)
    {
        puts("\"Invalid input\"");
    }
    else
    {
        long long dp[32] = { [0] = 0,[1] = 1 };
        for (int i = 2; i <= 31; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        printf("%lld", dp[n]);
    }
    return 0;
}