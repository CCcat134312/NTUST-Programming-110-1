// 踩地雷
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>

char map[101][101];
int n, m;
void detect(int x, int y)
{
	int tempx, tempy;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			tempx = x + i;
			tempy = y + j;
			if (tempx >= n || tempy >= m || tempx < 0 || tempy < 0 || map[tempx][tempy] == '*')
				continue;

			if (map[tempx][tempy] == '.')
				map[tempx][tempy] = '0';
			map[tempx][tempy]++;
		}
	}
}
int main()
{
	for (int time=1;;time++)
	{
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%s", &map[i]);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == '.')
					map[i][j] = '0';
				if (map[i][j] == '*')
					detect(i, j);
			}
		}
		printf("Field #%d:\n", time);
		for (int i = 0; i < n; i++, putchar('\n'))
			for (int j = 0; j < m; j++)
				printf("%c", map[i][j]);
		putchar('\n');
	}
	return 0;
}
/*
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
*/