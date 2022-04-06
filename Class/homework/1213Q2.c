// 字串分析 (A1B2C3 -> ABBCCC)
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
    int n;
    char trash;
    scanf("%d%c", &n, &trash);
    for (int i = 1; i <= n; i++)
    {
        char input[500] = { '\0' };
        scanf("%500s", input);
        char output = input[0];
        int times = 0;
        printf("Case %d: ", i);
        for (int i = 1; input[i] != '\0'; i++)
        {
            if (input[i] >= 'A' && input[i] <= 'Z')
            {
                for (int i = 0; i < times; i++)
                    printf("%c",output);
                output = input[i];
                times = 0;
            }
            else
            {
                if (times == 0)
                    times = input[i] - '0';
                else
                {
                    times *= 10;
                    times += (input[i] - '0');
                }
            }
        }
        for (int i = 0; i < times; i++)
            putchar(output);
        putchar('\n');
    }
    return 0;
}