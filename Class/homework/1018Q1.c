// 給兩數字跟運算元 做四則運算
#include <stdio.h>

int main()
{
    float a, b, result;
    char op;
    scanf_s("%f %c %f", &a, &op, 1, &b);
    if (op == '+')
    {
        result = a + b;
        printf("%.2f + %.2f = %.2f", a, b, result);
    }
    else if (op == '-')
    {
        result = a - b;
        printf("%.2f - %.2f = %.2f", a, b, result);
    }
    else if (op == '*')
    {
        result = a * b;
        printf("%.2f * %.2f = %.2f", a, b, result);
    }
    else if (op == '/')
    {
        if (b == 0)
        {
            printf("Division by zero");
        }
        else
        {
            result = a / b;
            printf("%.2f / %.2f = %.2f", a, b, result);
        }
    }
    return 0;
}