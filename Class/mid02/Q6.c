// split and decode
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char* content;
	int size;
} string;
void PushBack(string* s, const char addend)
{
	char* temp = realloc(s->content, (s->size + 2) * sizeof(char));
	if (temp == NULL)
	{
		puts("memory allocation failed!\n");
		return;
	}
	s->content = temp;
	s->content[s->size] = addend;
	s->size++;
	s->content[s->size] = '\0';
}
void Initialize(string* s)
{
	s->content = calloc(1, sizeof(char));
	s->size = 0;
}
string ReadLine()
{
	char input;
	string s;
	Initialize(&s);
	input = getchar();
	while (input == '\n')
		return s;
	while (input != '\n')
	{
		PushBack(&s, input);
		input = getchar();
	}
	return s;
}
void PrintStringInfo(const string s)
{
	printf("Size: %d\nContent: ", s.size);
	for (int i = 0; s.content[i]; i++)
		putchar(s.content[i]);
	putchar('\n');
}
string* StringSplit(const string s, const char separate, int* element)
{
	int index = 0;
	string* result = malloc(sizeof(string) * (index + 1));
	Initialize(&result[index]);
	for (int i = 0; s.content[i]; i++)
	{
		if (s.content[i] == separate)
		{
			
			index++;
			result = realloc(result, sizeof(string) * (index + 1));
			Initialize(&result[index]);
		}
		else
			PushBack(&result[index], s.content[i]);
	}
	*element = index + 1;
	return result;
}
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