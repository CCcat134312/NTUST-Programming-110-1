#include <stdio.h>
#include <stdlib.h>
struct number
{
    int data;
    int status;
};
struct number arr[5][5] = {[2][2].data = 0, [2][2].status = 1};
int judge()
{
    int flag;
    for (int i = 0; i < 5; i++)
    {
        flag = 1;
        for (int j = 0; j < 5; j++)
            if (arr[i][j].status == 0)
                flag = 0;
        if (flag == 1)
            return flag;
    }
    for (int i = 0; i < 5; i++)
    {
        flag = 1;
        for (int j = 0; j < 5; j++)
            if (arr[j][i].status == 0)
                flag = 0;
        if (flag == 1)
            return flag;
    }
    flag = 1;
    for (int i = 0; i < 5; i++)
        if (arr[i][i].status == 0)
            flag = 0;
    if (flag == 1)
        return flag;
    flag = 1;
    for (int i = 0; i < 5; i++)
        if (arr[i][4 - i].status == 0)
            flag = 0;
    return flag;
}
void fill(int nums)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j].data == nums)
            {
                arr[i][j].status = 1;
                return;
            }
        }
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int times = 0; times < n; times++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i != 2 || j != 2)
                {
                    scanf("%d", &arr[i][j].data);
                    arr[i][j].status = 0;
                }
            }
        }
        int temp, flag = 0;
        for (int i = 0; i < 75; i++)
        {
            scanf("%d", &temp);
            if (flag > 0)
                continue;

            fill(temp);

            if (judge(temp) == 1)
                flag = i + 1;
        }
        printf("BINGO after %d numbers announced\n", flag);
    }
    return 0;
}
/*

10 17 39 49 64
12 21 36 55 62
14 25    52 70
7 19 32 56 68
5 24 34 54 71
*/