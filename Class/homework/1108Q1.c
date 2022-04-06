// 盒內塔
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int step = 0;
char* output[3];
void hanoi(int target, int disk, char A, char B, char C)
{
    if (disk == 1)
    {
        step++;
        if (step == target)
        {
            output[0] = A;
            output[1] = B;
            output[2] = disk;
        }
        return;
    }
    hanoi(target, disk - 1, A, C, B);
    step++;
    if (step == target)
    {
        output[0] = A;
        output[1] = B;
        output[2] = disk;
    }
    hanoi(target, disk - 1, C, B, A);
}

int main()
{
    int disk, target;
    scanf_s("%d", &disk);
    scanf_s("%d", &target);
    if (disk < 1)
    {
        puts("Invalid disk number");
    }
    else if (target > ((1 << disk) - 1))
    {
        puts("Step out of range");
    }
    else
    {
        hanoi(target, disk, 'A', 'C', 'B');
        printf("Disk %d moved from %c to %c", output[2], output[0], output[1]);
    }
    return 0;
}