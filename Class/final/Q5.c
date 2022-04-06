// change letters to digits
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	scanf("%d", &n);
	for (int times = 0; times < n; times++)
	{
		char input[32] = { 0 };
		scanf("%s", input);
		int letters = 0, hyphens = 0;
		for (int i = 0; input[i]; i++)
		{
			if (input[i] == '-')
				hyphens++;
			else if (input[i] >= 'A' && input[i] <= 'Z')
			{
				letters++;

				if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C')
					input[i] = '2';
				else if (input[i] == 'D' || input[i] == 'E' || input[i] == 'F')
					input[i] = '3';
				else if (input[i] == 'G' || input[i] == 'H' || input[i] == 'I')
					input[i] = '4';
				else if (input[i] == 'J' || input[i] == 'K' || input[i] == 'L')
					input[i] = '5';
				else if (input[i] == 'M' || input[i] == 'N' || input[i] == 'O')
					input[i] = '6';
				else if (input[i] == 'P' || input[i] == 'Q' || input[i] == 'R' || input[i] == 'S')
					input[i] = '7';
				else if (input[i] == 'T' || input[i] == 'U' || input[i] == 'V')
					input[i] = '8';
				else if (input[i] == 'W' || input[i] == 'X' || input[i] == 'Y' || input[i] == 'Z')
					input[i] = '9';
			}
		}
		
		for (int i = 0; input[i]; i++)
			putchar(input[i]);
		printf(" %d %d\n", letters, hyphens);
	}
	return 0;
}
/*

2
1-HOME-SWEET-HOME
MY-MISERABLE-JOB

*/