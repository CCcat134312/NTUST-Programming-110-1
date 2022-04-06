// 羅馬數字
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
int table[95] = { ['I'] = 1, ['V'] = 5, ['X'] = 10, ['L'] = 50,
                  ['C'] = 100, ['D'] = 500, ['M'] = 1000 };
int main()
{
    char input[11];
    scanf("%11s", input);
    int len = strlen(input), result = table[input[len - 1]];
    for (int i = len - 2; i >= 0; i--)
    {
        if (table[input[i]] < table[input[i + 1]])
            result -= table[input[i]];
        else
            result += table[input[i]];
    }
    printf("%d", result);
    return 0;
}
