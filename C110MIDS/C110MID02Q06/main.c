#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include "myString.h"
int main(void)
{
	int time;
	scanf("%d\n", &time);
	for (int times = 1; times <= time; times++)
	{
		printf("Case #%d:\n", times);
		for (int j = 0; j < 110; j++)
		{
			string s = ReadLine();
			if (s.size == 0)
				break;
			int n;
			string* arr = StringSplit(s, ' ', &n);
			for (int i = 0, cnt = 0; i < n; i++)
			{
				if (arr[i].size == 0)
					continue;
				if (arr[i].size - 1 >= cnt)
				{
					putchar(arr[i].content[cnt]);
					cnt++;
				}
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}