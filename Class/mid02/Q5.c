// ¤¤§ÇÂà«á§Ç
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
int priority(char op)
{
	switch (op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}
int main()
{
	char input[51] = { '\0' }, output[51] = { '\0' }, stack[51] = { '\0' };
	scanf("%51s", input);
	int output_cnt = 0, stack_cnt = 0;
	for (int i = 0; input[i]; i++)
	{
		switch (input[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			while (priority(stack[stack_cnt]) >= priority(input[i]))
			{
				output[output_cnt] = stack[stack_cnt];
				output_cnt++;
				stack_cnt--;
			}
			stack_cnt++;
			stack[stack_cnt] = input[i];
			break;
		case '(':
			stack_cnt++;
			stack[stack_cnt] = input[i];
			break;
		case ')':
			while (stack[stack_cnt] != '(')
			{
				output[output_cnt] = stack[stack_cnt];
				output_cnt++;
				stack_cnt--;
			}
			stack_cnt--;
			break;
		default:
			output[output_cnt] = input[i];
			output_cnt++;
			break;
		}
	}
	while (stack_cnt > 0)
	{
		output[output_cnt] = stack[stack_cnt];
		output_cnt++;
		stack_cnt--;
	}
	printf("%s", output);
	return 0;
}
// ((1+2)*3)/4+5