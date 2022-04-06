#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find_point(char *arr, int len)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == '.' || result > 0)
            result++;
    }
    return result;
}
void push_front(char *arr, char fill, int len)
{
    for (int i = len; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = fill;
}
void pop_front(char *a, int len)
{
    for (int i = 0; i < len; i++)
        a[i] = a[i + 1];
}
void zero(char *a, char *b)
{
    int len_a = strlen(a), len_b = strlen(b);
    int point_a = find_point(a, len_a), point_b = find_point(b, len_b);

    // ======================== front '0' ===============================
    int fill_zero = abs((len_a - point_a) - (len_b - point_b));
    if (len_a - point_a > len_b - point_b) // fill b
    {
        for (int i = 0; i < fill_zero; i++)
        {
            push_front(b, '0', len_b);
            len_b++;
        }
    }
    else if (len_b - point_b > len_a - point_a) // fill a
    {
        for (int i = 0; i < fill_zero; i++)
        {
            push_front(a, '0', len_a);
            len_a++;
        }
    }
    // ======================== back '0' ===============================
    if (point_a == 0 && point_b == 0)
        return;
    if (point_a == 0) // fix no decimal point
    {
        a[len_a] = '.';
        a[len_a + 1] = '0';
        len_a += 2;
        point_a = 2;
    }
    if (point_b == 0)
    {
        b[len_b] = '.';
        b[len_b + 1] = '0';
        len_b += 2;
        point_b = 2;
    }
    fill_zero = abs(point_a - point_b);

    if (point_a > point_b) // fill b
    {
        for (int i = 0; i < fill_zero; i++)
            b[len_b + i] = '0';
    }
    else if (point_b > point_a) // fill a
    {
        for (int i = 0; i < fill_zero; i++)
            a[len_a + i] = '0';
    }
}
int cmp(char *a, char *b, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return -1;
    }
    return 0;
}
void swap(char *a, char *b, int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] ^= b[i];
        b[i] ^= a[i];
        a[i] ^= b[i];
    }
}
void remove_back_zero(char *a, int len)
{
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        if (a[i - 1] == '.' && a[i] == '0')
        {
            a[i - 1] = '\0';
            break;
        }
        else if (a[i - 1] != '0' && a[i] == '0')
        {
            a[i] = '\0';
            break;
        }
        else if (a[i] != '0')
            break;
    }
}
void remove_front_zero(char *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '0' && a[i + 1] != '.')
        {
            pop_front(a, len);
            len--;
            i--;
        }
        else
            break;
    }
}
int main()
{
    char a[63] = {0}, b[63] = {0}, op;
    scanf("%[0-9.]%c%[0-9.]", a, &op, b);
    zero(a, b); // fill zero to make point to point (?
    int len = strlen(a);
    if (op == '+')
    {
        int carry = 0, temp = 0;
        for (int i = len - 1; i >= 0; i--) // addition
        {
            if (a[i] == '.')
                continue;
            temp = (a[i] - '0') + (b[i] - '0') + carry;
            carry = temp / 10;
            temp %= 10;
            a[i] = temp + '0';
        }
        if (carry > 0)
            push_front(a, '1', strlen(a));
        remove_back_zero(a, len);
    }
    else if (op == '-')
    {
        int cmp_result = cmp(a, b, len);
        if (cmp_result == 0)
        {
            a[0] = 0;
            a[1] = '\0';
        }
        else
        {
            if (cmp_result < 0) // b > a
            {
                swap(a, b, len);
                putchar('-');
            }
            int carry = 0;
            for (int i = 0; i < len - 1; i++) // borrow
            {
                if (a[i] != '.' && a[i] - '0' > 0)
                {
                    a[i]--;
                    if (a[i + 1] == '.')
                        a[i + 2] += 10;
                    else
                        a[i + 1] += 10;
                }
            }
            for (int i = len - 1; i >= 0; i--) // subtraction
            {
                if (a[i] == '.')
                    continue;
                a[i] = (a[i] - b[i]) + carry;
                carry = a[i] / 10;
                a[i] = a[i] % 10 + '0';
            }

            remove_back_zero(a, len);
            len = strlen(a);
            remove_front_zero(a, len);
        }
    }
    printf("%s", a);
    return 0;
}