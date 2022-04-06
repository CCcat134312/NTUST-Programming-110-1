// 大數運算 (有小數點)
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>
int max(int a, int b) { return a > b ? a : b; }
// reverse a char array
void reverse(char* arr)
{
	int len = strlen(arr);
	char temp;
	for (int i = 0, j = len - 1; i <= j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
// right shift one digit and put character to left
void shift_one(char* a,char c)
{
	int len = strlen(a);
	for (int i = len; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = c;
}
// fill '0' to make length of two array be same
void zero(char* a,char *b)
{
	int len_a = strlen(a), len_b = strlen(b);
	int point_a = 0, point_b = 0;
	for (int i = 0; i < len_a; i++)
	{
		if (a[i] == '.' || point_a > 0)
			point_a++;
	}
	for (int i = 0; i < len_b; i++)
	{
		if (b[i] == '.' || point_b > 0)
			point_b++;
	}
	int max_len = max(len_a - point_a, len_b - point_b);
	if (max_len == len_a - point_a)
	{
		for (int times = 0; times < max_len - (len_b - point_b); times++)
		{
			shift_one(b,'0');
		}
		len_b += max_len - (len_b - point_b);
	}
	else
	{
		for (int times = 0; times < max_len - (len_a - point_a); times++)
		{
			shift_one(a,'0');
		}
		len_a += max_len - (len_a - point_a);
	}

	max_len = max(point_a, point_b);
	if (max_len == 0)
		return;
	else if (max_len == point_a)
	{
		if (point_b == 0)
		{
			b[len_b] = '.';
			b[len_b+1] = '0';
			len_b += 2;
			point_b = 2;
		}
		for (int i = 0; i < point_a - point_b; i++)
			b[len_b + i] = '0';
	}
	else
	{
		if (point_a == 0)
		{
			a[len_a] = '.';
			a[len_a + 1] = '0';
			len_a += 2;
			point_a = 2;
		}
		for (int i = 0; i < point_b - point_a; i++)
			a[len_a + i] = '0';
	}
}
// compare two number
int cmp(char* a, char* b)
{
	int len_a = strlen(a), len_b = strlen(b);
	if (len_a > len_b)
		return 1;
	else if (len_b > len_a)
		return -1;
	else
	{
		for (int i = 0; i < len_a; i++)
		{
			if (a[i] > b[i])
				return 1;
			else if (b[i] > a[i])
				return -1;
		}
		return 0;
	}
}
// swap all of element of two array
void swap(char* a, char* b)
{
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		a[i] ^= b[i];
		b[i] ^= a[i];
		a[i] ^= b[i];
	}
}
int main()
{
	int n;
	scanf("%d\n", &n);	// how many times will input
	for (int cases = 0; cases < n; cases++)
	{
		// 63 = digits(30) + decimal point(30) + carry(1) + point('.') + '\0' 
		char a[63] = { 0 }, b[63] = { 0 }, op;
		scanf("%[0-9.]%c%[0-9.]\n", a, &op, b);	// parse string by regex
		zero(a, b);	// fill '0'
		if (op == '+')
		{
			// reverse array to begin with LSB
			reverse(a);
			reverse(b);
			int len = strlen(a), temp = 0, carry = 0;
			for (int i = 0; i < len; i++)
			{
				if (a[i] == '.')
					continue;
				temp = (a[i] - '0') + (b[i] - '0') + carry;
				carry = temp / 10;
				temp %= 10;
				a[i] = temp + '0';
			}
			reverse(a);
			// remove unnecessary 0
			for (int i = len - 1; i > 0; i--)
			{
				if (a[i] != '0')
				{
					a[i + 1] = '\0';
					break;
				}
			}
			len = strlen(a);
			if (a[len - 1] == '.')	// remove point
				a[len - 1] = '\0';

			if (carry != 0)	// push '1' to right
				shift_one(a, '1');
		}
		else if (op == '-')
		{
			int result_cmp = cmp(a, b);	// result of compare
			if (result_cmp == 0)
			{
				a[0] = '0';
				a[1] = '\0';
			}
			else
			{
				// make sure the first number is bigger
				if (result_cmp == -1)	
				{
					swap(a, b);
					putchar('-');	
				}
				// all digit borrow first
				int len = strlen(a);
				for (int i = 0; i < len - 1; i++)
				{
					if (a[i] - '0' > 0 && a[i] != '.')
					{
						a[i]--;
						if (a[i + 1] == '.')
							a[i + 2] += 10;
						else
							a[i + 1] += 10;
					}
				}
				// reverse array to begin with LSB
				reverse(a);
				reverse(b);
				// do subtration
				for (int i = 0; i < len; i++)
				{
					if (a[i] == '.')
						continue;
					a[i] = a[i] - b[i] + '0';
				}
				// check every number less than 10
				// if greater than 9, carry to next digit
				for (int i = 0; i < len - 1; i++)
				{
					if (a[i] != '.' && a[i] - '0' > 9)
					{
						a[i] -= 10;
						if (a[i + 1] == '.')
							a[i + 2] ++;
						else
							a[i + 1] ++;
					}
				}
				//	remove unnecessary 0
				for (int i = len - 1; i > 0; i--)
				{
					if (a[i] != '0')
					{
						a[i + 1] = '\0';
						break;
					}
				}
				reverse(a);
				//	.99 -> 0.99
				if (a[0] == '.')
					shift_one(a, '0');
				//	remove unnecessary 0
				len = strlen(a);
				for (int i = len - 1; i > 0; i--)
				{
					if (a[i - 1] != '0' && a[i] == '0')
					{
						a[i] = '\0';
						break;
					}
				}
				len = strlen(a);
				//	100. -> 100
				if (a[len - 1] == '.')
					a[len - 1] = '\0';
			}
		}
		// cover original array to save memory
		// print the result of computation
		printf("%s\n", a);
	}
	return 0;
}
/*
5
12345678991019231124+1234567890000000
12345678991019231124-1234567890000000
1-123456789123456789
123465789.123456789+987654321.987654321
1000000000-0.1
*/

/*
12346913558909231124
2344444423129231124
-123456789123456788
1111120111.11111111
999999999.9
*/