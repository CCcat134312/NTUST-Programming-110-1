// 2*2矩陣乘法
#include <stdio.h>

int main()
{
	int arr1[4], arr2[4];
	scanf_s("%d %d %d %d", &arr1[0], &arr1[1], &arr1[2], &arr1[3]);
	scanf_s("%d %d %d %d", &arr2[0], &arr2[1], &arr2[2], &arr2[3]);
	printf("%d %d\n%d %d", arr1[0] * arr2[0] + arr1[1] * arr2[2], arr1[0] * arr2[1] + arr1[1] * arr2[3], arr1[2] * arr2[0] + arr1[3] * arr2[2], arr1[2] * arr2[1] + arr1[3] * arr2[3]);
	
	return 0;
}