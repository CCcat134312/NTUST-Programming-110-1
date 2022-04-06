// 判斷是否為11之倍數
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

int main()
{
	char input[1001];
	scanf("%s", input);
	int sum = 0,len=strlen(input);
	for (int i = 0; i < len; i++)
	{
		if (i % 2 == 0)
			sum += (input[i] - '0');
		else
			sum -= (input[i] - '0');
		printf("%c", input[i]);
	}
	if (sum % 11 == 0)
		puts(" is a multiple of 11.");
	else
		puts(" is not a multiple of 11.");
    return 0;
}