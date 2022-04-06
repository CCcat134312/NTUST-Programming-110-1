#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	char input[101];
	scanf("%[^\n]", input);
	int n;
	scanf("%d", &n);
	n %= 26;
	for (int i = 0; input[i] != '\0'; i++)
	{
		//printf("%c", input[i]);
		if (input[i] >= 'a' && input[i] <= 'z')
		{
			input[i] = (((input[i] - 'a') + n) % 26) + 'a';
		}
		else if (input[i] >= 'A' && input[i] <= 'Z')
		{
			input[i] = (((input[i] - 'A') + n) % 26) + 'A';
		}
	}
	printf("%s", input);
	return 0;
}