#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b)
{
	return strcmp(*(char**)a, *(char**)b);
}
int main()
{
	int n;
	scanf("%d", &n);
	char** countries;
	countries = (char**)malloc(sizeof(char) * n);
	for (int i = 0; i < n; i++)
	{
		countries[i] = (char*)calloc(sizeof(char), 75);
		scanf("%s", countries[i]);
		for (char name = 'w'; name != '\n';)
			name = getchar();
	}
	qsort(countries, n, sizeof(char*), cmp);

	printf("%s ", countries[0]);
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (strcmp(countries[i], countries[i - 1]) != 0)
		{
			printf("%d\n", cnt);
			cnt = 1;
			printf("%s ", countries[i]);
		}
		cnt++;
	}
	printf("%d", cnt - 1);
	for (int i = 0; i < n; i++)
		free(countries[i]);
	free(countries);
	return 0;
}
/*

3
Spain Donna Elvira
England Jane Doe
Spain Donna Anna

*/