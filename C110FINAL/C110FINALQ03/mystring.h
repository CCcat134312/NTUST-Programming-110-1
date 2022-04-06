#pragma once
#include <stdio.h>
#include <stdlib.h>
#define Initialize(...) __Initialize((init_args){__VA_ARGS__})
#define StringSlice(s, ...) __StringSlice(s, (slice_args){__VA_ARGS__})
#define StringCat(s, ...) __StringCat(s, (cat_args){__VA_ARGS__})
typedef struct
{
	const char* arr;
} init_args;
typedef struct
{
	int start;
	int end;
} slice_args;
typedef struct
{
	char* content;
	int size;
} string;
typedef struct
{
	const char* charArr;
	string str;
} cat_args;
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
string __Initialize(init_args args)
{
	string s = { .content = calloc(1, sizeof(char)), .size = 0 };
	if (args.arr)
		for (int i = 0; args.arr[i]; i++)
			PushBack(&s, args.arr[i]);
	return s;
}
string ReadLine()
{
	char input;
	string s = Initialize(NULL);

	for (input = getchar(); input == '\n'; input = getchar())
		;
	for (; input != '\n'; input = getchar())
		PushBack(&s, input);
	return s;
}
string Read()
{
	char input;
	string s = Initialize(NULL);
	for (input = getchar(); input == '\n' || input == ' '; input = getchar())
		;
	for (; input != ' ' && input != '\n'; input = getchar())
		PushBack(&s, input);
	return s;
}
void PrintStringInfo(const string s)
{
	printf("Size: %d\nContent: ", s.size);
	for (int i = 0; s.content[i]; i++)
		putchar(s.content[i]);
	putchar('\n');
}
void PrintString(const string s)
{
	for (int i = 0; s.content[i]; i++)
		putchar(s.content[i]);
	putchar('\n');
}
string* StringSplit(const string s, const char separate, int* element)
{
	int index = 0;
	string* result = malloc(sizeof(string) * (index + 1));
	result[index] = Initialize(NULL);
	int start = 0;
	for (; s.content[start]; start++)
		if (s.content[start] != separate)
			break;
	for (int i = start; s.content[i]; i++)
	{
		if (s.content[i] == separate)
		{
			if (s.content[i + 1] == separate || s.content[i + 1] == '\0')
				continue;
			index++;
			result = realloc(result, sizeof(string) * (index + 1));
			result[index] = Initialize(NULL);
		}
		else
			PushBack(&result[index], s.content[i]);
	}
	*element = index + 1;
	return result;
}
void __StringCat(string* s, cat_args args)
{
	if (args.charArr)
	{
		for (int i = 0; args.charArr[i]; i++)
			PushBack(s, args.charArr[i]);
	}
	if (args.str.content)
	{
		for (int i = 0; args.str.content[i]; i++)
			PushBack(s, args.str.content[i]);
	}
}
int StringCompare(const string s1, const string s2)
{
	if (s1.size != s2.size)
		return s1.size > s2.size ? 1 : -1;
	for (int i = 0; s1.content[i]; i++)
		if (s1.content[i] != s2.content[i])
			return s1.content[i] > s2.content[i] ? 1 : -1;
	return 0;
}
int StringNCompare(const string s1, const string s2, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!s1.content[i])
			return 1;
		if (!s2.content[i])
			return -1;
		if (s1.content[i] != s2.content[i])
			return s1.content[i] > s2.content[i] ? 1 : -1;
	}
	return 0;
}
string __StringSlice(const string s, slice_args args)
{
	int start = args.start ? args.start : 0;
	int end = args.end ? args.end : s.size;
	if (start > s.size - 1)
		start = s.size - 1;
	if (end > s.size)
		end = s.size;

	string result = Initialize(NULL);
	for (int i = start; i < end; i++)
		PushBack(&result, s.content[i]);
	return result;
}
string StringReverse(const string s)
{
	string result = Initialize(s.content);
	char temp;
	for (int start = 0, end = s.size - 1; start <= end; start++, end--)
	{
		temp = result.content[start];
		result.content[start] = result.content[end];
		result.content[end] = temp;
	}
	return result;
}
void StringFree(string* s)
{
	free(s->content);
	s->size = 0;
}
string StringReplace(const string origin, const string replacement, const string temp)
{
	string result = Initialize(NULL);
	for (int i = 0; i < origin.size; i++)
	{
		if (!StringNCompare(StringSlice(origin, i, i + replacement.size), replacement, replacement.size))
		{
			StringCat(&result, .str = temp.content);
			i += replacement.size - 1;
		}
		else
		{
			PushBack(&result, origin.content[i]);
		}
	}
	return result;
}