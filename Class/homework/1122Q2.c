// 字串減法 (去除指定字串)
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>
int main()
{
    char n1[201] = { 0 }, n2[201] = { 0 };
    gets(n1);
    gets(n2);
    int len1 = strlen(n1), len2 = strlen(n2);
    if (len1 < len2)
    {
        puts("Invalid pattern");
    }
    else
    {
        int sta = 0;
        for (int i = 0; i < len1; i++)
        {
            if (strncmp(n1 + i, n2, len2) == 0)
            {
                for (int j = i, k = i + len2; j < len1; j++, k++)
                    n1[j] = n1[k];
                n1[len1 - len2] = '\0';
                sta = 1;
            }
        }
        if (sta == 0)
            puts("Pattern not found");
        else
            puts(n1);

    }
    return 0;
}
