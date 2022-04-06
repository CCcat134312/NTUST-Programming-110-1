// ugly number
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
int main()
{
	int input;
	scanf("%d", &input);
	while (input % 2 == 0)
		input /= 2;
	while (input % 3 == 0)
		input /= 3;
	while (input % 5 == 0)
		input /= 5;
	if (input == 1)
		puts("It is an ugly number.");
	else
		puts("It is not an ugly number.");
    return 0;
}