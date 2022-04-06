// String Replace
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
void cpy(char* ori, char *res,int start, int len)
{
	for (int i = start, j = 0; i < len; j++, i++)
		res[j] = ori[i];
}
int main()
{
	char n1[51] = { 0 }, n2[51] = { 0 }, n3[51] = { 0 }, output[101] = { 0 };
	gets(n1);
	gets(n2);
	gets(n3);
	int len1 = strlen(n1), len2 = strlen(n2), len3 = strlen(n3);
	int output_index = 0;
	for (int i = 0; i < len1; i++)
	{
		if (strncmp(n1 + i, n2, len2) == 0)
		{
			for (int j = 0; j < len3; j++)
			{
				output[output_index] = n3[j];
				output_index++;
			}
			i += len2 - 1;
		}
		else
		{
			output[output_index] = n1[i];
			output_index++;
		}
	}
	puts(output);
	return 0;
}