// 找重複的數字
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
int qsort_cmp(const void* p1, const void* p2)
{
	int* a = (int*)p1;
	int* b = (int*)p2;
	return *a - *b;
}
int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	qsort(arr, 10, sizeof(int), qsort_cmp);
	int output[10], len = 0;
	int temp = arr[0];
	for (int i = 0; i < 9; i++)
	{
		if (temp == arr[i] && i != 0)
			continue;
		if (arr[i] == arr[i + 1])
		{
			output[len] = arr[i];
			temp = arr[i];
			len++;
		}
	}
	if (len == 0)
	{
		puts("0");
	}
	else
	{
		int sum = 0;
		for (int i = 0; i < len; i++)
			sum += output[i];
		printf("%d", sum);
	}
    return 0;
}