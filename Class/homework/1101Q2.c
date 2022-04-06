// 給一數列，求排序後，原本該數的 index
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
typedef struct pair
{
    int index;
    int data;
} pair;

int cmp(const void* a, const void* b)
{
    pair* p1 = (pair*)a;
    pair* p2 = (pair*)b;
    return (p1->data - p2->data);
}

int main()
{
    int n;
    scanf_s("%d", &n);
    pair *pairs = (pair *)malloc(sizeof(pair) * n);
    for (int i = 0; i < n; i++)
    {
        pairs[i].index = i;
        scanf_s("%d", &pairs[i].data);
    }
    qsort(pairs, n, sizeof(pair), cmp);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", pairs[i].index);
    }
    printf("%d", pairs[n - 1].index);
    free(pairs);
    return 0;
}