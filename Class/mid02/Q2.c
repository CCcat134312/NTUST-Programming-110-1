// point sort
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>
struct point
{
	float x;
	float y;
};
int cmp(const void* p1, const void* p2)
{
	struct point* a = (struct point*)p1;
	struct point* b = (struct point*)p2;
	if (a->x != b->x)
		return a->x - b->x;
	return a->y - b->y;
}
int main()
{
	int n;
	scanf("%d", &n);
	struct point arr[11] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%f %f", &arr[i].x, &arr[i].y);
	}
	qsort(arr, n, sizeof(struct point), cmp);
	for (int i = 0; i < n - 1; i++)
		printf("%.2f %.2f\n", arr[i].x, arr[i].y);
	printf("%.2f %.2f", arr[n-1].x, arr[n-1].y);
    return 0;
}