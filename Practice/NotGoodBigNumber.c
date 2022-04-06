#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 60
struct number
{
    char nums[SIZE + 2];
    int sign;
};
char read(struct number *num)
{
    char input = getchar();
    if (input == '-')
    {
        num->sign = 1;
        input = getchar();
    }
    int cnt = 0;
    while ((input >= '0' && input <= '9') || input == '.')
    {
        num->nums[cnt++] = input;
        input = getchar();
    }
    return input;
}
void printNumberInfo(struct number num)
{
    if (num.sign == 1)
        putchar('-');
    printf("%s\n", num.nums);
}
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
void add(struct number *a, struct number *b)
{
    int len = strlen(a->nums);
    int carry = 0, temp = 0;
    for (int i = len - 1; i >= 0; i--) // addition
    {
        if (a->nums[i] == '.')
            continue;
        temp = (a->nums[i] - '0') + (b->nums[i] - '0') + carry;
        carry = temp / 10;
        temp %= 10;
        a->nums[i] = temp + '0';
    }
    if (carry > 0)
        push_front(a->nums, '1', strlen(a->nums));
    remove_back_zero(a->nums, len);
}
void sub(struct number *a, struct number *b)
{
    int len = strlen(a->nums);
    int cmp_result = cmp(a->nums, b->nums, len);
    if (cmp_result == 0)
    {
        a->nums[0] = 0;
        a->nums[1] = '\0';
    }
    else
    {
        if (cmp_result < 0) // b > a
        {
            swap(a->nums, b->nums, len);
            putchar('-');
        }
        int carry = 0;
        for (int i = 0; i < len - 1; i++) // borrow
        {
            if (a->nums[i] != '.' && a->nums[i] - '0' > 0)
            {
                a->nums[i]--;
                if (a->nums[i + 1] == '.')
                    a->nums[i + 2] += 10;
                else
                    a->nums[i + 1] += 10;
            }
        }
        for (int i = len - 1; i >= 0; i--) // subtraction
        {
            if (a->nums[i] == '.')
                continue;
            a->nums[i] = (a->nums[i] - b->nums[i]) + carry;
            carry = a->nums[i] / 10;
            a->nums[i] = a->nums[i] % 10 + '0';
        }

        remove_back_zero(a->nums, len);
        len = strlen(a->nums);
        remove_front_zero(a->nums, len);
    }
}
void mul(struct number *a, struct number *b)
{
    int len = strlen(a->nums);
    if (len * 2 + 1 > SIZE)
    {
        puts("overflow\n");
        return;
    }
    int temp[2 * SIZE + 1] = {0};
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = len - 1; j >= 0; j--)
        {
            // printf("%c %c\n", a->nums[j], b->nums[i]);
            if (a->nums[j] == '.' || b->nums[i] == '.')
                continue;
            temp[i + j + 1] += (a->nums[j] - '0') * (b->nums[i] - '0');
        }
    }
    memset(a->nums, 0, SIZE + 2);
    for (int i = len * 2, index = SIZE; i >= 0; i--, index--)
    {
        a->nums[index] = (temp[i] % 10) + '0';
        temp[i - 1] += (temp[i] / 10);
    }
    for (int i = 0; i < SIZE+2; i++)
    {
        if (a->nums[i] == 0 || a->nums[i] == '0')
        {
            pop_front(a->nums, SIZE+2);
            i--;
        }
        else
            return;
    }
    remove_back_zero(a->nums,SIZE+2);
}
int main()
{
    char op;
    struct number a = {.nums = {0}, .sign = 0}, b = {.nums = {0}, .sign = 0};
    op = read(&a);
    read(&b);
    zero(a.nums, b.nums);
    if (op == '+')
    {
        if (a.sign == 0 && b.sign == 0)
            add(&a, &b);
        else if (a.sign == 0 && b.sign == 1)
            sub(&a, &b);
        else if (a.sign == 1 && b.sign == 0)
        {
            swap(a.nums, b.nums, strlen(a.nums));
            sub(&a, &b);
        }
        else
        {
            putchar('-');
            add(&a, &b);
        }
    }
    else if (op == '-')
    {
        if (a.sign == 0 && b.sign == 0)
            sub(&a, &b);
        else if (a.sign == 0 && b.sign == 1)
            add(&a, &b);
        else if (a.sign == 1 && b.sign == 0)
        {
            putchar('-');
            add(&a, &b);
        }
        else
        {
            swap(a.nums, b.nums, strlen(a.nums));
            sub(&a, &b);
        }
    }
    else if (op == '*')
    {
        mul(&a, &b);
    }
    printf("%s", a.nums);
    return 0;
}
/*

*/