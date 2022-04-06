// 四則運算
#include <stdio.h>

int main()
{
    float a, b;
    scanf_s("%f %f", &a, &b);
    printf("%.2f + %.2f = %.2f\n", a, b, a + b);
    printf("%.2f - %.2f = %.2f\n", a, b, a - b);
    printf("%.2f * %.2f = %.2f\n", a, b, a * b);
    printf("%.2f / %.2f = %.2f\n", a, b, a / b);

    return 0;
}